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

static void	put_pixel_2dmap(t_env *e, t_pos cursor)
{
	if (e->file[e->current_bloc.y][e->current_bloc.x] == 0)
		put_pixel_color(e, FLOOR, &cursor);
	else if (e->file[e->current_bloc.y][e->current_bloc.x] == 1)
		put_pixel_color(e, BEYOND_MAP, &cursor);
	else if (e->file[e->current_bloc.y][e->current_bloc.x] == 2)
		put_pixel_color(e, BLOC_COLOR, &cursor);
}

void		draw_grid(t_env *e)
{
	t_pos	cursor;

	cursor.y = 0;
	while (cursor.y < HEIGHT)
	{
		cursor.x = 0;
		while (cursor.x < WIDTH)
		{
			e->current_bloc.x = cursor.x / e->bloc_width;
			e->current_bloc.y = cursor.y / e->bloc_height;
			if (e->current_bloc.x < e->map_width
				&& e->current_bloc.y < e->map_height && e->current_bloc.x >= 0
				&& e->current_bloc.y >= 0)
				put_pixel_2dmap(e, cursor);
			else
				put_pixel_color(e, BEYOND_MAP, &cursor);
			cursor.x++;
		}
		cursor.y++;
	}
}

void		player_position(t_env *e)
{
	t_pos	start;
	t_pos	end;

	start.x = e->player.x * e->bloc_width;
	start.y = e->player.y * e->bloc_height;
	end.x = start.x - 2;
	end.y = start.y - 2;
	while (end.y != start.y + 2)
	{
		while (end.x != start.x + 2)
		{
			put_pixel_color(e, PLAYER_COL, &end);
			end.x++;
		}
		end.x = start.x - 2;
		end.y++;
	}
}

void		render_player_fov(t_env *e, t_vector *v)
{
	int		e2;

	e->current_bloc.x = v->start.x / e->bloc_width;
	e->current_bloc.y = v->start.y / e->bloc_height;
	while ((v->start.x > 0 && v->start.y > 0
				&& v->start.x < WIDTH && v->start.y < HEIGHT)
				&& (e->current_bloc.y < e->map_height
				&& e->current_bloc.x < e->map_width
				&& e->current_bloc.x >= 0 && e->current_bloc.y >= 0)
				&& (e->file[e->current_bloc.y][e->current_bloc.x] == 0))
	{
		e->current_bloc.x = v->start.x / e->bloc_width;
		e->current_bloc.y = v->start.y / e->bloc_height;
		if (v->start.x < WIDTH && v->start.x > 0 && v->start.y > 0
			&& v->start.y < HEIGHT)
			put_pixel_color(e, RAY, &v->start);
		e2 = v->err;
		calc_line(e2, v);
	}
}
