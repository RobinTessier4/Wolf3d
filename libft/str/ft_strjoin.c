/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 22:26:07 by alebui            #+#    #+#             */
/*   Updated: 2019/02/17 23:39:18 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*strjoin;

	if (!s1 && !s2)
		return (NULL);
	len = 0;
	if (s1)
		len += ft_strlen((char *)s1);
	if (s2)
		len += ft_strlen((char *)s2);
	if (!(strjoin = ft_strnew(len)))
		return (NULL);
	if (s1)
		strjoin = ft_strcpy(strjoin, s1);
	if (s2)
		strjoin = ft_strcat(strjoin, s2);
	return (strjoin);
}
