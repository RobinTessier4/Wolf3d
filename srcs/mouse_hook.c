/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:35:16 by rotessie          #+#    #+#             */
/*   Updated: 2020/01/06 17:38:28 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		mouse_hook(int key, int x, int y, t_env *e)
{
	int screenmid;

	screenmid = WIDTH / 2;
	key = 0;
	y = 0;

	if (x < screenmid)
	{
		e->oldx = e->dir_p.x;
		e->dir_p.x = e->dir_p.x * cos(-ROT_SPEED) - e->dir_p.y * sin(-ROT_SPEED);
		e->dir_p.y = e->oldx * sin(-ROT_SPEED) + e->dir_p.y * cos(-ROT_SPEED);

		e->oldx = e->plane_p.x;

		e->plane_p.x = e->plane_p.x * cos(-ROT_SPEED) - e->plane_p.y * sin(-ROT_SPEED);
		e->plane_p.y = e->oldx * sin(-ROT_SPEED) + e->plane_p.y * cos(-ROT_SPEED);
	}
	else if (x > screenmid)
	{
		e->oldx = e->dir_p.x;
		e->dir_p.x = e->dir_p.x * cos(ROT_SPEED) - e->dir_p.y * sin(ROT_SPEED);
		e->dir_p.y = e->oldx * sin(ROT_SPEED) + e->dir_p.y * cos(ROT_SPEED);
		e->oldx = e->plane_p.x;

		e->plane_p.x = e->plane_p.x * cos(ROT_SPEED) - e->plane_p.y * sin(ROT_SPEED);
		e->plane_p.y = e->oldx * sin(ROT_SPEED) + e->plane_p.y * cos(ROT_SPEED);
	}

	draw_2D_map(e);
	return (0);
}
