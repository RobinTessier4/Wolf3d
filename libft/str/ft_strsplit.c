/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:52:16 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 17:04:20 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			count_words(char const *str, char c)
{
	int				nb_words;
	int				is_word;

	is_word = 0;
	nb_words = 0;
	while (*str)
	{
		if (*str == c)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			nb_words++;
		}
		str++;
	}
	return (nb_words);
}

static int			str_len(char const *s, int i, char c)
{
	unsigned int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char			**free_all_tab(char **tab)
{
	ft_tabdel(&tab);
	return (NULL);
}

static void			go_on_reading(unsigned int *i, char const *s, char c)
{
	while (s[*i] == c)
		(*i)++;
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tmp;
	char			**tab;
	unsigned int	i;
	int				count;
	int				nb_words;

	if (!s || !c)
		return (NULL);
	nb_words = count_words(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	tmp = tab;
	i = 0;
	go_on_reading(&i, s, c);
	while (s[i])
	{
		count = str_len(s, i, c);
		if (!(*tab = ft_strsub(s, i, count)))
			free_all_tab(tab);
		tab++;
		i += count;
		go_on_reading(&i, s, c);
	}
	*tab = NULL;
	return (tmp);
}
