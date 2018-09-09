/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:37:42 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/19 20:56:59 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_final_spaces(char const *s)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[--i] == ' ' || s[i] == '\n' || s[i] == '\t')
		b++;
	return (b);
}

char			*ft_strtrim(char const *s)
{
	char	*fraiche;
	int		i;
	int		j;
	int		final_spaces;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	final_spaces = ft_count_final_spaces(s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	fraiche = malloc(sizeof(char) * ft_strlen(s) - i - final_spaces + 1);
	if (s[i] == '\0')
		return (ft_strdup(""));
	if (fraiche == NULL)
		return (NULL);
	while (s[i] != '\0')
		fraiche[j++] = s[i++];
	fraiche[j - final_spaces] = '\0';
	return (fraiche);
}
