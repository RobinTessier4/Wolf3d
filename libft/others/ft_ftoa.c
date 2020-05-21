/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:37:39 by alebui            #+#    #+#             */
/*   Updated: 2018/12/18 14:43:21 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		reverse(char *str, int len)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

int			afterfloat_to_str(int x, char *str, int d)
{
	int		i;

	i = 0;
	while (x)
	{
		str[i++] = (x % 10) + '0';
		x = x / 10;
	}
	while (i < d)
		str[i++] = '0';
	reverse(str, i);
	str[i] = '\0';
	return (i);
}

char		*ft_ftoa(float n, char *res, int afterpoint)
{
	int		ipart;
	float	fpart;
	int		i;
	char	neg;
	char	*ret;

	neg = (n < 0) ? 'n' : 'p';
	ipart = abs((int)n);
	if (afterpoint == 0)
		return (ret = ft_itoa(ipart));
	fpart = n - (float)ipart;
	i = afterfloat_to_str(ipart, res, 0);
	if (afterpoint == 0)
		return (NULL);
	res[i] = '.';
	fpart = fpart * ft_power((float)10, afterpoint);
	afterfloat_to_str(abs((int)fpart), res + i + 1, afterpoint);
	ret = ft_itoa(ipart);
	ret = ft_strjoin_free2(res, &ret);
	if (ipart == 0)
		ret = ft_strjoin_free2("0", &ret);
	if (neg == 'n')
		ret = ft_strjoin_free2("-", &ret);
	ft_strdel(&res);
	return (ret);
}
