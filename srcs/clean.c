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
			if (e->file[i])
			{
				free(e->file[i]);
				e->file[i] = NULL;
			}
			i++;
		}
		free(e->file);
		e->file = NULL;
	}
}

void		clean_map_lines(t_parse **lst)
{
	t_parse	*tmp;
	t_parse	*next;

	if (*lst)
	{
		tmp = *lst;
		if (!tmp)
			return ;
		while (tmp)
		{
			next = tmp->next;
			free(tmp->nums);
			ft_memdel((void **)&tmp);
			tmp = next;
		}
		*lst = NULL;
	}
}

static void	clean_text(t_env *e)
{
	int		i;

	i = 0;
	if (e->texture_tab)
	{
		while (e->texture_tab[i])
		{
			mlx_destroy_image(e->mlx->ptr, e->texture_tab[i]->ptr);
			e->texture_tab[i]->data = NULL;
			free(e->texture_tab[i]);
			i++;
		}
		free(e->texture_tab);
	}
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

void		exit_program(int ret, char *msg, t_env *e)
{
	ft_putendl(msg);
	clean_file(e);
	clean_map_lines(&e->map_lines);
	clean_vector(e);
	clean_text(e);
	if (e->mlx)
		mlx_destroy(e->mlx);
	if (e->file_descriptor != 0)
	{
		close(e->file_descriptor);
		e->file_descriptor = 0;
	}
	exit(ret);
}
