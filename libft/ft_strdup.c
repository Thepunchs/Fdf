/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:21:14 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/16 19:20:18 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*tab;
	int		len;

	len = 0;
	i = 0;
	while (s1[len] != '\0')
		len++;
	if (!(tab = (char *)malloc(sizeof(*tab) * len + 1)))
		return (NULL);
	while (i < len)
	{
		((unsigned char *)tab)[i] = ((unsigned char *)s1)[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
