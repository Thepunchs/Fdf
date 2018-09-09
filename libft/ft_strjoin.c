/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:16:42 by alefebvr          #+#    #+#             */
/*   Updated: 2018/01/15 15:02:54 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fraiche;
	int		k;
	int		l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	k = ft_strlen(s1);
	l = ft_strlen(s2);
	fraiche = malloc(sizeof(char) * (k + l) + 1);
	if (fraiche == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		fraiche[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		fraiche[i++] = s2[j++];
	fraiche[i] = '\0';
	return (fraiche);
}
