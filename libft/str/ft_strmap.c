/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 01:09:10 by alebui            #+#    #+#             */
/*   Updated: 2018/12/18 17:21:35 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*strmap;
	size_t	len;
	size_t	i;

	if (!f || !s)
		return (NULL);
	len = ft_strlen((char *)s);
	if (!(strmap = ft_strnew(len)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		strmap[i] = f(s[i]);
		i++;
	}
	strmap[i] = '\0';
	return (strmap);
}
