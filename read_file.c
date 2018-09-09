/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 20:08:00 by alefebvr          #+#    #+#             */
/*   Updated: 2018/03/17 16:17:23 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	alloc_tab(char *str, int **tab, int k, int *size_line)
{
	int		i;
	int		j;
	char	**temp;

	i = 0;
	j = 0;
	temp = ft_strsplit(str, ' ');
	while (temp[i])
		i++;
	if (!(tab[k] = (int *)malloc(sizeof(int) * (i))))
		return (0);
	while (j < i)
	{
		tab[k][j] = ft_atoi(temp[j]);
		j++;
	}
	*size_line = j;
	j--;
	while (j >= 0)
		free(temp[j--]);
	free(temp);
	return (i);
}

void		read_file(t_fdf *x, char *line, char *argv)
{
	int i;
	int ret;

	i = 0;
	while ((ret = get_next_line(x->fd, &line)) > 0)
	{
		i++;
		ft_strdel(&line);
	}
	ft_strdel(&line);
	x->size = i;
	close(x->fd);
	if (!(x->alt = (int **)malloc(sizeof(int *) * (i))))
		return ;
	x->fd = open(argv, O_RDONLY);
	i = 0;
	while ((ret = get_next_line(x->fd, &line)) > 0)
	{
		alloc_tab(line, x->alt, i, &x->sizeline);
		ft_strdel(&line);
		i++;
	}
	ft_strdel(&line);
	close(x->fd);
}

int			ft_check_file(char *argv)
{
	int		i;
	char	*str;
	int		fd;

	i = 0;
	str = ".fdf";
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			if ((ft_strcmp(str, &argv[i])) == 0)
			{
				if ((fd = open(argv, O_RDONLY)) < 0)
					return (0);
				close(fd);
				return (1);
			}
		}
		i++;
	}
	return (0);
}
