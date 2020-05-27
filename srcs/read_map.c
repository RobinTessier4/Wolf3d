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

static int			str_to_intarray(char *line, t_parse *elem, t_env *env)
{
	char			**split;
	int				i;
	int				j;

	i = 0;
	if (!(split = ft_strsplit_multi(line, "\t ")))
		exit_program(1, "error: could not split array", env);
	if ((int)ft_tablen(split) != env->map_width)
	{
		ft_tabdel(&split);
		exit_program(1, "Incorrect map width. Exiting.", env);
	}
	i = 0;
	i = 0;
	while (split[i])
	{
		if ((int)ft_strlen(split[i]) > 1)
		{
			j = 0;
			while (j < (int)ft_strlen(split[i]))
			{
				if (split[i][j] >= 48 && split[i][j] <= 57)
				{
					elem->nums[i] = ft_atoi(&split[i][j]);
					break ;
				}
				if (j == (int)ft_strlen(split[i]) - 2)
					exit_program(1, "QUE DES LETTRES. Exiting.", env);
				j++;
			}
		}
		else
			elem->nums[i] = ft_atoi(&split[i][j]);
		i++;
	}
	ft_tabdel(&split);
	return (0);
}

static int			gnl_reading(int fd, t_env *env)
{
	char			*line;
	t_parse			*elem;
	int				ret;
	int				bloc;

	bloc = 0;
	line = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (env->map_height == 0)
			tabwidth(line, env);
		elem = new_elem(env, env->map_width);
		if (str_to_intarray(line, elem, env) == -1)
			return (error_msg("parsing error. Exiting", env));
		env->map_height++;
		ft_strdel(&line);
	}
	return (ret);
}

t_parse				*ft_read_input(int fd, t_env *env)
{
	int				ret_read;

	ret_read = 0;
	env->map_height = 0;
	if ((ret_read = gnl_reading(fd, env)) == -1)
	{
		error_msg("error: empty file", env);
		return (NULL);
	}
	else if (env->map_height == 0)
	{
		error_msg("error: empty file", env);
		return (NULL);
	}
	return (env->map_lines);
}
