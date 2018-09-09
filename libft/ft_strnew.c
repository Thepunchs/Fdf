/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:03:41 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/18 16:24:33 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	while (i <= size)
		str[i++] = '\0';
	return (str);
}
