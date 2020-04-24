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
//				put_pixel_color(e, tab[pos.y][pos.x], &pos);
				pos.x++;
		}
		pos.x = 0;
		pos.y++;
}
	e->text = tab;
}

int		get_text(t_env *e, t_pos_d rayend, int pos)
{
	int color;
	int intx;
	int inty;
	int x;
	int y;

	intx = (int)rayend.x;
	inty = (int)rayend.y;
//	printf("inty = %d\n", inty);
//	printf("intx = %d\n", intx);
//	printf("rayend y = %f\n", rayend.y);
//	printf("rayend x = %f\n", rayend.x);

	rayend.x = rayend.x - intx;
	rayend.y = rayend.y - inty;
	x = rayend.x * WIDTH;
	y = rayend.y * HEIGHT;
	if (pos >= 499)
	pos = 499;
//	printf("x = %d\n", x);
//	printf("y = %d\n", y);
	if (inty == 0 || inty == 5)
	{
//	printf("check\n");
	color = e->text[pos][x];
	}
	else
	color = e->text[pos][y];
	return (color);
}

void		draw_text(t_env *e, t_vector *wall, t_pos_d rayend)
{
	int		y;
	int end;
	double pos;


	y = 0;
	end = wall->start.y * 2;
	if (!e)
		return ;
	while (wall->start.y != wall->end.y)
		{
			pos = (double)y / end;
//	printf("y = %d\n", y);
//	printf("pos = %f\n", pos);
			put_pixel_color(e, get_text(e, rayend, pos * HEIGHT), &wall->start);
			wall->start.y++;
			y++;
		}
}

/*void		draw_text(t_env *e, t_vector *wall, t_pos_d rayend)
{
	int		e2;

	if (!e)
		return ;
	while (wall->start.x != wall->end.x || wall->start.y != wall->end.y)
	{
		if (wall->start.x < WIDTH)
			put_pixel_color(e, get_text(e, rayend, wall), &wall->start);
		e2 = wall->err;
		if (e2 > -wall->dist.x)
		{
			wall->err -= wall->dist.y;
			wall->start.x += wall->sx;
		}
		if (e2 < wall->dist.y)
		{
			wall->err += wall->dist.x;
			wall->start.y += wall->sy;
		}
	}
}*/

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
