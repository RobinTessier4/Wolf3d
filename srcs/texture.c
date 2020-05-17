/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:27 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:06:19 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	text_stone_init(t_env *e, int a, int b)
{
	e->text[0].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone1.xpm", &a, &b);
	e->text[0].data = mlx_get_data_addr(e->text[0].img, &e->text[0].bpp, &e->text[0].sizeline, &e->text[0].endian);
	e->text[1].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone3.xpm", &a, &b);
	e->text[1].data = mlx_get_data_addr(e->text[1].img, &e->text[1].bpp, &e->text[1].sizeline, &e->text[1].endian);
	e->text[2].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone2.xpm", &a, &b);
	e->text[2].data = mlx_get_data_addr(e->text[2].img, &e->text[2].bpp, &e->text[2].sizeline, &e->text[2].endian);
	e->text[3].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone4.xpm", &a, &b);
	e->text[3].data = mlx_get_data_addr(e->text[3].img, &e->text[3].bpp, &e->text[3].sizeline, &e->text[3].endian);
}

static void	text_wood_init(t_env *e, int a, int b)
{
	e->text[4].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood1.xpm", &a, &b);
	e->text[4].data = mlx_get_data_addr(e->text[4].img, &e->text[4].bpp, &e->text[4].sizeline, &e->text[4].endian);
	e->text[5].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood3.xpm", &a, &b);
	e->text[5].data = mlx_get_data_addr(e->text[5].img, &e->text[5].bpp, &e->text[5].sizeline, &e->text[5].endian);
	e->text[6].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood2.xpm", &a, &b);
	e->text[6].data = mlx_get_data_addr(e->text[6].img, &e->text[6].bpp, &e->text[6].sizeline, &e->text[6].endian);
	e->text[7].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood4.xpm", &a, &b);
	e->text[7].data = mlx_get_data_addr(e->text[7].img, &e->text[7].bpp, &e->text[7].sizeline, &e->text[7].endian);
}

int			text_init(t_env *e)
{
	int		a;
	int		b;

	a = 64;
	b = 64;
	text_stone_init(e, a, b);
	text_wood_init(e, a, b);
	return (0);
}