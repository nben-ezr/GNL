/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: nben-ezr <nben-ezr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/15 01:40:50 by nben-ezr       #+#    #+#                */
/*   Updated: 2020/01/19 19:27:34 by nben-ezr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# define MAX_FD 1024

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_gnl_info
{
	int			rval;
	char		*remainder[MAX_FD];
}				t_gnl_info;

char			*ft_strndup(const char *s1, size_t len);
char			*ft_substr(const char *s1, int start);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
int				get_next_line(int fd, char **line);
void			*ft_calloc(size_t count, size_t size);
#endif
