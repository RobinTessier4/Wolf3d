/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:42:40 by rotessie          #+#    #+#             */
/*   Updated: 2020/01/30 11:12:54 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		param_init(t_env *e)
{
	if (!(e->dir = ft_memalloc(sizeof(t_vector))))
		return (1);
	if (!(e->plane = ft_memalloc(sizeof(t_vector))))
		return (1);
	if (!(e->lray = ft_memalloc(sizeof(t_vector))))
		return (1);
	if (!(e->rray = ft_memalloc(sizeof(t_vector))))
		return (1);
	e->player.x = 2.5;
	e->player.y = 2.5;
	e->dir_p.x = 0;
	e->dir_p.y = -1;
	e->plane_p.x = 0.66;
	e->plane_p.y = 0;
	e->bloc_width = WIDTH / e->map_width;
	e->bloc_height = HEIGHT / e->map_height;
	return (0);
}

t_env	*init_mlx(t_env *e)
{
	e->mlx = mlx_start(WIDTH, HEIGHT, "WOLF3D");
	e->mlx->img->color = WHITE;
	return (e);
}
