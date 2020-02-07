/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 22:59:00 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 18:36:25 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] != '\0' && i < n &&
			((unsigned char)s1[i] == (unsigned char)s2[i]))
		i++;
	if (i == n && i > 0)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
