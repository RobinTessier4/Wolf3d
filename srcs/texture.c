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

static void		set_texture(t_env *e, int a, int b)
{
	int			i;
	char		*stonepath;
	char		*woodpath;

	i = 0;
	stonepath = ft_strdup("textures/stone0.xpm");
	woodpath = ft_strdup("textures/wood0.xpm");
	while (i < 4)
	{
		stonepath[14] = (i + 1) + 48;
		e->text[i].img = mlx_xpm_file_to_image(e->mlx->ptr, stonepath, &a, &b);
		e->text[i].data = mlx_get_data_addr(e->text[i].img, &e->text[i].bpp,
			&e->text[i].sizeline, &e->text[i].endian);
		i++;
	}
	while (i < 8)
	{
		woodpath[13] = i - i + 1 + 48;
		e->text[i].img = mlx_xpm_file_to_image(e->mlx->ptr, woodpath, &a, &b);
		e->text[i].data = mlx_get_data_addr(e->text[i].img, &e->text[i].bpp,
			&e->text[i].sizeline, &e->text[i].endian);
		i++;
	}
}

int				texture_init(t_env *e)
{
	int			a;
	int			b;

	a = 64;
	b = 64;
	// set_stone_texture(e, a, b);
	// set_wood_texture(e, a, b);
	set_texture(e, a, b);
	return (0);
}

void			get_texture_color(t_env *e, int i, int x, int pos)
{
	e->red = e->text[i].data[(x * e->text[i].bpp)
		/ 8 + (pos * e->text[i].sizeline)];
	e->green = e->text[i].data[((x * e->text[i].bpp) / 8)
		+ 1 + (pos * e->text[i].sizeline)];
	e->blue = e->text[i].data[((x * e->text[i].bpp) / 8)
		+ 2 + (pos * e->text[i].sizeline)];
	e->color = (e->blue << 16) | (e->green << 8) | e->red;
}

static void		calc_render_texture
	(t_env *e, t_pos_d pos, t_pos ray_pos, t_pos coord)
{
	if (e->rayend.y >= 0.996 || e->rayend.y <= 0.004)
	{
		if (((e->dir_p.y - e->plane_p.y) - (((e->dir_p.y - e->plane_p.y)
			- (e->dir_p.y + e->plane_p.y)) * ((double)pos.x / WIDTH))) < 0)
			get_texture_color(e, (e->file[ray_pos.y][ray_pos.x] * 4) - 4,
				coord.x, pos.y);
		else
			get_texture_color(e, (e->file[ray_pos.y][ray_pos.x] * 4) - 4 + 1,
				coord.x, pos.y);
	}
	else
	{
		if (((e->dir_p.x - e->plane_p.x) - (((e->dir_p.x - e->plane_p.x)
			- (e->dir_p.x + e->plane_p.x)) * ((double)pos.x / WIDTH))) > 0)
			get_texture_color(e, (e->file[ray_pos.y][ray_pos.x] * 4) - 4 + 2,
				coord.y, pos.y);
		else
			get_texture_color(e, (e->file[ray_pos.y][ray_pos.x] * 4) - 4 + 3,
				coord.y, pos.y);
	}
}

unsigned int	render_texture(t_env *e, t_pos_d pos)
{
	t_pos		ray_pos;
	t_pos		coord;

	ray_pos.x = (int)e->rayend.x;
	ray_pos.y = (int)e->rayend.y;
	e->rayend.x = e->rayend.x - ray_pos.x;
	e->rayend.y = e->rayend.y - ray_pos.y;
	coord.x = e->rayend.x * 250;
	coord.y = e->rayend.y * 250;
	calc_render_texture(e, pos, ray_pos, coord);
	return (e->color);
}
