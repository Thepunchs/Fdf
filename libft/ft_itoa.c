/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 11:42:05 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/19 22:08:17 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isnegative(int nb)
{
	if (nb < 0)
		return (1);
	else
		return (0);
}

static int		ft_combiendechiffres(int nb)
{
	int chiffres;
	int a;

	a = 0;
	chiffres = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb = -nb;
		chiffres++;
	}
	if (nb == -2147483648)
	{
		nb = -1 - nb;
		chiffres++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		if (chiffres == 1 && nb == (2147483647 / 10) && a != 1)
			nb++;
		a = 1;
		chiffres++;
	}
	chiffres++;
	return (chiffres);
}

char			*ft_itoa(int n)
{
	int		negative;
	int		chiffres;
	char	*fraiche;

	negative = ft_isnegative(n);
	chiffres = ft_combiendechiffres(n);
	if (negative == 1 && n != -2147483648)
		n = -n;
	if (n == -2147483648)
		n = -1 - n;
	if ((fraiche = malloc(sizeof(char) * chiffres + 1)) == NULL)
		return (NULL);
	if (negative == 1)
		fraiche[0] = '-';
	fraiche[chiffres] = '\0';
	while (n > 9)
	{
		if (negative == 1 && n == 2147483647)
			fraiche[--chiffres] = n % 10 + 1 + '0';
		else
			fraiche[--chiffres] = n % 10 + '0';
		n = n / 10;
	}
	fraiche[--chiffres] = n + '0';
	return (fraiche);
}
