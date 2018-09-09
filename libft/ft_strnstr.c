/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:44:29 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/19 21:19:16 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	size_t	size;
	int		b;

	i = 0;
	b = 0;
	size = ft_strlen(needle);
	if (needle[i] == '\0' || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && n >= size)
	{
		if (!ft_strncmp(&haystack[i], needle, size))
			return (&((char *)haystack)[i]);
		i++;
		n--;
	}
	return (NULL);
}
