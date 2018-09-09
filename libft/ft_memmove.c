/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:35:37 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/17 18:01:06 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	i = len;
	while (i != 0)
	{
		i--;
		((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
