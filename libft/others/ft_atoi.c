/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:33:02 by alebui            #+#    #+#             */
/*   Updated: 2019/01/10 20:23:26 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int						ft_atoi(const char *str)
{
	int					i;
	int					is_neg;
	unsigned long int	nb;

	i = 0;
	is_neg = 0;
	nb = 0;
	while (((str[i] >= 8 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-')
		is_neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (is_neg == 1 && nb > 9223372036854775807)
		return (0);
	else if (is_neg == 0 && nb > 9223372036854775806)
		return (-1);
	if (is_neg == 1)
		return ((int)nb * -1);
	return ((int)nb);
}
