/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:18:08 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 16:45:40 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstfind(t_list *lst, void *ptr, size_t len)
{
	if (!lst || !ptr)
		return (NULL);
	while (lst)
	{
		if (!ft_memcmp(lst->content, ptr, len))
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
