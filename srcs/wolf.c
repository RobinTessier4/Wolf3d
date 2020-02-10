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

void	wolf(t_env *e)
{
	printf("wolf.c\n");
	draw_grid(e); // segfault is here
//	player_position(e);
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
}