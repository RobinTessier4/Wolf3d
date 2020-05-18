/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:25:51 by rotessie          #+#    #+#             */
/*   Updated: 2020/01/30 11:06:15 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	draw_sky_floor(t_env *e)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
//	mlx_clear_window(e->mlx->ptr, e->mlx->wind);
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			i = ((x * e->mlx->img->bpp) / 8) + (y * e->mlx->img->s_line);
			if (y < HEIGHT / 2)
			{
				e->mlx->img->data[i] = (char)180;
				e->mlx->img->data[i + 1] = (char)150;
				e->mlx->img->data[i + 2] = (char)0;
			}
			else
			{
				e->mlx->img->data[i] = (char)80;
				e->mlx->img->data[i + 1] = (char)80;
				e->mlx->img->data[i + 2] = (char)80;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

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

void	info(t_env *e)
{
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 400, 10, 0x9100FF, "Displ cmd");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 30, 0xFFFFFF, "Space");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 425, 60, 0x9100FF, "Move");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 425, 80, 0xFFFFFF, "WASD");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 425, 110, 0x9100FF, "Turn");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 418, 130, 0xFFFFFF, "Arrows");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 430, 160, 0x9100FF, "Map");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 440, 180, 0xFFFFFF, "M");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 420, 450, 0x9100FF, "Close");
	mlx_string_put(e->mlx->ptr, e->mlx->wind, 430, 470, 0xFFFFFF, "ESC");
}

void	draw_raycasting(t_env *e)
{
//	ft_destroy_image (e->mlx->ptr, e->mlx->img);
//	e->mlx->img = ft_new_image (e->mlx->ptr, WIDTH, HEIGHT);
	draw_sky_floor(e);
	raycasting(e);
	if (e->help == 1)
		draw_info_line(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
	if (e->help == 1)
		info(e);
}

void	draw_2D_map(t_env *e)
{
//		ft_destroy_image (e->mlx->ptr, e->mlx->img);
//	e->mlx->img = ft_new_image (e->mlx->ptr, WIDTH, HEIGHT);
		fill_img(e->mlx, WHITE, WIDTH, HEIGHT);
	draw_grid(e);
	player_position(e);
	draw_vector(e);
	if (e->help == 1)
		draw_info_line(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
	if (e->help == 1)
		info(e);
}
