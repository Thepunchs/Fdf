/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:49:53 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/16 21:09:33 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int b;
	int j;

	b = 0;
	i = 0;
	if (!*needle)
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (needle[b] == haystack[i])
			j = i;
		while (needle[b] == haystack[j] && needle[b] != '\0')
		{
			b++;
			j++;
		}
		if (needle[b] == '\0')
			return (&((char *)haystack)[i]);
		b = 0;
		i++;
	}
	return (NULL);
}
