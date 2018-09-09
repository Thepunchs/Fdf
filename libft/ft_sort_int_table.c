/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 10:31:39 by alefebvr          #+#    #+#             */
/*   Updated: 2017/11/21 11:20:31 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_table(int *tab, int size)
{
	int i;
	int a;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			a = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = a;
			i = 0;
		}
		if (tab[0] > tab[1])
		{
			a = tab[0];
			tab[0] = tab[1];
			tab[1] = a;
			i = 0;
		}
		i++;
	}
}
