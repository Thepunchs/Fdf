/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:41:51 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/16 19:19:20 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int b;

	b = ft_strlen((char *)s);
	i = 0;
	while (b != 0 && s[b] != (char)c)
		b--;
	if (s[b] == c)
		return (&((char*)s)[b]);
	return (NULL);
}
