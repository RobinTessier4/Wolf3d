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

void				del_map_lines(t_parse **lst)
{
	t_parse			*tmp;
	t_parse			*next;

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

static int			malloc_tab(t_env *env, t_parse *elem, int len)
{
	if (!(elem->nums = (int *)(malloc)(sizeof(int) * len)))
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
	del_map_lines(&e->map_lines);
	return (tab);
}
