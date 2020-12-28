/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:10:24 by adlancel          #+#    #+#             */
/*   Updated: 2020/12/28 21:23:36 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < ft_strlen_gnl(s, 0))
	{
		while (s[start] && i < len)
			res[i++] = s[start++];
	}
	res[i] = '\0';
	return (res);
}

char	*ft_fill_line(char *s, char **line, int i)
{
	char *str;

	*line = ft_substr(s, 0, i);
	str = ft_substr(s, i + 1, ft_strlen_gnl(s, i));
	free(s);
	s = NULL;
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	static char	*s[256];
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (ERROR);
	if (!s[fd] && (!(s[fd] = ft_calloc(1, sizeof(char *)))))
		return (ERROR);
	if (s[fd] && (((i = ft_eol(s[fd])) != ERROR)))
		return ((s[fd] = ft_fill_line(s[fd], line, i)) != FINISH);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		s[fd] = ft_strjoin_free(s[fd], buf, ret);
		if (((i = ft_eol(s[fd])) != ERROR))
			return ((s[fd] = ft_fill_line(s[fd], line, i)) != FINISH);
	}
	if (s[fd])
	{
		*line = ft_strdup(s[fd]);
		free(s[fd]);
		s[fd] = NULL;
		return (FINISH);
	}
	return (FINISH);
}
