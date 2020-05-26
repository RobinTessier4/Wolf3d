/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:06:31 by rotessie          #+#    #+#             */
/*   Updated: 2020/01/13 08:40:02 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static int			malloc_tab(t_env *env, t_parse *elem, int len)
{
	if (!(elem->nums = (int *)malloc(sizeof(int) * len)))
		return (error_msg("error while malloc tab in chained list", env));
	return (0);
}

t_parse				*new_elem(t_env *env, int len)
{
	t_parse			*elem;
	t_parse			*prev;

	elem = env->map_lines;
	while (elem)
	{
		prev = elem;
		elem = elem->next;
	}
	if (!(elem = ((t_parse *)malloc(sizeof(t_parse)))))
	{
		error_msg("error while malloc element of chained list", env);
		return (NULL);
	}
	if (env->map_lines)
		prev->next = elem;
	else
		env->map_lines = elem;
	if (malloc_tab(env, elem, len) == -1)
		return (NULL);
	ft_bzero(elem->nums, (sizeof(int) * len));
	elem->next = NULL;
	return (elem);
}

int					check_if_walkable(t_env *e, int **tab)
{
	int				i;
	int				j;
	int				walkable;

	i = 0;
	walkable = -1;
	while (i < e->map_height)
	{
		j = 0;
		while (j < e->map_width)
		{
			if (tab[i][j] == 0)
				walkable = 1;
			else if (tab[i][j] < 0 || tab[i][j] > 2)
				return (-1);
			j++;
		}
		i++;
	}
	return (walkable);
}

int					**map_tab(t_env *e)
{
	int				**tab;
	t_parse			*elem;
	int				i;
	int				j;

	elem = e->map_lines;
	i = 0;
	if (!(tab = (int**)(malloc(sizeof(int*) * e->map_height))))
		return (NULL);
	while (elem)
	{
		if (!(tab[i] = (int *)(malloc(sizeof(int) * e->map_width))))
			return (NULL);
		j = -1;
		while (++j < e->map_width)
			tab[i][j] = elem->nums[j];
		i++;
		elem = elem->next;
	}
	clean_map_lines(&e->map_lines);
	if (check_if_walkable(e, tab) != 1)
		return (NULL);
	return (tab);
}
