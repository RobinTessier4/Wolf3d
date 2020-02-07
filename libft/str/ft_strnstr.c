/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:57:43 by alebui            #+#    #+#             */
/*   Updated: 2018/12/04 20:11:00 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	char	*it1;
	char	*it2;

	if (!*needle)
		return ((void *)haystack);
	while (n-- && *haystack)
	{
		if (*haystack == *needle)
		{
			i = n;
			it1 = (void *)haystack + 1;
			it2 = (void *)needle + 1;
			while (i-- && *it1 && *it2 && *it1 == *it2)
			{
				++it1;
				++it2;
			}
			if (!*it2)
				return ((void *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
