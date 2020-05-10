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

int		get_text(t_env *e, t_pos_d rayend, int posi)
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
	x = rayend.x * 64;
	y = rayend.y * 64;
	char red;
	char green;
	char blue;
		if (rayend.y >= 0.995 || rayend.y <= 0.005)
		{
	//	printf("check\n");
			red = e->text->data[(x * e->text->bpp) / 8  + (posi * e->text->sizeline)];
			green = e->text->data[((x * e->text->bpp) / 8)+ 1 + (posi * e->text->sizeline)];
			blue = e->text->data[((x * e->text->bpp) / 8) + 2 + (posi * e->text->sizeline)];
			color = (blue << 16) | (green << 8) | red;
	}
	else
	{
	red = e->text->data[(y * e->text->bpp) / 8  + (posi * e->text->sizeline)];
			green = e->text->data[((y * e->text->bpp) / 8)+ 1 + (posi * e->text->sizeline)];
			blue = e->text->data[((y * e->text->bpp) / 8) + 2 + (posi * e->text->sizeline)];
			color = (blue << 16) | (green << 8) | red;
}
/*
	t_pos pos;
	pos.x = 0;
	pos.y = 0;
	while (pos.y < 500)
	{
		while (pos.x < 500)
		{
			red = e->text->data[(pos.x * e->text->bpp) / 8  + (pos.y * e->text->sizeline)];
			green = e->text->data[((pos.x * e->text->bpp) / 8)+ 1 + (pos.y * e->text->sizeline)];
			blue = e->text->data[((pos.x * e->text->bpp) / 8) + 2 + (pos.y * e->text->sizeline)];
			color = (blue << 16) | (green << 8) | red;
		put_pixel_color(e, color, &pos);
		pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
*/

	return (color);
}

void		draw_text(t_env *e, t_vector *wall, t_pos_d rayend)
{
	int		y;
	int end;
	int pos;


	y = 0;
	end = wall->start.y + (HEIGHT - wall->end.y);
	if (!e)
		return ;
	while (wall->start.y != wall->end.y)
	{
		pos = y / (((double)HEIGHT - end) / 64);
		put_pixel_color(e, get_text(e, rayend, pos), &wall->start);
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
