/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 18:47:16 by alebui            #+#    #+#             */
/*   Updated: 2019/01/04 14:38:57 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d2;
	char	*s2;

	d2 = (char *)dst;
	s2 = (char *)src;
	if (dst == src)
		return (dst);
	if (src < dst)
		while (len--)
			d2[len] = s2[len];
	else
		while (len--)
			*d2++ = *s2++;
	return (dst);
}
