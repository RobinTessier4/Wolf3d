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

static void		virtual_init(t_virtual *v)
{
	v->dist.x = fabs(v->start.x - v->end.x);
	v->dist.y = fabs(v->start.y - v->end.y);
	v->sx = v->start.x < v->end.x ? 1 : -1;
	v->sy = v->start.y < v->end.y ? 1 : -1;
	v->sx /= WIDTH;
	v->sy /= WIDTH;
	v->err = (v->dist.x > v->dist.y ? v->dist.x : -v->dist.y) / 2;
}

double			calc_size_ray(t_env *e, t_virtual *v)
{	
	float		e2;
	double		dist;
	double		startx;
	double		starty;

	startx = v->start.x;
	starty = v->start.y;
	while (v->start.x > 0 && v->start.y > 0 && v->start.x < e->map_width && v->start.y < e->map_height && e->file[(int)v->start.y][(int)v->start.x] == 0)
	{
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
	dist = sqrt(v->dist.x * v->dist.x + v->dist.y * v->dist.y);
	return (dist);
}

static void		draw_wall(t_env *e, double dist, int x, t_pos_d rayend)
{
	int			size_wall;
	double		ecart;
	double		angle;
	t_vector	*wall;

	if (!(wall = ft_memalloc(sizeof(t_vector))))
		return ;
	size_wall = BLOC_HEIGHT / (dist + (dist / 10));
	if (size_wall == 0)
		return ;
	ecart = 2 * x / (double)WIDTH - 1;
	angle = (146 * ecart) / (WIDTH / 2);
	size_wall /= cos(angle);
	wall->start.x = x;
	wall->start.y = (HEIGHT / 2) - size_wall;
	wall->end.x = x;
	wall->end.y = (HEIGHT / 2) + size_wall;
	vector_init(e, wall);
	if (rayend.x > 0 && rayend.x < e->map_width && rayend.y > 0 && rayend.y < e->map_height)
		draw_text(e, wall, rayend);
	free(wall);
	wall = NULL;
}

void			raycasting(t_env *e)
{
	int			x;
	double		size;
	t_virtual	vector;
	t_virtual	rayon;
	t_pos_d		start;

	vector.start.x = (e->player.x + e->dir_p.x - e->plane_p.x);
	vector.start.y = (e->player.y + e->dir_p.y - e->plane_p.y);
	vector.end.x = (e->player.x + e->dir_p.x + e->plane_p.x);
	vector.end.y = (e->player.y + e->dir_p.y + e->plane_p.y);
	virtual_init(&vector);
	start = vector.start;
	x = 0;
	while (x < WIDTH)
	{
		rayon.start.x = e->player.x * BLOC_SIZE;
		rayon.start.y = e->player.y * BLOC_SIZE;
		rayon.end.x = start.x + ((vector.end.x - start.x) * (x / (double)WIDTH));
		rayon.end.y = start.y + ((vector.end.y - start.y) * (x / (double)WIDTH));
		virtual_init(&rayon);
		size = calc_size_ray(e, &rayon);
		draw_wall(e, size, x, rayon.start);
		x++;
	}
}
