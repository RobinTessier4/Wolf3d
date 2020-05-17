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

int			ft_close(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

static void	hook_events(t_env *e)
{
	mlx_hook(e->mlx->wind, 2, (1L << 0), &key_hook, e);
	mlx_hook(e->mlx->wind, 3, (1L << 1), &key_release_hook, e);
	mlx_hook(e->mlx->wind, 17, 0L, ft_close, e);
	mlx_loop(e->mlx->ptr);
}	

/*
static void __attribute__((destructor)) destruct()
{
	while(1);
}
*/

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
					// printf("e.map_width: %d ; e.map_height: %d\n", e.map_width, e.map_height);
					draw_raycasting(&e);
					hook_events(&e);
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
