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

int		text_test(t_env *e)
{
	int a;
	int b;
	t_text *text;
//	void	*img;
	a = 64;
	b = 64;

	if (!(text = ft_memalloc(sizeof(t_text))))
		return (1);
	if (!(text->data = ft_memalloc(sizeof(char) * 100000)))
		return (1);
	printf("check\n");
	text->img = mlx_xpm_file_to_image(e->mlx->ptr, "textures/colorstone.xpm", &a, &b);
	printf("check\n");
	text->data = mlx_get_data_addr(text->img, &text->bpp, &text->sizeline, &text->endian);
	e->text = text;
	printf("bpp = %d\n", e->text->bpp);
	printf("sizeline = %d\n", e->text->sizeline);
	printf("endian = %d\n", e->text->endian);
	printf("str = %s\n", e->text->data);

//e->text->data[x + (y * e->text->bpp)];

	return (0);
}

int			main(int ac, char **av)
{
	t_env	*e;
	int 	fd;

	e = ft_memalloc(sizeof(t_env));
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			if (ft_read_input(fd, e) != NULL)
			{
				if ((e->file = map_tab(e)) != NULL)
				{
					if (HEIGHT < e->map_height || WIDTH < e->map_width)
						return(error_msg("error: window is too small", e));
					init_ptr(e);
					text_test(e);
					print_map(e);
					printf("e.map_width: %d ; e.map_height: %d\n", e->map_width, e->map_height);
					draw_raycasting(e);
					mlx_hook(e->mlx->wind, 2, 0, key_hook, e);
					mlx_mouse_hook(e->mlx->wind, mouse_hook, e);
					mlx_loop(e->mlx->ptr);
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
