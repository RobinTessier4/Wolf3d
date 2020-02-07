/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 00:04:52 by alebui            #+#    #+#             */
/*   Updated: 2018/12/18 17:22:59 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*strnew;
	size_t	i;

	if (!(strnew = (char *)malloc((sizeof(char) * (size + 1)))))
		return (NULL);
	i = 0;
	while (i <= size)
	{
		strnew[i] = '\0';
		i++;
	}
	return (strnew);
}
