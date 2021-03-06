/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/13/02 18:22:37 by alebui            #+#    #+#             */
/*   Updated: 2020/13/02 20:20:20 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

t_virtual		init_vector_pos(t_env *e)
{
	t_virtual	tmp;

	tmp.start.x = (e->player.x + e->dir_p.x - e->plane_p.x);
	tmp.start.y = (e->player.y + e->dir_p.y - e->plane_p.y);
	tmp.end.x = (e->player.x + e->dir_p.x + e->plane_p.x);
	tmp.end.y = (e->player.y + e->dir_p.y + e->plane_p.y);
	return (tmp);
}

void			vector_init(t_vector *v)
{
	v->dist.x = abs(v->end.x - v->start.x);
	v->dist.y = abs(v->end.y - v->start.y);
	v->sx = v->start.x < v->end.x ? 1 : -1;
	v->sy = v->start.y < v->end.y ? 1 : -1;
	v->err = (v->dist.x > v->dist.y ? v->dist.x : -v->dist.y) / 2;
}

/*
** 1. init central ray at the player's position : e->dir->start
** 2. intersections points on the plane accordind
**	  the player direction : e->dir->end
** 3. init plane's position : e->plane->start/end
** 4. init left coordinates of the plane : e->lray->start/end
** 5. init right coordinates of the plane : e->rray->start/end
*/

void			ray_init(t_env *e)
{
	e->dir->start.x = e->player.x * e->bloc_width;
	e->dir->start.y = e->player.y * e->bloc_height;
	e->dir->end.x = (e->player.x + e->dir_p.x) * e->bloc_width;
	e->dir->end.y = (e->player.y + e->dir_p.y) * e->bloc_height;
	e->plane->start.x = (e->player.x + e->dir_p.x - e->plane_p.x)
		* e->bloc_width;
	e->plane->start.y = (e->player.y + e->dir_p.y - e->plane_p.y)
		* e->bloc_height;
	e->plane->end.x = (e->player.x + e->dir_p.x + e->plane_p.x)
		* e->bloc_width;
	e->plane->end.y = (e->player.y + e->dir_p.y + e->plane_p.y)
		* e->bloc_height;
	e->lray->start.x = e->dir->start.x;
	e->lray->start.y = e->dir->start.y;
	e->lray->end.x = e->plane->start.x;
	e->lray->end.y = e->plane->start.y;
	e->rray->start.x = e->dir->start.x;
	e->rray->start.y = e->dir->start.y;
	e->rray->end.x = e->plane->end.x;
	e->rray->end.y = e->plane->end.y;
}

void			draw_rayons(t_env *e, t_vector *tmp)
{
	int			err;

	while (tmp->start.x != tmp->end.x || tmp->start.y != tmp->end.y)
	{
		e->lray->start.x = e->player.x * e->bloc_width;
		e->lray->start.y = e->player.y * e->bloc_height;
		e->lray->end = tmp->start;
		vector_init(e->lray);
		render_player_fov(e, e->lray);
		err = tmp->err;
		if (err > -tmp->dist.x)
		{
			tmp->err -= tmp->dist.y;
			tmp->start.x += tmp->sx;
		}
		if (err < tmp->dist.y)
		{
			tmp->err += tmp->dist.x;
			tmp->start.y += tmp->sy;
		}
	}
}

void			draw_vector(t_env *e)
{
	t_vector	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_vector))))
		return ;
	ray_init(e);
	vector_init(e->dir);
	vector_init(e->plane);
	vector_init(e->rray);
	vector_init(e->lray);
	tmp->start = e->plane->start;
	tmp->end = e->plane->end;
	vector_init(tmp);
	draw_rayons(e, tmp);
	free(tmp);
}
