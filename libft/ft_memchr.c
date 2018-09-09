/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:51:36 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/16 17:53:58 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)&s[i]);
		i++;
		n--;
	}
	return (NULL);
}
