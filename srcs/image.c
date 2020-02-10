/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:34:57 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:16:43 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

/*
void	put_pixel(t_env *e, int x, int y, unsigned int c)
{
	int i;

	if (x >= 0 && y >= 0 && x <= WIDTH && y <= HEIGHT)
	{
		i = ((x * e->bpp) / 8) +
			(y * e->sizeline);
		e->data[i] = (char)(c);
		e->data[i + 1] = (char)(c >> 8);
		e->data[i + 2] = (char)(c >> 16);
	}
}
*/

void		put_pixel_color(t_env *e, int color, t_pos *pos)
{
	e->mlx->img->color = color;
	img_pixel_put(e->mlx, *pos);
}