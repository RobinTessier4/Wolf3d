/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:05:06 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 14:02:16 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		**ft_tabdup(char **tab)
{
	char	**dup_tab;
	int		tab_len;
	int		i;

	tab_len = ft_tablen(tab);
	if (!tab || !(dup_tab = (char **)malloc(sizeof(char *) * (tab_len + 1))))
		return (NULL);
	i = 0;
	while (i < tab_len)
	{
		if (!(dup_tab[i] = ft_strdup(tab[i])))
		{
			ft_tabdel(&tab);
			return (NULL);
		}
		i++;
	}
	dup_tab[i] = NULL;
	return (dup_tab);
}
