/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:41:48 by alebui            #+#    #+#             */
/*   Updated: 2018/12/04 16:25:50 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*count;

	i = 0;
	count = NULL;
	if ((char)c == '\0')
		return ((char *)s + ft_strlen((char *)s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			count = (char *)s + i;
		i++;
	}
	return ((char *)count);
}
