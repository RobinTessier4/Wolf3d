/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 18:17:19 by alebui            #+#    #+#             */
/*   Updated: 2019/01/10 20:36:01 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char			is_blank(char c)
{
	if (c == 10 || c == 32 || c == 9)
		c = 1;
	else
		c = 0;
	return (c);
}

char				*ft_strtrim(char const *s)
{
	char			*strtrim;
	unsigned int	start;
	unsigned int	blank;
	int				end;
	int				len;

	if (!s)
		return (NULL);
	start = 0;
	blank = 0;
	end = ft_strlen((char *)s) - 1;
	while (s[start] && is_blank(s[start]))
		start++;
	blank = start;
	while (end > 0 && is_blank(s[end]))
	{
		end--;
		blank++;
	}
	len = ft_strlen((char *)s) - blank;
	if (len < 0)
		len = 0;
	if (!(strtrim = ft_strsub(s, start, (size_t)len)))
		return (NULL);
	return (strtrim);
}
