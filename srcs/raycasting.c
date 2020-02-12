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

void	draw_wall(t_env *e, t_pos cur)
{
	t_pos start;
	t_pos end;
	int midheight;

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


void	raycasting(t_env *e)
{
	t_pos cur;

	cur.x = 0;
	cur.y = 0;
	while (cur.x < WIDTH)
	{
		draw_one_by_one(e);
		draw_wall(e, cur);
		cur.x++;
	}
	cur.x = 0;
	cur.y = HEIGHT/2;
	while (cur.x < WIDTH)
	{
		put_pixel_color(e, 65535, &cur);
		cur.x++;
	}
}