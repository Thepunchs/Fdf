/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:58:39 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/16 19:32:14 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t k;
	size_t lol;

	i = 0;
	j = ft_strlen(src);
	k = ft_strlen(dst);
	lol = k;
	if (size == 0)
		return (j);
	while (size - 1 > k && src[i] != '\0')
		dst[k++] = src[i++];
	dst[k] = '\0';
	if (size > lol)
		return (j + lol);
	else
		return (size + j);
}
