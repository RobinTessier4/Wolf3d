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

void		draw_horizon(t_env *e)
{
	t_pos	horizon_start;
	t_pos	horizon_end;

	horizon_start.x = 0;
	horizon_start.y = HEIGHT/2; 
	horizon_end.x = WIDTH;
	horizon_end.y = HEIGHT/2; 
	e->mlx->img->color = 65535;
	drawline(e->mlx, horizon_start, horizon_end);
}

double		calc_size_ray(t_env *e, t_vector *v)
{
	int		e2;
	double	size;

	e->current_bloc.x = v->start.x / BLOC_SIZE;
	e->current_bloc.y = v->start.y / BLOC_SIZE;
	while (e->file[e->current_bloc.y][e->current_bloc.x] == 0)
	{
		e->current_bloc.x = v->start.x / BLOC_SIZE;
		e->current_bloc.y = v->start.y / BLOC_SIZE;
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
	v->dist.x = abs(v->start.x - v->end.x);
	v->dist.y = abs(v->start.y - v->end.y);
	size = sqrt(v->dist.x * v->dist.x + v->dist.y * v->dist.y);
	return (size);
}

static void		draw_wall(t_env *e, double dist, int x)
{
	t_pos		start;
	t_pos		end;
	int			size;
	// midheight = HEIGHT / 2
	// size = BLOC_HEIGHT / dist

	if (dist > 0)
		size = BLOC_HEIGHT / dist;
	else
		size = HEIGHT / 2;
	start.x = x;
	start.y = (HEIGHT / 2) - size;
	end.x = x;
	end.y = (HEIGHT / 2) + size;
	drawline(e->mlx, start, end);
}

void			raycasting(t_env *e)
{
	int			x;
	int			err;
	double		size;
	t_vector	vector;
	
	x = 0;
	vector.start.x = (e->player.x + e->dir_p.x - e->plane_p.x) * BLOC_SIZE;
	vector.start.y = (e->player.y + e->dir_p.y - e->plane_p.y) * BLOC_SIZE;
	vector.end.x = (e->player.x + e->dir_p.x + e->plane_p.x) * BLOC_SIZE;
	vector.end.y = (e->player.y + e->dir_p.y + e->plane_p.y) * BLOC_SIZE;
	vector_init(e, &vector);
	e->mlx->img->color = 0xF5CB5C;
	while (x < WIDTH)
	{
		e->lray->start.x = e->player.x * BLOC_SIZE;
		e->lray->start.y = e->player.y * BLOC_SIZE;
		e->lray->end = vector.start;
		vector_init(e, e->lray);
		size = calc_size_ray(e, e->lray);
		printf("x: %d ; size: %f\n", x, size);
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
	draw_horizon(e);
}

/*
void		draw_wall(t_env *e, t_pos cur)
{
	t_pos	start;
	t_pos	end;
	int		midheight;

	e->leftray /= 2;
	midheight = HEIGHT / 2;
	start.x = cur.x;
	start.y = e->leftray;
	end.x = cur.x;
	end.y = HEIGHT - e->leftray;
	e->mlx->img->color = 0x4EA5D9;
	printf("left ray = %d\n", e->leftray);
	drawline(e->mlx, start, end);
}
*/


