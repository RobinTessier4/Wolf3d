/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:35:26 by alebui            #+#    #+#             */
/*   Updated: 2019/01/25 16:39:08 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map;
	t_list *prev;
	t_list *first;

	if (!lst || !f)
		return (NULL);
	prev = NULL;
	first = NULL;
	while (lst)
	{
		map = f(ft_lstnew(lst->content, lst->content_size));
		if (prev != NULL)
			prev->next = map;
		if (first == NULL)
			first = map;
		prev = map;
		lst = lst->next;
	}
	return (first);
}
