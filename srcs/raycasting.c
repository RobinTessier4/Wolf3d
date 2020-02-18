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
	t_pos_d	current_bloc;

	current_bloc.x = v->start.x / BLOC_SIZE;
	current_bloc.y = v->start.y / BLOC_SIZE;
	while (v->start.x > 0 && v->start.y > 0 && e->file[(int)current_bloc.y][(int)current_bloc.x] == 0)
	{
		current_bloc.x = v->start.x / BLOC_SIZE;
		current_bloc.y = v->start.y / BLOC_SIZE;
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
	v->dist.x = fabs(v->start.x - v->end.x);
	v->dist.y = fabs(v->start.y - v->end.y);
	dist = sqrt(v->dist.x * v->dist.x + v->dist.y * v->dist.y);
	return (dist);
}

static void		draw_wall(t_env *e, double dist, int x)
{
	t_pos		start;
	t_pos		end;
	int			size_wall;
	int			ecart;
	double		angle;

	size_wall = BLOC_HEIGHT / dist;
	if (size_wall == 0)
		return ;
	if (x != WIDTH / 2)
	{
		ecart = abs((WIDTH / 2) - x) - 1;
		// si ecart = 250, angle = 0.66/2 = 0.33
		//angle = (0.445 * ecart) / (WIDTH / 2); // why 0.445??
		angle = (0.575959 * ecart) / (WIDTH / 2);
		size_wall /= cos(angle);
		printf("x: %d ; size_wall: %d ; ecart : %d ; angle : %f\n", x, size_wall, ecart, angle);
	}
	start.x = x;
	start.y = (HEIGHT / 2) - size_wall;
	end.x = x;
	end.y = (HEIGHT / 2) + size_wall;
	drawline(e->mlx, start, end);
}

void			raycasting(t_env *e)
{
	int			x;
	float		err;
	double		size;
	t_virtual	vector;
	t_virtual	rayon;
	
	// vector ici est une copie du vector "plane" cf ray_init()
	vector.start.x = (e->player.x + e->dir_p.x - e->plane_p.x) * BLOC_SIZE;
	vector.start.y = (e->player.y + e->dir_p.y - e->plane_p.y) * BLOC_SIZE;
	vector.end.x = (e->player.x + e->dir_p.x + e->plane_p.x) * BLOC_SIZE;
	vector.end.y = (e->player.y + e->dir_p.y + e->plane_p.y) * BLOC_SIZE;
	virtual_init(&vector);
	e->mlx->img->color = 0x5B507A;
	
	x = 0;
	while (x < WIDTH)
	{
		rayon.start.x = e->player.x * BLOC_SIZE;
		rayon.start.y = e->player.y * BLOC_SIZE;

		rayon.end = vector.start;
		virtual_init(&rayon);
		size = calc_size_ray(e, &rayon);
		// apres calc_size_ray, lray.start s'est deplace de vector.start vers le point de collision avec le mur
		// calc_size_ray retourne la distance entre le mur (lray.start) et le plan de projection (lray.end)
		draw_wall(e, size, x);
		err = vector.err;
		if (err > -vector.dist.x)
		{
			vector.err -= vector.dist.y;
			vector.start.x += vector.sx;
		}
		if (err < vector.dist.y)
		{
			vector.err += vector.dist.x;
			vector.start.y += vector.sy;
		}
		x++;
	}
}
