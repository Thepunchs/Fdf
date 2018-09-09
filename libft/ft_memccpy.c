/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:08:07 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/16 17:55:56 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	i = 0;
	if (n == 0)
		return (NULL);
	while (n > i)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] != (unsigned char)c)
			i++;
		else
			return (&tmp1[i + 1]);
	}
	return (NULL);
}
