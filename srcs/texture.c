/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:27 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:06:19 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			get_texture_color(t_env *e, int i, int x, int pos)
{
	e->red = e->texture_tab[i]->data[(x * e->texture_tab[i]->bpp)
		/ 8 + (pos * e->texture_tab[i]->s_line)];
	e->green = e->texture_tab[i]->data[((x * e->texture_tab[i]->bpp) / 8)
		+ 1 + (pos * e->texture_tab[i]->s_line)];
	e->blue = e->texture_tab[i]->data[((x * e->texture_tab[i]->bpp) / 8)
		+ 2 + (pos * e->texture_tab[i]->s_line)];
	e->color = (e->blue << 16) | (e->green << 8) | e->red;
}

static void		calc_render_texture(t_env *e, t_pos_d pos, t_pos r,
		t_pos_d rayend)
{
	t_pos		coord;

	coord.x = rayend.x * 250;
	coord.y = rayend.y * 250;
	if (rayend.y >= 0.996 || rayend.y <= 0.004)
	{
		if (((e->dir_p.y - e->plane_p.y) - (((e->dir_p.y - e->plane_p.y)
							- (e->dir_p.y + e->plane_p.y)) * ((double)pos.x /
							WIDTH))) < 0)
			get_texture_color(e, (e->file[r.y][r.x] * 4) - 4, coord.x, pos.y);
		else
			get_texture_color(e, (e->file[r.y][r.x] * 4) - 4 + 1, coord.x,
			pos.y);
	}
	else
	{
		if (((e->dir_p.x - e->plane_p.x) - (((e->dir_p.x - e->plane_p.x)
							- (e->dir_p.x + e->plane_p.x)) *
						((double)pos.x / WIDTH))) > 0)
			get_texture_color(e, (e->file[r.y][r.x] * 4) - 4 + 2, coord.y,
			pos.y);
		else
			get_texture_color(e, (e->file[r.y][r.x] * 4) - 4 + 3, coord.y,
			pos.y);
	}
}

unsigned int	render_texture(t_env *e, t_pos_d pos, t_pos_d rayend)
{
	t_pos		ray_pos;

	ray_pos.x = (int)rayend.x;
	ray_pos.y = (int)rayend.y;
	rayend.x = rayend.x - ray_pos.x;
	rayend.y = rayend.y - ray_pos.y;
	calc_render_texture(e, pos, ray_pos, rayend);
	return (e->color);
}
