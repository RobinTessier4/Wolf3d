/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:21:26 by alebui            #+#    #+#             */
/*   Updated: 2019/01/10 20:27:51 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list		*ft_lstdup(t_list *lst)
{
	t_list	*dup;
	t_list	*tmp;
	t_list	*first;

	if (!lst)
		return (NULL);
	dup = ft_lstnew(lst->content, lst->content_size);
	first = dup;
	while (lst)
	{
		tmp = dup;
		lst = lst->next;
		if (!lst)
			dup = NULL;
		else
			dup = ft_lstnew(lst->content, lst->content_size);
		tmp->next = dup;
	}
	return (first);
}
