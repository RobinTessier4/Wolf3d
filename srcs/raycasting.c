/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:26:18 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:03:39 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	 virtual_init(t_virtual *v)
{
	v->dist.x = fabs(v->start.x - v->end.x);
	v->dist.y = fabs(v->start.y - v->end.y);
	v->sx = v->start.x < v->end.x ? 1 : -1;
	v->sy = v->start.y < v->end.y ? 1 : -1;
	v->sx /= WIDTH;
	v->sy /= WIDTH;
	v->err = (v->dist.x > v->dist.y ? v->dist.x : -v->dist.y) / 2;
}

double		calc_size_ray(t_env *e, t_virtual *v)
{
	float	e2;
	double	dist;
	//	t_pos_d	current_bloc;
	double startx;
	double starty;

	startx = v->start.x;
	starty = v->start.y;
	//	current_bloc.x = v->start.x / BLOC_SIZE;
	//	current_bloc.y = v->start.y / BLOC_SIZE;
	while (v->start.x > 0 && v->start.y > 0 && e->file[(int)v->start.y][(int)v->start.x] == 0)
	{
		//		current_bloc.x = v->start.x / BLOC_SIZE;
		//		current_bloc.y = v->start.y / BLOC_SIZE;
		e2 = v->err;
		if (e2 > -v->dist.x)
		{
			v->err -= v->dist.y;
			v->start.x += v->sx;
		}
		if (e2 < v->dist.y)
		{
			v->err += v->dist.x;
			v->start.y += v->sy;
		}
	}
	v->dist.x = fabs(v->start.x - startx);
	v->dist.y = fabs(v->start.y - starty);

	//	printf("dist x = %f\n", v->dist.x);
	//	printf("dist y = %f\n", v->dist.y);
	dist = sqrt(v->dist.x * v->dist.x + v->dist.y * v->dist.y);
	//	printf("dist x = %f\n", v->dist.x);
	//	printf("dist y = %f\n", v->dist.y);
//	printf("start x = %f\n", v->start.x);
//	printf("start y = %f\n", v->start.y);
//	v->start.x = startx;
//	v->start.y = starty;
	return (dist);
}

static void		draw_wall(t_env *e, double dist, int x, t_pos_d rayend)
{
	//	t_pos		start;
	//	t_pos		end;
	int			size_wall;
	double		ecart;
	double		angle;
	double width;
	t_vector *wall;



	if (!(wall = ft_memalloc(sizeof(t_vector))))
		return ;
	size_wall = BLOC_HEIGHT / dist;
	width = WIDTH;
	if (size_wall == 0)
		return ;
//	if (x != WIDTH / 2)
	{
		ecart = 2 * x / width - 1;
		angle = (146 * ecart) / (WIDTH / 2);
		size_wall /= cos(angle);
	}
	wall->start.x = x;
	wall->start.y = (HEIGHT / 2) - size_wall;
	wall->end.x = x;
	wall->end.y = (HEIGHT / 2) + size_wall;
	vector_init(e, wall);
	//	drawline(e->mlx, start, end);
//	test(e);
draw_text(e, wall, rayend);
}

void			raycasting(t_env *e)
{
	int			x;
//	float		err;
	double		size;
	t_virtual	vector;
	t_virtual	rayon;
	double startx;
	double starty;
	double width;

	width = WIDTH;
	text_init(e);
	// vector ici est une copie du vector "plane" cf ray_init()
	vector.start.x = (e->player.x + e->dir_p.x - e->plane_p.x) * BLOC_SIZE;
	vector.start.y = (e->player.y + e->dir_p.y - e->plane_p.y) * BLOC_SIZE;
	vector.end.x = (e->player.x + e->dir_p.x + e->plane_p.x) * BLOC_SIZE;
	vector.end.y = (e->player.y + e->dir_p.y + e->plane_p.y) * BLOC_SIZE;
	virtual_init(&vector);
	e->mlx->img->color = 0x5B507A;

	startx = vector.start.x;
	starty = vector.start.y;
	x = 0;
	while (x < WIDTH)
	{
		rayon.start.x = e->player.x * BLOC_SIZE;
		rayon.start.y = e->player.y * BLOC_SIZE;

		rayon.end.x = startx + ((vector.end.x - startx) * (x / width));
		rayon.end.y = starty + ((vector.end.y - starty) * (x / width));
		virtual_init(&rayon);
		size = calc_size_ray(e, &rayon);
		// apres calc_size_ray, lray.start s'est deplace de vector.start vers le point de collision avec le mur
		// calc_size_ray retourne la distance entre le mur (lray.start) et le plan de projection (lray.end)
	//	printf("raystart x = %f\n", rayon.start.x);
	//	printf("raystart y = %f\n", rayon.start.y);
	//	printf("dist = %f\n", size);
	//	printf("rayend x = %f\n", rayon.end.x);
	//	printf("rayend y = %f\n", rayon.end.y);
		draw_wall(e, size, x, rayon.start);
	/*	err = vector.err;
		if (err > -vector.dist.x)
		{
			vector.err -= vector.dist.y;
			vector.start.x += vector.sx;
		}
		if (err < vector.dist.y)
		{
			vector.err += vector.dist.x;
			vector.start.y += vector.sy;
		}*/
		x++;
	}
}
