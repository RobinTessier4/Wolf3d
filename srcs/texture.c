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
	e->text[0].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone1.xpm", &a, &b);
	e->text[0].data = mlx_get_data_addr(e->text[0].img, &e->text[0].bpp, &e->text[0].sizeline, &e->text[0].endian);
	e->text[1].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone3.xpm", &a, &b);
	e->text[1].data = mlx_get_data_addr(e->text[1].img, &e->text[1].bpp, &e->text[1].sizeline, &e->text[1].endian);
	e->text[2].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone2.xpm", &a, &b);
	e->text[2].data = mlx_get_data_addr(e->text[2].img, &e->text[2].bpp, &e->text[2].sizeline, &e->text[2].endian);
	e->text[3].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/stone4.xpm", &a, &b);
	e->text[3].data = mlx_get_data_addr(e->text[3].img, &e->text[3].bpp, &e->text[3].sizeline, &e->text[3].endian);
	e->text[4].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood1.xpm", &a, &b);
	e->text[4].data = mlx_get_data_addr(e->text[4].img, &e->text[4].bpp, &e->text[4].sizeline, &e->text[4].endian);
	e->text[5].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood3.xpm", &a, &b);
	e->text[5].data = mlx_get_data_addr(e->text[5].img, &e->text[5].bpp, &e->text[5].sizeline, &e->text[5].endian);
	e->text[6].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood2.xpm", &a, &b);
	e->text[6].data = mlx_get_data_addr(e->text[6].img, &e->text[6].bpp, &e->text[6].sizeline, &e->text[6].endian);
	e->text[7].img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/wood4.xpm", &a, &b);
	e->text[7].data = mlx_get_data_addr(e->text[7].img, &e->text[7].bpp, &e->text[7].sizeline, &e->text[7].endian);
}

int				texture_init(t_env *e)
{
	int			a;
	int			b;
//	int			i;

//	i = 0;
	a = 250;
	b = 250;
//	while (i <= 8)
///	{
//	e->text[i] = malloc(sizeof(t_text));
//	i++;
//	}
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
(t_env *e, t_pos_d pos, t_pos ray_pos, t_pos coord, t_pos_d rayend)
{
	if (rayend.y >= 0.996 || rayend.y <= 0.004)
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

unsigned int	render_texture(t_env *e, t_pos_d pos, t_pos_d rayend)
{
	t_pos		ray_pos;
	t_pos		coord;
	
	ray_pos.x = (int)rayend.x;
	ray_pos.y = (int)rayend.y;
	rayend.x = rayend.x - ray_pos.x;
	rayend.y = rayend.y - ray_pos.y;
	coord.x = rayend.x * 250;
	coord.y = rayend.y * 250;
	calc_render_texture(e, pos, ray_pos, coord, rayend);
	return (e->color);
}
