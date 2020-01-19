/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nben-ezr <nben-ezr@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/12 23:17:34 by nben-ezr       #+#    #+#                */
/*   Updated: 2020/01/18 01:55:39 by nben-ezr      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *s1, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0' && len > 0)
	{
		s2[i] = s1[i];
		i++;
		len--;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(const char *s1, int start)
{
	int			len;
	char		*substr;
	const char	*countstr;
	int			i;

	i = 0;
	countstr = s1 + start;
	len = 0;
	while (*countstr != '\0')
	{
		countstr++;
		len++;
	}
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (s1[start + i] != '\0')
	{
		substr[i] = s1[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstring;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	newstring = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (newstring == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		newstring[i] = s1[i];
		i++;
	}
	free((char*)s1);
	while (s2[j] != '\0')
	{
		newstring[i + j] = s2[j];
		j++;
	}
	newstring[i + j] = '\0';
	return (newstring);
}

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x] != 0)
	{
		x++;
	}
	return (x);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*memory;
	unsigned char	*memstr;
	size_t			i;

	i = count * size;
	memory = malloc(i);
	if (memory == NULL)
		return (0);
	memstr = memory;
	while (i > 0)
	{
		*memstr = 0;
		memstr++;
		i--;
	}
	return (memory);
}
