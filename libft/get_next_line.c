/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:05:44 by alefebvr          #+#    #+#             */
/*   Updated: 2018/02/01 15:53:36 by alefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_read_file(int fd, char *line[fd], char *buff)
{
	int			ret;
	char		*tmp;

	while (!ft_strchr(buff, '\n') && (ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		tmp = line[fd];
		line[fd] = ft_strjoin(line[fd], buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	if (ret == -1)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char	*tmpstr[OPEN_MAX];
	char		*buff;
	char		*str;
	char		*tmp_bis;

	if (fd < 0 || read(fd, NULL, 0) == -1 || line == NULL || fd > OPEN_MAX
			|| !(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	if (!tmpstr[fd])
		tmpstr[fd] = ft_strnew(0);
	if (ft_read_file(fd, tmpstr, buff) == -1)
		return (-1);
	if ((str = ft_strchr(tmpstr[fd], '\n')))
	{
		tmp_bis = tmpstr[fd];
		*line = ft_strsub(tmpstr[fd], 0, str - tmpstr[fd]);
		tmpstr[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp_bis);
		return (1);
	}
	*line = ft_strdup(tmpstr[fd]);
	ft_strdel(&tmpstr[fd]);
	if (*line[0] == '\0')
		return (0);
	return (1);
}
