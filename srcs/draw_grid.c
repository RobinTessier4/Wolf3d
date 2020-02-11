/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:27:58 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:16:11 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		draw_grid(t_env *e)
{
	t_pos	cursor;

	cursor.y = 0;
	printf("e->map_width: %d ; e->map_height: %d\n", e->map_width, e->map_height);
	while (cursor.y < HEIGHT)
	{
		cursor.x = 0;
		while (cursor.x < WIDTH)
		{
			e->current_bloc.x = cursor.x / e->bloc_width;
			e->current_bloc.y = cursor.y / e->bloc_height;
			if (e->current_bloc.x < e->map_width && e->current_bloc.y < e->map_height)
			{
				if (e->file[e->current_bloc.y][e->current_bloc.x] == 0)
					put_pixel_color(e, 0x7570B3, &cursor);
				else if (e->file[e->current_bloc.y][e->current_bloc.x] == 1)
					put_pixel_color(e, 0x888888, &cursor);
				else if (e->file[e->current_bloc.y][e->current_bloc.x] == 2)
					put_pixel_color(e, 0x1B9E77, &cursor);
				else if (e->file[e->current_bloc.y][e->current_bloc.x] == 3)
					put_pixel_color(e, 0xE7298A, &cursor);
			}
			cursor.x++;
		}
		cursor.y++;
	}
}

void		draw_line(t_env *e, t_vector *v)
{
	int		e2;

	while (v->start.x != v->end.x || v->start.y != v->end.y)
	{
		if (v->start.x < WIDTH)
			put_pixel_color(e, 7869695, &v->start);
		e2 = v->err;
		if (e2 > -v->dx)
		{
			v->err -= v->dy;
			v->start.x += v->sx;
		}
		if (e2 < v->dy)
		{
			v->err += v->dx;
			v->start.y += v->sy;
		}
	}
}

void		draw_inf_line(t_env *e, t_vector *v, int i)
{
	int		e2;

	e->current_bloc.x = v->start.x / e->bloc_width;
	e->current_bloc.y = v->start.y / e->bloc_height;
	while ((v->start.x > 0 && v->start.y > 0) && (v->start.x < WIDTH && v->start.y < HEIGHT) && (e->tab[e->current_bloc.y][e->current_bloc.x] == 0))
	{
		e->current_bloc.x = v->start.x / e->bloc_width;
		e->current_bloc.y = v->start.y / e->bloc_height;
		if (v->start.x < WIDTH)
			put_pixel_color(e, 7869695, &v->start);
		e2 = v->err;
		if (e2 > -v->dx)
		{
			v->err -= v->dy;
			v->start.x += v->sx;
		}
		if (e2 < v->dy)
		{
			v->err += v->dx;
			v->start.y += v->sy;
		}
		if (i == 1)
			e->leftray++;
		else if (i == 2)
			e->rightray++;
		else
			e->midray++;
	}
}

int	ft_abs(int nbr)
{
	if (nbr < 0)
		nbr = -nbr;
	return (nbr);
}

/*
void	vector_init(t_env *e, t_vector *v)
{
	if (!e)
		return ;
	v->dx = ft_abs(v->end.x - v->start.x);
	v->dy = ft_abs(v->end.y - v->start.y);
	v->sx = v->start.x < v->end.x ? 1 : -1;
	v->sy = v->start.y < v->end.y ? 1 : -1;
	v->err = (v->dx > v->dy ? v->dx : -v->dy) / 2;
}

void	ray_init(t_env *e)
{
	e->dir->start.x = e->player.x * e->bloc_width;
	e->dir->start.y = e->player.y * e->bloc_height;
	e->dir->end.x = (e->player.x + e->dir_p.x) * e->bloc_width;
	e->dir->end.y = (e->player.y + e->dir_p.y) * e->bloc_height;

	e->plane->start.x = (e->player.x + e->dir_p.x - e->plane_p.x) * e->bloc_width;
	e->plane->start.y = (e->player.y + e->dir_p.y - e->plane_p.y) * e->bloc_height;
	e->plane->end.x = (e->player.x + e->dir_p.x + e->plane_p.x) * e->bloc_width;
	e->plane->end.y = (e->player.y + e->dir_p.y + e->plane_p.y) * e->bloc_height;

	e->lray->start.x = e->dir->start.x;
	e->lray->start.y = e->dir->start.y;
	e->lray->end.x = e->plane->start.x;
	e->lray->end.y = e->plane->start.y;
	e->rray->start.x = e->dir->start.x;
	e->rray->start.y = e->dir->start.y;
	e->rray->end.x = e->plane->end.x;
	e->rray->end.y = e->plane->end.y;
}

void	draw_vector(t_env *e)
{
	e->leftray = 0;
	e->rightray = 0;
	e->midray = 0;
	ray_init(e);
	vector_init(e, e->dir);
	vector_init(e, e->plane);
	vector_init(e, e->rray);
	vector_init(e, e->lray);
	draw_inf_line(e, e->dir, 3);
	draw_line(e, e->plane);
	draw_inf_line(e, e->lray, 1);
	draw_inf_line(e, e->rray, 2);
}
*/

void	player_position(t_env *e)
{

	t_pos start;
	t_pos end;

	start.x = e->player.x * e->bloc_width;
	start.y = e->player.y * e->bloc_height;
	end.x = start.x - 2;
	end.y = start.y - 2;
	while (end.y != start.y + 2)
	{
		while (end.x != start.x + 2)
		{
			put_pixel_color(e, 16711680, &end);
			end.x++;
		}
		end.x = start.x - 2;
		end.y++;
	}
//	draw_vector(e);
}