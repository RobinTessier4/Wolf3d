/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:25:51 by rotessie          #+#    #+#             */
/*   Updated: 2020/01/30 11:06:15 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	render_sky(t_env *e)
{
	t_pos	start;
	t_pos	end;

	start.x = 0;
	start.y = 0;
	end.x = WIDTH;
	end.y = HEIGHT / 2;
	if (e->nightshift == 0)
		fill_img_pos(e->mlx, DAYSKY, start, end);
	else
		fill_img_pos(e->mlx, NIGHTSKY, start, end);
}

static void	render_floor(t_env *e)
{
	t_pos	start;
	t_pos	end;

	start.x = 0;
	start.y = HEIGHT / 2;
	end.x = WIDTH;
	end.y = HEIGHT;
	if (e->nightshift == 0)
		fill_img_pos(e->mlx, DAYFLOOR, start, end);
	else
		fill_img_pos(e->mlx, NIGHTFLOOR, start, end);
}

static void	display_hud(t_env *e)
{
	if (e->help == 1)
	{
		hud_background(e);
		hud_frame(e);
	}
	mlx_put_image_to_window(e->mlx->ptr, e->mlx->wind, e->mlx->img->ptr, 0, 0);
	if (e->help == 1)
		info(e);
}

void		render_raycasting(t_env *e)
{
	render_sky(e);
	render_floor(e);
	raycasting(e);
	display_hud(e);
}

void		render_2d_map(t_env *e)
{
	draw_grid(e);
	player_position(e);
	draw_vector(e);
	display_hud(e);
}
