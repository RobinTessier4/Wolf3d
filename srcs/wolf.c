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

void	draw_2D_map(t_env *e)
{
	fill_img(e->mlx, BLACK, WIDTH, HEIGHT);
	draw_grid(e);
	player_position(e);
	draw_vector(e);
	//raycasting(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
}