/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:42:09 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/17 17:56:03 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fraiche;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	fraiche = malloc(sizeof(char) * len + 1);
	if (fraiche == NULL)
		return (NULL);
	while (len > i && s[start] != '\0')
		fraiche[i++] = s[start++];
	fraiche[i] = '\0';
	return (fraiche);
}
