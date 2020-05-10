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

// check if wall doesn't work 
int			check_if_wall(t_env *e, int i)
{
	t_pos_d 	cur; //cur pour cursor

	cur = e->player;
	if (i == 1)
	{
		cur.y += e->dir_p.y / 10;
		cur.x += e->dir_p.x / 10;
	}
	else if (i == 2)
	{
		cur.y -= e->dir_p.y / 10;
		cur.x -= e->dir_p.x / 10;
	}
	else if (i == 3)
	{
		cur.y -= e->dir_p.x / 10;
		cur.x += e->dir_p.y / 10;
	}
	else if (i == 4)
	{
		cur.y += e->dir_p.x / 10;
		cur.x -= e->dir_p.y / 10;
	}
	if (e->file[(int)cur.y][(int)cur.x] != 0)
		return (1);
	return (0);
}

static void	wasd_key(int key, t_env *e)
{
	if (key == W && e->player.y < HEIGHT && check_if_wall(e, 1) == 0)
	{
		e->player.y += e->dir_p.y / 10;
		e->player.x += e->dir_p.x / 10;
	}
	else if (key == S && e->player.y > 0 && check_if_wall(e, 2) == 0)
	{
		e->player.y -= e->dir_p.y / 10;
		e->player.x -= e->dir_p.x / 10;
	}
	else if (key == A && e->player.x > 0 && check_if_wall(e, 3) == 0)
	{
		e->player.y -= e->dir_p.x / 10;
		e->player.x += e->dir_p.y / 10;
	}
	else if (key == D && e->player.x < WIDTH && check_if_wall(e, 4) == 0)
	{
		e->player.y += e->dir_p.x / 10;
		e->player.x -= e->dir_p.y / 10;
	}
}

static void	rotation_key(int key, t_env *e)
{
	if (key == ARROW_LEFT)
	{
		e->oldx = e->dir_p.x;
		e->dir_p.x = e->dir_p.x * cos(-ROT_SPEED) - e->dir_p.y * sin(-ROT_SPEED);
		e->dir_p.y = e->oldx * sin(-ROT_SPEED) + e->dir_p.y * cos(-ROT_SPEED);
		
		e->oldx = e->plane_p.x;
		
		e->plane_p.x = e->plane_p.x * cos(-ROT_SPEED) - e->plane_p.y * sin(-ROT_SPEED);
		e->plane_p.y = e->oldx * sin(-ROT_SPEED) + e->plane_p.y * cos(-ROT_SPEED);
	}
	else if (key == ARROW_RIGHT)
	{
		e->oldx = e->dir_p.x;
		e->dir_p.x = e->dir_p.x * cos(ROT_SPEED) - e->dir_p.y * sin(ROT_SPEED);
		e->dir_p.y = e->oldx * sin(ROT_SPEED) + e->dir_p.y * cos(ROT_SPEED);
		e->oldx = e->plane_p.x;
		
		e->plane_p.x = e->plane_p.x * cos(ROT_SPEED) - e->plane_p.y * sin(ROT_SPEED);
		e->plane_p.y = e->oldx * sin(ROT_SPEED) + e->plane_p.y * cos(ROT_SPEED);
	}
}

int			key_hook(int key, t_env *e)
{
	if (key == MAIN_PAD_ESC)
	{
		mlx_destroy_image(e->mlx->ptr, e->mlx->img); 
		exit(EXIT_SUCCESS);
	}
	wasd_key(key, e);
	rotation_key(key, e);
	if (key == SPACE_BAR)
	{
		if (e->map == 1)
			e->map = 0;
		else if (e->map == 0)
			e->map = 1;
	}
	if (e->map == 1)
		draw_raycasting(e);
	else if (e->map == 0)
		draw_2D_map(e);
	return (0);
}
