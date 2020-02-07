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
	t_parse	*tmp;
	t_parse	*next;

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

/*
char		*ft_read(int fd) // refaire le parseur avec get_next_line()
{
	char	*str;
	char	buffer[129];
	int		ret;
	char	*tmp;
	int		i; // variable i non utlisée

	i = 0;
	str = ft_strnew(0);
	while ((ret = read(fd, buffer, 128)) > 0)
	{
		buffer[ret] = '\0';
		tmp = str;
		if (!(str = ft_strjoin(str, buffer)))
			return (NULL);
		free(tmp);
		i++;
	}
	return (str);
}

int			count_col(char *str) // mettre en statique
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (ft_isdigit(str[i]) == 0 && str[i] != '-' && str[i] != '+')
		return (-1);
	while (str[i])
	{
		if (str[i] != ' ' && ft_isdigit(str[i] == 0) && str[i] != '-' &&
				str[i] != '+')
			return (-1);
		if (str[i] == ' ')
		{
			count++;
			while (str[i] == ' ')
				i++;
		}
		if (str[i] != '\0')
			i++;
	}
	count++;
	return (count);
}

void		free_char_tab(char **tab) // ft_tabdel + mettre en statique
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int			check_endline(char *str) // mettre en statique
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			if (str[i + 1] == '\n')
				return (-1);
		i++;
	}
	return (0);
}

int			check_error(char *str, t_env *e)
{
	int		i;
	int		count;
	int		temp;
	char	**tab;

	count = 0;
	i = 0;
	temp = 0;
	if (!(tab = ft_strsplit(str, '\n')))
		return (1);
	if (tab[i] == NULL || check_endline(str) == -1)
		return (1);
	e->col = count_col(tab[i]);
	while (tab[i])
	{
		count = count_col(tab[i]);
		if (count == -1 || (count != temp && temp != 0))
		{
			free_char_tab(tab);
			return (1);
		}
		temp = count;
		i++;
	}
	e->rows = i;
	e->tab = make_tab(e, str);
	free_char_tab(tab);
	return (0);
}
*/