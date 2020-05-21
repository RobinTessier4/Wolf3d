/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:33:39 by alebui            #+#    #+#             */
/*   Updated: 2019/08/06 14:33:40 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void		hud_frame(t_env *e)
{
	t_pos	start;
	t_pos	end;
	int		color;

	color = 0x89fc00;
	e->mlx->img->color = color;
	start.x = WIDTH - (WIDTH / 5);
	start.y = 0;
	end.x = WIDTH - (WIDTH / 5);
	end.y = 300;
	drawline(e->mlx, start, end, color);
	e->mlx->img->color = WHITE;
	start.x = WIDTH - (WIDTH / 5);
	start.y = 300;
	end.x = WIDTH;
	end.y = 300;
	drawline(e->mlx, start, end, color);
}

void		hud_background(t_env *e)
{
	t_pos	start;
	t_pos	end;

	start.x = WIDTH - (WIDTH / 5) + 1;
	start.y = 0;
	end.x = WIDTH;
	end.y = 300;
	if (e->nightshift == 0)
		fill_img_pos(e->mlx, DAY_HUD, start, end);
	else
		fill_img_pos(e->mlx, NIGHT_HUD, start, end);
}

void		info(t_env *e)
{
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 10,
		TITLE_HUD, "Display HUD");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 30, TEXT_HUD, "Space");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 60, TITLE_HUD, "Move");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 80, TEXT_HUD, "WASD");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 110, TITLE_HUD, "Turn");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 130, TEXT_HUD, "Arrows");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 160, TITLE_HUD, "Map");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 180, TEXT_HUD, "M");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 210,
		TITLE_HUD, "Nightshift");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 230, TEXT_HUD, "shift");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 260, TITLE_HUD, "Close");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 280, TEXT_HUD, "ESC");
}
