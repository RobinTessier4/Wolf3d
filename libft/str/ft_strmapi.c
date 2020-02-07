/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 01:20:34 by alebui            #+#    #+#             */
/*   Updated: 2018/12/18 17:23:48 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
		strmap[i] = f(i, s[i]);
		i++;
	}
	return (strmap);
}
