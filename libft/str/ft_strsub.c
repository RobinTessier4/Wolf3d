/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:30:13 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 14:04:07 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*newstr;

	if (!s || !(newstr = ft_strnew(len)))
		return (NULL);
	i = start;
	j = 0;
	while (j < len)
	{
		newstr[j] = s[i];
		i++;
		j++;
	}
	return (newstr);
}
