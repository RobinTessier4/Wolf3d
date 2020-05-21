/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:35:25 by alebui            #+#    #+#             */
/*   Updated: 2019/08/01 14:35:30 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

int			draw_circle(t_mlx *mlx, t_pos *origin, int angle, int rayon)
{
	double	i;
	double	rad;
	t_pos	or;

	i = 0;
	if (!mlx)
		return (-1);
	while (i <= angle)
	{
		rad = i * (2 * M_PI) / 360;
		or.x = origin->x + rayon * cos(rad);
		or.y = origin->y + rayon * sin(rad);
		i = i + ((2 * M_PI) / (8 * rayon));
		if (or.x < 0 || or.y < 0 || or.x >= mlx->mlx_s.x
			|| or.y >= mlx->mlx_s.y)
			continue ;
		img_pixel_put(mlx, or, color);
	}
	return (0);
}
