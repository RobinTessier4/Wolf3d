/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:37:39 by alebui            #+#    #+#             */
/*   Updated: 2018/12/18 14:43:21 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

float	ft_power(float number, int pow)
{
	int			i;
	float		ret;

	i = 1;
	ret = number;
	while (i < pow)
	{
		ret *= number;
		i++;
	}
	return (ret);
}
