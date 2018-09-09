/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:02:49 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/17 14:31:43 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*fraiche;
	char	lol;

	i = 0;
	if (!s)
		return (NULL);
	if ((fraiche = malloc(sizeof(char) * ft_strlen(s) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		lol = f(i, s[i]);
		fraiche[i] = lol;
		i++;
	}
	fraiche[i] = '\0';
	return (fraiche);
}
