/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 19:32:13 by alebui            #+#    #+#             */
/*   Updated: 2020/02/04 19:33:35 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void			usage(char *program)
{
	ft_putstr(program);
	ft_putendl(": usage: filename");
}

void			ft_error(void)
{
	ft_putstr("error: ");
	ft_putendl(strerror(errno));
}

int				error_msg(char *message, t_env *env)
{
	if (message && VERBOSE)
		ft_putendl_fd(message, 1);
	if (env->map_lines)
		del_map_lines(&env->map_lines);
	return (1);
}