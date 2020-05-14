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

static void	init_ptr(t_env *e)
{
	init_mlx(e);
	param_init(e);
}

int		ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int		text_init(t_env *e)
{
	int a;
	int b;

	a = 64;
	b = 64;
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
	return (0);
}

int			main(int ac, char **av)
{
	t_env	e;
	int 	fd;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			if (ft_read_input(fd, &e) != NULL)
			{
				if ((e.file = map_tab(&e)) != NULL)
				{
					if (HEIGHT < e.map_height || WIDTH < e.map_width)
						return(error_msg("error: window is too small", &e));
					init_ptr(&e);
					print_map(&e);
					printf("e.map_width: %d ; e.map_height: %d\n", e.map_width, e.map_height);
					draw_raycasting(&e);
					mlx_hook(e.mlx->wind, 2, 0, key_hook, &e);
					mlx_hook(e.mlx->wind, 17, 0L, ft_close, &e);
					mlx_loop(e.mlx->ptr);
				}
				else
				{
					ft_putendl("Map is invalid");
					close(fd);
					return (1);
				}
			}
		}
	}
	else
		ft_putendl("Usage : wolf3d [map01/map02/map03]");	
	return (0);
}
