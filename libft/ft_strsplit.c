/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:52:19 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/07 23:32:28 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nb_word(char *str, char c)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			cpt++;
		i++;
	}
	return (cpt);
}

static int		ft_nb_char(int index_word, char *str, char c)
{
	int	i;
	int	nb_word;
	int nb_char;

	i = 0;
	nb_char = 0;
	nb_word = 0;
	while (str[i])
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			nb_word++;
		i++;
		if ((str[i] != c) && (nb_word + 1 == index_word))
			nb_char++;
	}
	if ((str[0] != c) && (index_word == 1))
		return (nb_char + 1);
	else
		return (nb_char);
}

static int		ft_word_position(int index_word, char *str, char c)
{
	int	i;
	int	nb_word;
	int	word_position;

	word_position = 0;
	i = 0;
	nb_word = 0;
	if ((str[0] != c) && (index_word == 1))
		return (0);
	while (str[i])
	{
		if ((str[i] != c) && (str[i + 1] == c || str[i + 1] == '\0'))
			nb_word++;
		i++;
		if ((str[i] != c) && (nb_word + 1 == index_word))
			word_position = i;
	}
	return (word_position - (ft_nb_char(index_word, str, c) - 1));
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (!s || !(tab = malloc(sizeof(char *) * (ft_nb_word((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_nb_word((char *)s, c))
	{
		if (!(tab[i] = malloc(sizeof(char) *
			(ft_nb_char((i + 1), (char *)s, c) + 1))))
			return (NULL);
		while (j < (ft_nb_char((i + 1), (char *)s, c)))
		{
			tab[i][j] = s[ft_word_position((i + 1), (char *)s, c) + j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
		j = 0;
	}
	tab[i] = 0;
	return (tab);
}
