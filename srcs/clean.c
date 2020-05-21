/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <alebui@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:20:43 by alebui            #+#    #+#             */
/*   Updated: 2020/02/05 15:06:29 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void	clean_file(t_env *e)
{
	int		i;

	i = 0;
	if (e->file)
	{
		while (i < e->map_height)
		{
			free(e->file[i]);
			e->file[i] = NULL;
			i++;
		}
		free(e->file);
		e->file = NULL;
	}
}

static void	clean_map_lines(t_env *e)
{
	if (e->map_lines)
	{
		while (e->map_lines)
		{
			free(e->map_lines->nums);
			e->map_lines->nums = NULL;
			e->map_lines = e->map_lines->next;
		}
	}
}

static void	clean_text(t_env *e)
{
 	int		i;

 	i = 0;
 	while (e->texture_tab[i])
 	{
 		if (e->texture_tab[i]->ptr)
 		{
 			free(e->texture_tab[i]->ptr);
 			e->texture_tab[i]->ptr = NULL;
 		}
 		if (e->texture_tab[i]->data)
 		{
 			free(e->texture_tab[i]->data);
 			e->texture_tab[i]->data = NULL;
 		}
		if (e->texture_tab[i])
		{
		free(e->texture_tab[i]);
		e->texture_tab[i] = NULL;
		}
 		i++;
 	}
	free(e->texture_tab);
	e->texture_tab = NULL;
}

static void	clean_vector(t_env *e)
{
	if (e->dir)
	{
		free(e->dir);
		e->dir = NULL;
	}
	if (e->plane)
	{
		free(e->plane);
		e->plane = NULL;
	}
	if (e->lray)
	{
		free(e->lray);
		e->lray = NULL;
	}
	if (e->rray)
	{
		free(e->rray);
		e->rray = NULL;
	}
}

void		exit_program(t_env *e)
{
	clean_text(e);
	clean_file(e);
	clean_map_lines(e);
	clean_vector(e);
	mlx_destroy(e->mlx);
exit(EXIT_SUCCESS);
}
