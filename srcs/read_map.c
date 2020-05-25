/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 07:57:32 by rotessie          #+#    #+#             */
/*   Updated: 2020/01/30 11:27:06 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

static void			tabwidth(char *line, t_env *env)
{
	int				len;
	char			**split;

	len = 0;
	split = ft_strsplit(line, ' ');
	while (split[len])
		len++;
	env->map_width = len;
	ft_tabdel(&split);
}

static	int			check_if_walkable(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] - 48 == 0)
			j = 1;
		if ((str[i] - 48 < 0 || str[i] - 48 > 2) && (str[i] != ' '))
			return (-1);
		i++;
	}
	return (j);
}

static int			str_to_intarray(char *line, t_parse *elem, t_env *env)
{
	char			**split;
	int				i;

	i = 0;
	split = ft_strsplit_multi(line, "\t ");
	while (split[i])
	{
		elem->nums[i] = ft_atoi(split[i]);
		i++;
	}
	env->line_cmp = i;
	ft_tabdel(&split);
	return (0);
}

static int			gnl_reading(int fd, t_env *env)
{
	char			*line;
	t_parse			*elem;
	int				bloc;

	bloc = 0;
	line = NULL;
	while ((env->gnl_ret = get_next_line(fd, &line)) > 0)
	{
		if (check_if_walkable(line) != 0 && bloc != -1)
			bloc = 1;
		if (check_if_walkable(line) == -1)
			bloc = -1;
		if (env->map_height == 0)
			tabwidth(line, env);
		elem = new_elem(env, env->map_width);
		if (str_to_intarray(line, elem, env) == -1)
			return (error_msg("parsing error. Exiting", env));
		if (env->line_cmp != env->map_width)
			return (error_msg("Found wrong line length. Exiting", env));
		env->map_height++;
		ft_strdel(&line);
	}
	if (bloc == -1 || bloc == 0)
		return (-1);
	return (env->gnl_ret);
}

t_parse				*ft_read_input(int fd, t_env *env)
{
	int				ret_read;

	ret_read = 0;
	env->map_height = 0;
	if ((ret_read = gnl_reading(fd, env)) == -1)
	{
		return (NULL);
	}
	else if (env->map_height == 0)
	{
		error_msg("error: empty file", env);
		return (NULL);
	}
	return (env->map_lines);
}
