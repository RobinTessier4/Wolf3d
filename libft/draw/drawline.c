/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:35:25 by alebui            #+#    #+#             */
/*   Updated: 2019/07/25 14:35:30 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

static void	drawline_x(t_mlx *mlx, t_pos start, t_pos end)
{
	char	i;
	t_pos	p;

	i = 0;
	p.x = start.x;
	while (p.x <= end.x)
	{
		p.y = start.y;
		if (end.x - start.x != 0)
			p.y += ((end.y - start.y) * (p.x - start.x)) / (end.x - start.x);
		else
			p.y += ((end.y - start.y) * (p.x - start.x));
		if (i == 0 && start.y != p.y)
			i = (start.y > p.y) ? -1 : 1;
		if (p.x >= mlx->mlx_s.x || (i == -1 && p.y < 0) \
			|| (i == 1 && p.y >= mlx->mlx_s.y))
			break ;
		else if (p.x < 0 || p.y < 0 || p.y >= mlx->mlx_s.y)
		{
			p.x = (p.x < 0) ? 0 : p.x + 1;
			continue ;
		}
		img_pixel_put(mlx, p);
		p.x++;
	}
}

static void	drawline_y(t_mlx *mlx, t_pos start, t_pos end)
{
	char	i;
	t_pos	p;

	i = 0;
	p.y = start.y;
	while (p.y <= end.y)
	{
		p.x = start.x;
		if (end.y - start.y != 0)
			p.x += ((end.x - start.x) * (p.y - start.y)) / (end.y - start.y);
		else
			p.x = ((end.x - start.x) * (p.y - start.y));
		if (i == 0 && start.x != p.x)
			i = (start.x > p.x) ? -1 : 1;
		if (p.y >= mlx->mlx_s.y || (i == -1 && p.x < 0) \
			|| (i == 1 && p.x >= mlx->mlx_s.x))
			break ;
		else if (p.y < 0 || p.x < 0 || p.x >= mlx->mlx_s.x)
		{
			p.y = (p.y < 0) ? 0 : p.y + 1;
			continue ;
		}
		img_pixel_put(mlx, p);
		p.y++;
	}
}

int			drawline(t_mlx *mlx, t_pos start, t_pos end)
{
	if (abs(end.x - start.x) >= abs(end.y - start.y))
	{
		if (start.x <= end.x)
			drawline_x(mlx, start, end);
		else
			drawline_x(mlx, end, start);
	}
	else if (abs(end.x - start.x) <= abs(end.y - start.y))
	{
		if (start.y <= end.y)
			drawline_y(mlx, start, end);
		else
			drawline_y(mlx, end, start);
	}
	return (0);
}
