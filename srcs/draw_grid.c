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

void	draw_grid(t_env *e)
{
	t_pos pos;

	pos.y = 0;
	if (e)
		printf("draw_grid\n");
	while (pos.y < HEIGHT)
	{
		pos.x = 0;		
		while (pos.x <= WIDTH)
		{
			e->x2 = pos.x / e->x1;
			e->y2 = pos.y / e->y1;
			if (e->y2 <= e->map_height && e->x2 <= e->map_width)
			{
				if (e->file[e->y2][e->x2] == 0)
					put_pixel_color(e, 0x7570B3, &pos);
				else if (e->file[e->y2][e->x2] == 1)
					put_pixel_color(e, 0x888888, &pos);
				else if (e->file[e->y2][e->x2] == 2)
					put_pixel_color(e, 0x1B9E77, &pos);
				else if (e->file[e->y2][e->x2] == 3)
					put_pixel_color(e, 0xE7298A, &pos);
			}
			else
			{
				put_pixel_color(e, WHITE, &pos);
				printf("OUTSIDE\n");
			}
			pos.x++;
		}
		pos.y++;
	}
}

/*
void		draw_line(t_env *e, t_vector *v)
{
	int		e2;

	while (v->x1 != v->x2 || v->y1 != v->y2)
	{
		if (v->x1 < e->image_x)
			put_pixel(e, v->x1, v->y1, 7869695);
		e2 = v->err;
		if (e2 > -v->dx)
		{
			v->err -= v->dy;
			v->x1 += v->sx;
		}
		if (e2 < v->dy)
		{
			v->err += v->dx;
			v->y1 += v->sy;
		}
	}
}

void		draw_inf_line(t_env *e, t_vector *v, int i)
{
	int		e2;

	e->x2 = v->x1 / e->x1;
	e->y2 = v->y1 / e->y1;
	while ((v->x1 > 0 && v->y1 > 0) && (v->x1 < e->image_x && v->y1 < e->image_y) && (e->tab[e->y2][e->x2] == 0))
	{
		e->x2 = v->x1 / e->x1;
		e->y2 = v->y1 / e->y1;
		if (v->x1 < e->image_x)
			put_pixel(e, v->x1, v->y1, 7869695);
		e2 = v->err;
		if (e2 > -v->dx)
		{
			v->err -= v->dy;
			v->x1 += v->sx;
		}
		if (e2 < v->dy)
		{
			v->err += v->dx;
			v->y1 += v->sy;
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

void	vector_init(t_env *e, t_vector *v)
{
	if (!e)
		return ;
	v->dx = ft_abs(v->x2 - v->x1);
	v->dy = ft_abs(v->y2 - v->y1);
	v->sx = v->x1 < v->x2 ? 1 : -1;
	v->sy = v->y1 < v->y2 ? 1 : -1;
	v->err = (v->dx > v->dy ? v->dx : -v->dy) / 2;
}

void	ray_init(t_env *e)
{
	e->dir->x1 = e->x * e->x1;
	e->dir->y1 = e->y * e->y1;
	e->dir->x2 = (e->x + e->xdir) * e->x1;
	e->dir->y2 = (e->y + e->ydir) * e->y1;

	e->plane->x1 = (e->x + e->xdir - e->xplane) * e->x1;
	e->plane->y1 = (e->y + e->ydir - e->yplane) * e->y1;
	e->plane->x2 = (e->x + e->xdir + e->xplane) * e->x1;
	e->plane->y2 = (e->y + e->ydir + e->yplane) * e->y1;

	e->lray->x1 = e->dir->x1;
	e->lray->y1 = e->dir->y1;
	e->lray->x2 = e->plane->x1;
	e->lray->y2 = e->plane->y1;
	e->rray->x1 = e->dir->x1;
	e->rray->y1 = e->dir->y1;
	e->rray->x2 = e->plane->x2;
	e->rray->y2 = e->plane->y2;
}


void	player_position(t_env *e)
{
	int x;
	int y;
	int x1;
	int y1;

	x = e->x * e->x1;
	y = e->y * e->y1;
	x1 = x - 2;
	y1 = y - 2;
	while (y1 != y + 2)
	{
		while (x1 != x + 2)
		{
			put_pixel(e, x1, y1, 16711680);
			x1++;
		}
		x1 = x - 2;
		y1++;
	}
	draw_vector(e);
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
	t_pos pos1;
	t_pos pos2;

	pos1.x = e->x * e->x1;
	pos1.y = e->y * e->y1;
	pos2.x = pos1.x - 2;
	pos2.y = pos1.y - 2;
	while (pos2.y != pos1.y + 2)
	{
		while (pos2.x != pos1.x + 2)
		{
			put_pixel_color(e, 16711680, &pos2);
			pos2.x++;
		}
		pos2.x = pos1.x - 2;
		pos2.y++;
	}
	// draw_vector(e);
}