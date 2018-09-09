/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 15:41:26 by alefebvr          #+#    #+#             */
/*   Updated: 2018/03/17 15:40:31 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <mlx.h>
# include "libft/get_next_line.h"
# define WINW 1400
# define WINH 1300

typedef struct		s_fdf
{
	int				fd;
	char			*name;
	void			*mlx;
	void			*win;
	int				x;
	int				y;
	int				**alt;
	unsigned long	rgb;
	unsigned long	rgb2;
	unsigned long	rgb3;
	int				size;
	int				sizeline;
	int				zoom;
	int				zoom_z;
	int				xbase;
	int				ybase;
	int				slbase;
	int				sbase;
}					t_fdf;

typedef struct		s_bres
{
	int				xincr;
	int				yincr;
	int				dx;
	int				dy;
	int				d_x;
	int				d_y;
	int				ex;
	int				ey;
}					t_bres;

typedef struct		s_z
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				rgb;
}					t_z;

void				read_file(t_fdf *x, char *line, char *argv);
int					ft_check_file(char *argv);
void				draw_line(t_fdf elem, t_z z);
void				draw(t_fdf elem);
int					get_next_line(const int fd, char **line);
#endif
