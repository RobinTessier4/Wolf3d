/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:33:39 by alebui            #+#    #+#             */
/*   Updated: 2019/08/06 14:33:40 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

int			fill_img(t_mlx *mlx, int color, int width, int height)
{
	t_pos	pos;

	if (!mlx || !width || !height)
		return (-1);
	pos.y = 0;
	mlx->img->color = color;
	while (pos.y < height)
	{
		pos.x = 0;
		while (pos.x < width)
		{
			img_pixel_put(mlx, pos, color);
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}

int			fill_img_pos(t_mlx *mlx, int color, t_pos start, t_pos end)
{
	t_pos	start2;

	start2 = start;
	if (!mlx)
		return (-1);
	mlx->img->color = color;
	while (start2.y < end.y)
	{
		start2.x = start.x;
		while (start2.x < end.x)
		{
			img_pixel_put(mlx, start2, color);
			start2.x++;
		}
		start2.y++;
	}
	return (0);
}
