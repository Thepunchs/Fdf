/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:12:10 by alefebvr          #+#    #+#             */
/*   Updated: 2018/02/14 16:04:13 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i - 1] != c)
			words++;
	}
	return (words);
}

static int	count_letters(char const *s, char c, int word)
{
	int i;
	int letters;
	int j;

	j = 0;
	letters = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (j != word)
			while (s[i] != c && s[i] != '\0')
				i++;
		else
		{
			while (s[i++] != c && s[i] != '\0')
				letters++;
			break ;
		}
		j++;
	}
	return (letters);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**fraiches;
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	if ((fraiches = ft_memalloc(sizeof(char*) *
					(count_words(s, c) + 1))) == NULL)
		return (NULL);
	fraiches[count_words(s, c)] = 0;
	while (j < count_words(s, c))
	{
		fraiches[j] = ft_memalloc(sizeof(char) * count_letters(s, c, j) + 1);
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
			fraiches[j][k++] = s[i++];
		k = 0;
		j++;
	}
	return (fraiches);
}
