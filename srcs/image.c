/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:34:57 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:16:43 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			put_pixel_color(t_env *e, int color, t_pos *pos)
{
	e->mlx->img->color = color;
	img_pixel_put(e->mlx, *pos, color);
}

void			draw_line(t_env *e, t_vector *v)
{
	int			e2;

	if (!e)
		return ;
	while (v->start.x != v->end.x || v->start.y != v->end.y)
	{
		if (v->start.x < WIDTH)
			put_pixel_color(e, 7869695, &v->start);
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
}

void			draw_text(t_env *e, t_vector *wall)
{
	int			y;
	int			end;
	t_pos_d		pos;

	pos.x = wall->start.x;
	y = 0;
	end = wall->start.y + (HEIGHT - wall->end.y);
	if (!e)
		return ;
	while (wall->start.y != wall->end.y)
	{
		pos.y = y / (((double)HEIGHT - end) / 250);
		if (wall->start.y < HEIGHT && wall->start.y > 0)
			put_pixel_color(e, render_texture(e, pos), &wall->start);
		wall->start.y++;
		y++;
	}
}
