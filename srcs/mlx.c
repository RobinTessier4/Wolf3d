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
	e->x = 9.5;
	e->y = 6.5;
	e->xdir = 0;
	e->ydir = -1;
	e->xplane = 0.66;
	e->yplane = 0;
	e->x1 = WIDTH / e->map_width; //renommer x1 et x2
	e->y1 = HEIGHT / e->map_height;
	// printf("e->x1: %d, e->y1: %d\n", e->x1, e->y1);
	return (0);
}

t_env	*init_mlx(t_env *e)
{
	e->mlx = mlx_start(WIDTH, HEIGHT, "WOLF3D");
	e->mlx->img->color = WHITE;
	param_init(e); //peut pas etre dans cette fonction
	return (e);
}
