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

void	        vector_init(t_env *e, t_vector *v)
{
    (void)e;
	v->dist.x = abs(v->end.x - v->start.x);
	v->dist.y = abs(v->end.y - v->start.y);
	v->sx = v->start.x < v->end.x ? 1 : -1;
	v->sy = v->start.y < v->end.y ? 1 : -1;
	v->err = (v->dist.x > v->dist.y ? v->dist.x : -v->dist.y) / 2;
}

void	        ray_init(t_env *e)
{
    /* init central ray at the player's position */
	e->dir->start.x = e->player.x * e->bloc_width;
	e->dir->start.y = e->player.y * e->bloc_height;
    
    /* Point de passage du rayon sur le plane en fonction de la direction joueur */
	e->dir->end.x = (e->player.x + e->dir_p.x) * e->bloc_width;
	e->dir->end.y = (e->player.y + e->dir_p.y) * e->bloc_height;

    /* init position of the plane */
	e->plane->start.x = (e->player.x + e->dir_p.x - e->plane_p.x) * e->bloc_width;
	e->plane->start.y = (e->player.y + e->dir_p.y - e->plane_p.y) * e->bloc_height;
	e->plane->end.x = (e->player.x + e->dir_p.x + e->plane_p.x) * e->bloc_width;
	e->plane->end.y = (e->player.y + e->dir_p.y + e->plane_p.y) * e->bloc_height;

    /* init left ray */
	e->lray->start.x = e->dir->start.x;
	e->lray->start.y = e->dir->start.y;
	e->lray->end.x = e->plane->start.x;
	e->lray->end.y = e->plane->start.y;
    
    /* init right ray */	
    e->rray->start.x = e->dir->start.x;
	e->rray->start.y = e->dir->start.y;
	e->rray->end.x = e->plane->end.x;
	e->rray->end.y = e->plane->end.y;
}

void	        draw_rayons(t_env *e, t_vector *tmp)
{
	int		    err;

	while (tmp->start.x != tmp->end.x || tmp->start.y != tmp->end.y)
	{
		// TODO : incrementer lray->end.x && lray->end.y pour aller de gauche a droite
		// lray->end par de plane->start et doit aller vers plane->end
		e->lray->start.x = e->player.x * e->bloc_width;
		e->lray->start.y = e->player.y * e->bloc_height;
		e->lray->end = tmp->start;
		vector_init(e, e->lray);
		draw_inf_line(e, e->lray, 1);
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

void	        draw_vector(t_env *e)
{
	t_vector	*tmp; //copie de plane

	if (!(tmp = ft_memalloc(sizeof(t_vector))))
		return ;
	e->leftray = 0;
	e->rightray = 0;
	e->midray = 0;
	ray_init(e);
	vector_init(e, e->dir);
	vector_init(e, e->plane);
	vector_init(e, e->rray);
	vector_init(e, e->lray);
	draw_inf_line(e, e->dir, 3);
	
    /* initialisation de tmp avant de draw plane */
	tmp->start = e->plane->start;
	tmp->end = e->plane->end;
	vector_init(e, tmp);
	
    draw_line(e, e->plane);
	draw_inf_line(e, e->lray, 1);
	draw_inf_line(e, e->rray, 2);

	draw_rayons(e, tmp);
	free(tmp);
}