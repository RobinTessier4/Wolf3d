/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:52:39 by alebui            #+#    #+#             */
/*   Updated: 2019/09/29 15:52:42 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

static t_uint32	swap_endian(t_uint32 in)
{
	t_uint32	out;

	out = (in << 24);
	out |= ((in << 8) & 0x00ff0000);
	out |= ((in >> 8) & 0x0000ff00);
	out |= (in >> 24);
	return (out);
}

t_uint32		true_color(void *mlx, int endian, int rgb)
{
	t_uint32	color;

	color = mlx_get_color_value(mlx, rgb);
	if (endian == MLX_BIG_ENDIAN)
		color = swap_endian(color);
	return (color);
}

int				pixel_color(t_mlx *mlx, t_pos pos)
{
	int			index;
	int			bpp;
	t_img		*img;
	int			color;
	t_color		col;

	col.red = 0;
	col.green = 0;
	col.blue = 0;
	img = mlx->img;
	if ((!(pos.x >= 0 && pos.y >= 0))
		&& (!(pos.x < mlx->img->img_s.x && pos.y < mlx->img->img_s.y)))
		return (-1);
	bpp = img->bpp / 8;
	index = pos.y * img->s_line + pos.x * bpp;
	col.red = (int)((unsigned char)img->data[index]);
	col.green = (int)((unsigned char)img->data[index + 1]);
	col.blue = (int)((unsigned char)img->data[index + 2]);
	color = (col.blue << 16) | (col.green << 8) | col.red;
	return (color);
}
