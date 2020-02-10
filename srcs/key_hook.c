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

	x = e->x * e->bloc_width;
	y = e->y * e->bloc_height;
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
		if (e->tab[e->current_bloc.y][e->current_bloc.x] != 0)
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
	if (key == W && e->y < HEIGHT && check_if_wall(e, 1) == 0)
	{
		e->y += e->ydir / 10;
		e->x += e->xdir / 10;
	}
	if (key == S && e->y > 0 && check_if_wall(e, 2) == 0)
	{
		e->y -= e->ydir / 10;
		e->x -= e->xdir / 10;
	}
	if (key == A && e->x > 0 && check_if_wall(e, 3) == 0)
	{
		e->y -= e->xdir / 10;
		e->x += e->ydir / 10;
	}
	if (key == D && e->x < WIDTH && check_if_wall(e, 4) == 0)
	{
		e->y += e->xdir / 10;
		e->x -= e->ydir / 10;
	}
	if (key == ARROW_LEFT)
	{
		e->oldx = e->xdir;
		e->xdir = e->xdir * cos(-0.05) - e->ydir * sin(-0.05);
		e->ydir = e->oldx * sin(-0.05) + e->ydir * cos(-0.05);
		e->oldx = e->xplane;
		e->xplane = e->xplane * cos(-0.05) - e->yplane * sin(-0.05);
		e->yplane = e->oldx * sin(-0.05) + e->yplane * cos(-0.05);
	}
	if (key == ARROW_RIGHT)
	{
		e->oldx = e->xdir;
		e->xdir = e->xdir * cos(0.05) - e->ydir * sin(0.05);
		e->ydir = e->oldx * sin(0.05) + e->ydir * cos(0.05);
		e->oldx = e->xplane;
		e->xplane = e->xplane * cos(0.05) - e->yplane * sin(0.05);
		e->yplane = e->oldx * sin(0.05) + e->yplane * cos(0.05);
	}
	// mlx_destroy_image(e->mlx, e->ptr);
	wolf(e);
	return (0);
}
