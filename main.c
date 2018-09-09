/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 14:35:36 by alefebvr          #+#    #+#             */
/*   Updated: 2018/03/17 15:58:43 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_alt(t_fdf *elem)
{
	elem->sbase--;
	while (elem->sbase >= 0)
	{
		free(elem->alt[elem->sbase]);
		elem->sbase--;
	}
	free(elem->alt);
}

int		deal_key(int key, t_fdf *elem)
{
	mlx_clear_window(elem->mlx, elem->win);
	if (key == 78)
		if (elem->zoom > 3)
			elem->zoom = elem->zoom - 2;
	if (key == 69)
		elem->zoom = elem->zoom + 2;
	if (key == 125)
		elem->zoom_z = elem->zoom_z - 1;
	if (key == 126)
		elem->zoom_z = elem->zoom_z + 1;
	if (key == 13)
		elem->ybase = elem->ybase - 50;
	if (key == 0 || key == 123)
		elem->xbase = elem->xbase - 50;
	if (key == 1)
		elem->ybase = elem->ybase + 50;
	if (key == 2 || key == 124)
		elem->xbase = elem->xbase + 50;
	if (key == 53)
	{
		free_alt(elem);
		exit(1);
	}
	draw(*elem);
	return (1);
}

void	ft_init(t_fdf *x)
{
	x->size = 0;
	x->sizeline = 0;
	x->zoom = 30;
	x->rgb = 2385959;
	x->xbase = 500;
	x->ybase = 100;
	x->x = x->xbase;
	x->y = x->ybase;
	x->zoom_z = 3;
	x->rgb = 0x46FF00;
	x->rgb2 = 0xFF0000;
	x->rgb3 = 0x00E4FF;
}

int		main(int argc, char **argv)
{
	t_fdf	x;
	char	*line;

	line = NULL;
	if (argc == 2 && ft_check_file(argv[1]) != 0)
	{
		ft_init(&x);
		x.fd = open(argv[1], O_RDONLY);
		x.name = argv[1];
		read_file(&x, line, argv[1]);
		x.slbase = x.sizeline;
		x.sbase = x.size;
		x.mlx = mlx_init();
		x.win = mlx_new_window(x.mlx, WINW, WINH, x.name);
		draw(x);
		mlx_key_hook(x.win, deal_key, &x);
		mlx_loop(x.mlx);
	}
	else
		ft_putendl("usage : ./fdf map.fdf");
	return (0);
}
