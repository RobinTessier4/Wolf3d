/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotessie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:07:27 by rotessie          #+#    #+#             */
/*   Updated: 2020/02/05 15:06:19 by rotessie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wolf3d.h>

void	calc_line(int e2, t_vector *v)
{
	if (e2 > -v->dist.x)
	{
		v->err -= v->dist.y;
		v->start.x += v->sx;
	}
	if (e2 < v->dist.y)
	{
		v->err += v->dist.x;
		v->start.y += v->sy;
	}
}
