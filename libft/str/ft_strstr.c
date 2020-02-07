/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:05:17 by alebui            #+#    #+#             */
/*   Updated: 2018/12/04 23:52:03 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*s1;
	char	*s2;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			s1 = (char *)haystack + 1;
			s2 = (char *)needle + 1;
			while (*s1 && *s2 && *s1 == *s2)
			{
				++s1;
				++s2;
			}
			if (!*s2)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
