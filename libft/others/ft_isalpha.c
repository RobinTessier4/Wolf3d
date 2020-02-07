/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 23:13:54 by alebui            #+#    #+#             */
/*   Updated: 2018/12/04 23:38:44 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	int ret;

	ret = (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) ? 1 : 0);
	return (ret);
}
