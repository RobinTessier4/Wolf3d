/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:36:19 by alebui            #+#    #+#             */
/*   Updated: 2019/01/10 20:25:43 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *after;

	tmp = *alst;
	after = *alst;
	if (!alst || !del)
		return ;
	while (tmp)
	{
		after = tmp->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = after;
	}
	*alst = NULL;
}
