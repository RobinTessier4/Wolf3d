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

static int	ft_close(void)
{
	printf("JE QUITTE\n");
	exit(EXIT_SUCCESS);
	return (0);
}

static void	hook_events(t_env *e)
{
	mlx_hook(e->mlx->wind, 2, (1L << 0), &key_hook, e);
	mlx_hook(e->mlx->wind, 17, 0L, ft_close, e);
	mlx_loop(e->mlx->ptr);
}

/*
** __attribute__((destructor)) void loop_inf(void){ for(;;); }
*/

static void	run_app(t_env *e)
{
	if (HEIGHT < e->map_height || WIDTH < e->map_width)
		v_error_msg("error: window is too small", e);
	else
	{
		init_ptr(e);
		print_map(e);
		draw_raycasting(e);
		hook_events(e);
	}
}

int			main(int ac, char **av)
{
	t_env	e;
	int		fd;

	if (ac != 2)
		usage();
	else if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) > 0)
		{
			if (ft_read_input(fd, &e) != NULL)
			{
				if ((e.file = map_tab(&e)) != NULL)
					run_app(&e);
				else
				{
					ft_putendl("Map is invalid");
					close(fd);
					return (1);
				}
			}
		}
		usage();
	}
	return (0);
}
