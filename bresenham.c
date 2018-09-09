/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:57:58 by alefebvr          #+#    #+#             */
/*   Updated: 2018/03/15 20:46:54 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bres_init(t_bres *x, t_z z)
{
	x->xincr = 1;
	x->yincr = 1;
	x->ex = abs(z.x2 - z.x1);
	x->ey = abs(z.y2 - z.y1);
	x->dx = 2 * x->ex;
	x->dy = 2 * x->ey;
	x->d_x = x->ex;
	x->d_y = x->ey;
}

void	bres1(t_bres bres, t_fdf elem, t_z z)
{
	int i;

	i = 0;
	while (i <= bres.d_x)
	{
		mlx_pixel_put(elem.mlx, elem.win, z.x1, z.y1, z.rgb);
		i++;
		z.x1 += bres.xincr;
		bres.ex -= bres.dy;
		if (bres.ex < 0)
		{
			z.y1 += bres.yincr;
			bres.ex += bres.dx;
		}
	}
}

void	bres2(t_bres bres, t_fdf elem, t_z z)
{
	int i;

	i = 0;
	while (i <= bres.d_y)
	{
		mlx_pixel_put(elem.mlx, elem.win, z.x1, z.y1, z.rgb);
		i++;
		z.y1 += bres.yincr;
		bres.ey -= bres.dx;
		if (bres.ey < 0)
		{
			z.x1 += bres.xincr;
			bres.ey += bres.dy;
		}
	}
}

void	draw_line(t_fdf elem, t_z z)
{
	t_bres bres;

	bres_init(&bres, z);
	if (z.x1 > z.x2)
		bres.xincr = -1;
	if (z.y1 > z.y2)
		bres.yincr = -1;
	if (bres.d_x > bres.d_y || bres.d_x == bres.d_y)
		bres1(bres, elem, z);
	else if (bres.d_x < bres.d_y)
		bres2(bres, elem, z);
}
