/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:27 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:06:19 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int			**malloc_texture(t_env *e)
{
	int		i;

	i = 0;
	if (!(e->texture_tab = (t_img**)ft_memalloc(sizeof(t_img*) * 9)))
		return (NULL);
	while (i < 8)
	{
		if (!(e->texture_tab[i] = (t_img*)ft_memalloc(sizeof(t_img))))
			return (NULL);
		ft_bzero(e->texture_tab[i], sizeof(t_img));
		i++;
	}
	e->texture_tab[i] = NULL;
	return (0);
}

void		set_texture_stone(t_env *e, int a, int b)
{
	int		i;
	char	*stonepath;

	stonepath = ft_strdup("textures/stone0.xpm");
	i = 0;
	while (i < 4)
	{
		stonepath[14] = (i + 1) + 48;
		e->texture_tab[i]->ptr = mlx_xpm_file_to_image(e->mlx->ptr, stonepath,
				&a, &b);
		e->texture_tab[i]->data = mlx_get_data_addr(e->texture_tab[i]->ptr,
				&e->texture_tab[i]->bpp, &e->texture_tab[i]->s_line,
				&e->texture_tab[i]->endian);
		i++;
	}
	free(stonepath);
	stonepath = NULL;
}

void		set_texture_wood(t_env *e, int a, int b)
{
	int		i;
	char	*woodpath;

	woodpath = ft_strdup("textures/wood0.xpm");
	i = 4;
	while (i < 8)
	{
		woodpath[13] = i + 48 - 3;
		e->texture_tab[i]->ptr = mlx_xpm_file_to_image(e->mlx->ptr, woodpath,
				&a, &b);
		e->texture_tab[i]->data = mlx_get_data_addr(e->texture_tab[i]->ptr,
				&e->texture_tab[i]->bpp, &e->texture_tab[i]->s_line,
				&e->texture_tab[i]->endian);
		i++;
	}
	free(woodpath);
	woodpath = NULL;
}

int			texture_init(t_env *e)
{
	int		a;
	int		b;

	a = 250;
	b = 250;
	malloc_texture(e);
	set_texture_stone(e, a, b);
	set_texture_wood(e, a, b);
	return (0);
}
