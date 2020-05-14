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
	mlx_clear_window(e->mlx->ptr, e->mlx->wind);
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

void	draw_raycasting(t_env *e)
{
	ft_destroy_image (e->mlx->ptr, e->mlx->img);
	e->mlx->img = ft_new_image (e->mlx->ptr, WIDTH, HEIGHT);
	draw_sky_floor(e);
raycasting(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
}

void	draw_2D_map(t_env *e)
{
	fill_img(e->mlx, WHITE, WIDTH, HEIGHT);
	draw_grid(e);
	player_position(e);
	draw_vector(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
}
