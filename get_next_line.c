/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nben-ezr <nben-ezr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 22:53:54 by nben-ezr       #+#    #+#                */
/*   Updated: 2020/01/19 19:24:42 by nben-ezr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_newline(int fd, t_gnl_info *info, char **line, int ret)
{
	int		nline_loc;
	char	*temp;

	nline_loc = 0;
	while (info->remainder[fd][nline_loc] != '\0')
	{
		if (info->remainder[fd][nline_loc] == '\n')
		{
			*line = ft_strndup(info->remainder[fd], nline_loc);
			if (line == NULL)
				return (-1);
			temp = ft_substr(info->remainder[fd], nline_loc + 1);
			free(info->remainder[fd]);
			info->remainder[fd] = temp;
			if (info->remainder[fd] == NULL)
				return (-1);
			return (1);
		}
		nline_loc++;
	}
	return (0);
}

int		read_buffer(int fd, t_gnl_info *info, char **line)
{
	int		ret;
	char	buff_hold[BUFFER_SIZE + 1];

	ret = -1;
	while (ret != 0)
	{
		if (check_newline(fd, info, line, ret) == 1)
			return (1);
		else if (check_newline(fd, info, line, ret) == -1)
			return (-1);
		ret = read(fd, buff_hold, BUFFER_SIZE);
		if (ret < 0)
		{
			info->rval = -1;
			return (info->rval);
		}
		buff_hold[ret] = '\0';
		info->remainder[fd] = ft_strjoin(info->remainder[fd], buff_hold);
		if (info->remainder[fd] == NULL)
			return (-1);
		*line = info->remainder[fd];
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl_info	info;

	if (line == NULL || fd > MAX_FD || fd < 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (info.remainder[fd] == NULL)
		info.remainder[fd] = (char*)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (info.rval >= 0)
		info.rval = read_buffer(fd, &info, line);
	printf("%d: ", info.rval);
	return (info.rval);
}
