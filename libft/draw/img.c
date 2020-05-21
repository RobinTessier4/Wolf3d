/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 17:54:57 by alebui            #+#    #+#             */
/*   Updated: 2019/07/24 17:54:59 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

t_img			*ft_new_image(void *ptr, int width, int height)
{
	t_img		*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (NULL);
	if (img)
	{
		img->img_s.x = width;
		img->img_s.y = height;
	}
	if (!(img->ptr = mlx_new_image(ptr, width, height)))
	{
		free(img);
		img = NULL;
	}
	if (!(img->data = mlx_get_data_addr(img->ptr, &img->bpp, &img->s_line,
		&img->endian)))
	{
		free(img->ptr);
		free(img);
		img = NULL;
	}
	return (img);
}

void			ft_destroy_image(void *ptr, t_img *img)
{
	if (!img || !ptr)
		return ;
	mlx_destroy_image(ptr, img->ptr);
	free(img);
}

int				img_pixel_put(t_mlx *mlx, t_pos pos, int col)
{
	int			index;
	int			bpp;
	t_uint32	color;
	t_img		*img;

	img = mlx->img;
	if ((!(pos.x >= 0 && pos.y >= 0))
		&& (!(pos.x < mlx->img->img_s.x && pos.y < mlx->img->img_s.y)))
		return (-1);
	bpp = img->bpp / 8;
	color = true_color(mlx->ptr, img->endian, col);
	index = pos.y * img->s_line + pos.x * bpp;
	ft_memcpy(img->data + index, &color, bpp);
	return (0);
}
