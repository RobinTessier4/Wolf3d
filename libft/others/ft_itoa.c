/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:37:39 by alebui            #+#    #+#             */
/*   Updated: 2018/12/18 14:43:21 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_itoa_len(int n)
{
	size_t		len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*create_str(int n)
{
	char		*new_str;
	size_t		len;

	len = ft_itoa_len(n);
	if (!(new_str = ft_strnew(len)))
		return (NULL);
	return (new_str);
}

static char		*min_int(int n, char *str_itoa, size_t len)
{
	n = 2147483647;
	*str_itoa = '-';
	while (n >= 10)
	{
		str_itoa[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	if (n >= 0 && n < 10)
		str_itoa[len] = n + 48;
	str_itoa[ft_itoa_len(-2147483647 - 1) - 1] = '8';
	return (str_itoa);
}

char			*ft_itoa(int n)
{
	char		*str_itoa;
	size_t		len;

	if (!(str_itoa = create_str(n)))
		return (NULL);
	len = ft_itoa_len(n) - 1;
	if (n == (-2147483647 - 1))
		min_int(n, str_itoa, len);
	else if (n < 0)
	{
		*str_itoa = '-';
		n *= -1;
	}
	while (n >= 10)
	{
		str_itoa[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	if (n >= 0 && n < 10)
		str_itoa[len] = n + 48;
	return (str_itoa);
}
