/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 11:23:08 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 14:16:47 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				**ft_tabsub(char **tab, unsigned int start, size_t len)
{
	char			**tabnew;
	unsigned int	i;
	unsigned int	j;

	if (!tab || !(tabnew = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	i = 0;
	j = start;
	while (i < len && tab[j])
	{
		if (!(tabnew[i] = ft_strdup(tab[j])))
		{
			ft_tabdel(&tabnew);
			return (NULL);
		}
		i++;
		j++;
	}
	while (i <= len)
	{
		tabnew[i] = NULL;
		i++;
	}
	return (tabnew);
}
