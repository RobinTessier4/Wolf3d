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

/*
void	draw_info_line(t_env *e)
{
	int x;
	int y;
	int i;

	y = 0;
	x = 390;
	while (y != 500)
	{
		i = ((x * e->mlx->img->bpp) / 8) + (y * e->mlx->img->s_line);
		e->mlx->img->data[i] = (char)0;
		e->mlx->img->data[i + 1] = (char)0;
		e->mlx->img->data[i + 2] = (char)0;
		y++;
	}
	x++;
	while (x != 500)
	{
		y = 0;
		while (y != 500)
		{
			i = ((x * e->mlx->img->bpp) / 8) + (y * e->mlx->img->s_line);
			if (y < 440)
			{
				e->mlx->img->data[i] = (char)145;
				e->mlx->img->data[i + 1] = (char)158;
				e->mlx->img->data[i + 2] = (char)53;
			}
			else
			{
				e->mlx->img->data[i] = (char)80;
				e->mlx->img->data[i + 1] = (char)60;
				e->mlx->img->data[i + 2] = (char)80;
			}
			y++;
		}
		x++;
	}
}
*/

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
	end.y = 250;
	drawline(e->mlx, start, end, color);
	e->mlx->img->color = WHITE;
	start.x = WIDTH - (WIDTH / 5);
	start.y = 250;
	end.x = WIDTH;
	end.y = 250;
	drawline(e->mlx, start, end, color);
}

void		hud_background(t_env *e)
{
	t_pos	start;
	t_pos	end;

	start.x = WIDTH - (WIDTH / 5) + 2;
	start.y = 0;
	end.x = WIDTH;
	end.y = 250;
	fill_img_pos(e->mlx, 0x253237, start, end);
}

void		info(t_env *e)
{
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 10, 0x9100FF, "Display HUD");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 30, 0xFFFFFF, "Space");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 60, 0x9100FF, "Move");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 80, 0xFFFFFF, "WASD");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 110, 0x9100FF, "Turn");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 130, 0xFFFFFF, "Arrows");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 160, 0x9100FF, "Map");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 180, 0xFFFFFF, "M");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 220, 0x9100FF, "Close");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 240, 0xFFFFFF, "ESC");
}