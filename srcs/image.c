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
	img_pixel_put(e->mlx, *pos);
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

static void		get_text_color(t_env *e, int i, int x, int pos)
{
	e->red = e->text[i].data[(x * e->text[i].bpp) / 8 + (pos * e->text[i].sizeline)];
	e->green = e->text[i].data[((x * e->text[i].bpp) / 8) + 1 + (pos * e->text[i].sizeline)];
	e->blue = e->text[i].data[((x * e->text[i].bpp) / 8) + 2 + (pos * e->text[i].sizeline)];
	e->color = (e->blue << 16) | (e->green << 8) | e->red;
}

unsigned int	get_text(t_env *e, t_pos_d rayend, t_pos_d pos)
{
	int intx;
	int inty;
	t_pos coord;

	intx = (int)rayend.x;
	inty = (int)rayend.y;
	rayend.x = rayend.x - intx;
	rayend.y = rayend.y - inty;
	coord.x = rayend.x * 250;
	coord.y = rayend.y * 250;
	if (rayend.y >= 0.996 || rayend.y <= 0.004)
	{
		if (((e->dir_p.y - e->plane_p.y) - (((e->dir_p.y - e->plane_p.y) - (e->dir_p.y + e->plane_p.y)) * ((double)pos.x / WIDTH))) < 0)
			get_text_color(e, (e->file[inty][intx] * 4) - 4, coord.x, pos.y);
		else
			get_text_color(e, (e->file[inty][intx] * 4) - 4 + 1, coord.x, pos.y);
	}
	else
	{
		if (((e->dir_p.x - e->plane_p.x) - (((e->dir_p.x - e->plane_p.x) - (e->dir_p.x + e->plane_p.x)) * ((double)pos.x / WIDTH))) > 0)
			get_text_color(e, (e->file[inty][intx] * 4) - 4 + 2, coord.y, pos.y);
		else
			get_text_color(e, (e->file[inty][intx] * 4) - 4 + 3, coord.y, pos.y);
	}
	return (e->color);
}

void			draw_text(t_env *e, t_vector *wall, t_pos_d rayend)
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
			put_pixel_color(e, get_text(e, rayend, pos), &wall->start);
		wall->start.y++;
		y++;
	}
}

void			draw_inf_line(t_env *e, t_vector *v)
{
	int			e2;

	e->current_bloc.x = v->start.x / e->bloc_width;
	e->current_bloc.y = v->start.y / e->bloc_height;
	while ((v->start.x > 0 && v->start.y > 0
				&& v->start.x < WIDTH && v->start.y < HEIGHT) && (e->current_bloc.y < e->map_height && e->current_bloc.x < e->map_width && e->current_bloc.x >= 0 && e->current_bloc.y >= 0)
			&& (e->file[e->current_bloc.y][e->current_bloc.x] == 0))
	{
		e->current_bloc.x = v->start.x / e->bloc_width;
		e->current_bloc.y = v->start.y / e->bloc_height;
		if (v->start.x < WIDTH && v->start.x > 0 && v->start.y > 0 && v->start.y < HEIGHT)
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
