/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 01:00:02 by alebui            #+#    #+#             */
/*   Updated: 2018/12/08 01:08:56 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t i;

	if (s == NULL)
		return ;
	i = 0;
	while (*s && f)
	{
		f(i, s);
		i++;
		s++;
	}
}
