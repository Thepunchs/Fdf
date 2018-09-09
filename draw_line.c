/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:57:58 by alefebvr          #+#    #+#             */
/*   Updated: 2018/03/17 15:29:30 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	z_init(t_fdf elem, t_z *z, int x)
{
	z->x1 = elem.x;
	z->y1 = elem.y;
	z->y2 = elem.y + elem.zoom;
	if (x == 1)
		z->x2 = elem.x - elem.zoom;
	else
		z->x2 = elem.x + elem.zoom;
}

void	draw_horizontal(t_fdf elem, int i, int j)
{
	t_z z;

	z_init(elem, &z, 0);
	if (elem.sizeline != 1)
	{
		if (elem.alt[i][j] != 0 && elem.alt[i][j + 1] != 0)
		{
			z.y1 = z.y1 - elem.alt[i][j] * elem.zoom_z;
			z.y2 = z.y2 - elem.alt[i][j + 1] * elem.zoom_z;
			z.rgb = elem.rgb2;
		}
		else if (elem.alt[i][j] == 0 && elem.alt[i][j + 1] != 0)
		{
			z.y2 = z.y2 - elem.alt[i][j + 1] * elem.zoom_z;
			z.rgb = elem.rgb3;
		}
		else if (elem.alt[i][j] != 0 && elem.alt[i][j + 1] == 0)
		{
			z.y1 = z.y1 - elem.alt[i][j] * elem.zoom_z;
			z.rgb = elem.rgb3;
		}
		else
			z.rgb = elem.rgb;
		draw_line(elem, z);
	}
}

void	draw_vertical(t_fdf elem, int i, int j)
{
	t_z z;

	z_init(elem, &z, 1);
	if (elem.size != 1)
	{
		if (elem.alt[i][j] != 0 && elem.alt[i + 1][j] != 0)
		{
			z.y1 = z.y1 - elem.alt[i][j] * elem.zoom_z;
			z.y2 = z.y2 - elem.alt[i + 1][j] * elem.zoom_z;
			z.rgb = elem.rgb2;
		}
		else if (elem.alt[i][j] == 0 && elem.alt[i + 1][j] != 0)
		{
			z.y2 = z.y2 - elem.alt[i + 1][j] * elem.zoom_z;
			z.rgb = elem.rgb3;
		}
		else if (elem.alt[i][j] != 0 && elem.alt[i + 1][j] == 0)
		{
			z.y1 = z.y1 - elem.alt[i][j] * elem.zoom_z;
			z.rgb = elem.rgb3;
		}
		else
			z.rgb = elem.rgb;
		draw_line(elem, z);
	}
}

void	draw(t_fdf elem)
{
	int i;
	int j;

	i = 0;
	while (elem.size > 0)
	{
		j = 0;
		elem.sizeline = elem.slbase;
		elem.x = elem.xbase;
		elem.y = elem.ybase;
		while (elem.sizeline > 0)
		{
			draw_horizontal(elem, i, j);
			draw_vertical(elem, i, j);
			elem.x += elem.zoom;
			elem.y += elem.zoom;
			elem.sizeline--;
			j++;
		}
		elem.xbase -= elem.zoom;
		elem.ybase += elem.zoom;
		elem.size--;
		i++;
	}
}
