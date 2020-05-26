/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_multi.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebui <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:52:16 by alebui            #+#    #+#             */
/*   Updated: 2019/01/14 17:04:20 by alebui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int			found_word(char const *str, char *split, int found, int j)
{
	found = 0;
	while (split[++j])
	{
		if (split[j] == *str)
		{
			found = 1;
			break ;
		}
	}
	return (found);
}

static int			count_words(char const *str, char *split)
{
	int				nb_words;
	int				is_word;
	char			found;
	int				j;

	is_word = 0;
	nb_words = 0;
	while (*str)
	{
		j = -1;
		found = found_word(str, split, found, j);
		if (found == 1)
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

static int			str_len(char const *s, int i, char *split)
{
	char			found;
	int				j;
	unsigned int	len;

	len = 0;
	while (s[i] != '\0')
	{
		j = -1;
		found = 0;
		while (split[++j])
		{
			if (split[j] == s[i])
			{
				found = 1;
				break ;
			}
		}
		if (found == 1)
			break ;
		len++;
		i++;
	}
	return (len);
}

static void			go_on_reading(unsigned int *i, char const *str, char *split)
{
	char			found;
	int				j;

	while (str[*i])
	{
		found = 0;
		j = -1;
		while (split[++j])
		{
			if (split[j] == str[*i])
			{
				found = 1;
				break ;
			}
		}
		if (found == 0)
			break ;
		(*i)++;
	}
}

char				**ft_strsplit_multi(char const *str, char *split)
{
	char			**tmp;
	char			**tab;
	unsigned int	i;
	int				count;
	int				nb_words;

	if (!str || !split)
		return (NULL);
	nb_words = count_words(str, split);
	if (!(tab = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	tmp = tab;
	i = 0;
	go_on_reading(&i, str, split);
	while (str[i])
	{
		count = str_len(str, i, split);
		if (!(*tab = ft_strsub(str, i, count)))
		{
			ft_tabdel(&tab);
			tab = tmp;
			break ;
		}
		tab++;
		i += count;
		go_on_reading(&i, str, split);
	}
	*tab = NULL;
	return (tmp);
}
