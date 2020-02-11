/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:34:59 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:06:53 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

int		check_if_wall(t_env *e, int i)
{
	if (e && i)
		printf("je check\n");
	printf("je check\n");
	/*
	int x;
	int y;

	x = e->player.x * e->bloc_width;
	y = e->player.y * e->bloc_height;
//	if (e->dir->x == 1)
//		y -= 2;
	if (i == 2)
		y += 2;
	else if (i == 3)
		x -= 2;
	else if (i == 4)
		x += 2;
	e->current_bloc.x = x / e->bloc_width;
	e->current_bloc.y = y / e->bloc_height;
	if (e->current_bloc.y <= e->rows && e->current_bloc.x <= e->col)
	{
		if (e->file[e->current_bloc.y][e->current_bloc.x] != 0)
			return (1);
	}
	*/
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (e)
		printf("key_hook\n");
	if (key == MAIN_PAD_ESC)
	{
		// mlx_destroy_image(e->mlx, e->ptr); 
		exit(EXIT_SUCCESS);
	}
	if (key == W && e->player.y < HEIGHT && check_if_wall(e, 1) == 0)
	{
		e->player.y += e->dir_p.y / 10;
		e->player.x += e->dir_p.x / 10;
	}
	if (key == S && e->player.y > 0 && check_if_wall(e, 2) == 0)
	{
		e->player.y -= e->dir_p.y / 10;
		e->player.x -= e->dir_p.x / 10;
	}
	if (key == A && e->player.x > 0 && check_if_wall(e, 3) == 0)
	{
		e->player.y -= e->dir_p.x / 10;
		e->player.x += e->dir_p.y / 10;
	}
	if (key == D && e->player.x < WIDTH && check_if_wall(e, 4) == 0)
	{
		e->player.y += e->dir_p.x / 10;
		e->player.x -= e->dir_p.y / 10;
	}
	if (key == ARROW_LEFT)
	{
		e->oldx = e->dir_p.x;
		e->dir_p.x = e->dir_p.x * cos(-0.05) - e->dir_p.y * sin(-0.05);
		e->dir_p.y = e->oldx * sin(-0.05) + e->dir_p.y * cos(-0.05);
		e->oldx = e->plane_p.x;
		e->plane_p.x = e->plane_p.x * cos(-0.05) - e->plane_p.y * sin(-0.05);
		e->plane_p.y = e->oldx * sin(-0.05) + e->plane_p.y * cos(-0.05);
	}
	if (key == ARROW_RIGHT)
	{
		e->oldx = e->dir_p.x;
		e->dir_p.x = e->dir_p.x * cos(0.05) - e->dir_p.y * sin(0.05);
		e->dir_p.y = e->oldx * sin(0.05) + e->dir_p.y * cos(0.05);
		e->oldx = e->plane_p.x;
		e->plane_p.x = e->plane_p.x * cos(0.05) - e->plane_p.y * sin(0.05);
		e->plane_p.y = e->oldx * sin(0.05) + e->plane_p.y * cos(0.05);
	}
	// mlx_destroy_image(e->mlx, e->ptr);
	wolf(e);
	return (0);
}
