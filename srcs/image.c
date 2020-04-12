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

void		put_pixel_color(t_env *e, int color, t_pos *pos)
{
	e->mlx->img->color = color;
	img_pixel_put(e->mlx, *pos);
}

void		draw_line(t_env *e, t_vector *v)
{
	int		e2;

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

void		text_init(t_env *e)
{
	int xcolor;
	int ycolor;
	int xycolor;
	int texWidth;
	int texHeight;
	int **tab;
	t_pos pos;

	(void)e;
	pos.x = 0;
	pos.y = 0;
	texWidth = 300;
	texHeight = 300;
	if (!(tab = (int**)(malloc(sizeof(int*) * HEIGHT))))
		return ;
	while (pos.y < HEIGHT)
	{
		if (!(tab[pos.y] = (int *)(malloc(sizeof(int) * WIDTH))))
			return ;
		while (pos.x < WIDTH)
		{
			xcolor = pos.x * 256 / texWidth;
			ycolor = pos.y * 256 / texHeight;
			xycolor = pos.y * 128 / texHeight + pos.x * 128 / texWidth;
			tab[pos.y][pos.x] = xycolor + 256 * xycolor + 65536 * xycolor;
			//	put_pixel_color(e, tab[pos.y][pos.x], &pos);
				pos.x++;
		}
		pos.x = 0;
		pos.y++;
}
	e->text = tab;
}

int		get_text(t_env *e, t_pos_d rayend, t_vector *v)
{
	int color;
	int intx;
	int inty;
	int x;
	int y;

	(void)v;
	intx = (int)rayend.x;
	inty = (int)rayend.y;


	rayend.x = rayend.x - intx;
	rayend.y = rayend.y - inty;
	x = rayend.x * WIDTH;
	y = rayend.y * HEIGHT;
	color = e->text[y][x];
	return (color);
}

void		draw_text(t_env *e, t_vector *v, t_pos_d rayend)
{
	int		e2;

	(void)rayend;
	if (!e)
		return ;
	while (v->start.x != v->end.x || v->start.y != v->end.y)
	{
		if (v->start.x < WIDTH)
			put_pixel_color(e, get_text(e, rayend, v), &v->start);
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

void		draw_inf_line(t_env *e, t_vector *v, int i)
{
	int		e2;

	e->current_bloc.x = v->start.x / e->bloc_width;
	e->current_bloc.y = v->start.y / e->bloc_height;

	while ((v->start.x > 0 && v->start.y > 0) 
			&& (v->start.x < WIDTH && v->start.y < HEIGHT) 
			&& (e->file[e->current_bloc.y][e->current_bloc.x] == 0))
	{
		e->current_bloc.x = v->start.x / e->bloc_width;
		e->current_bloc.y = v->start.y / e->bloc_height;
		if (v->start.x < WIDTH)
		{
			put_pixel_color(e, 7869695, &v->start);
		}
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
		if (i == 1)
			e->leftray++;
		else if (i == 2)
			e->rightray++;
		else
			e->midray++;
	}
}
