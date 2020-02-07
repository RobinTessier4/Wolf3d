/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:35:17 by alebui            #+#    #+#             */
/*   Updated: 2019/09/29 15:35:22 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

t_mlx	*mlx_start(int width, int height, char *title)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		mlx = NULL;
	if (mlx && !(mlx->ptr = mlx_init()))
		mlx = NULL;
	if (mlx)
	{
		mlx->mlx_s.x = width;
		mlx->mlx_s.y = height;
	}
	if (mlx && !(mlx->wind = mlx_new_window(mlx->ptr, width, height, title)))
	{
		free(mlx->ptr);
		free(mlx);
		mlx = NULL;
	}
	if (mlx && !(mlx->img = ft_new_image(mlx->ptr, width, height)))
	{
		free(mlx->ptr);
		free(mlx->wind);
		free(mlx);
		mlx = NULL;
	}
	return (mlx);
}

void	mlx_destroy(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->img)
		ft_destroy_image(mlx->ptr, mlx->img);
	mlx_destroy_window(mlx->ptr, mlx->wind);
	free(mlx);
}
