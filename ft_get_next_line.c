/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:10:24 by adlancel          #+#    #+#             */
/*   Updated: 2020/12/25 01:12:20 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*ft_fill_line(char *static_str, char **line, int i)
{
	char *str;

	*line = ft_substr(static_str, 0, i);
	str = ft_substr(static_str, i + 1, ft_strlen_gnl(static_str, i));
	free(static_str);
	static_str = NULL;
	return (str);
}

int		ft_get_next_line(int fd, char **line)
{
	int			i;
	static char	*static_str;
	char		buf[BUFFER_SIZE + 1];
	int			ret;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buf, 0) < 0)
		return (ERROR);
	if (static_str && (((i = ft_eol(static_str)) != ERROR)))
		return ((static_str = ft_fill_line(static_str, line, i)) != NULL);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		static_str = ft_strjoin_free(static_str, buf);
		if (((i = ft_eol(static_str)) != ERROR))
			return ((static_str = ft_fill_line(static_str, line, i)) != NULL);
	}
	if (static_str)
	{
		*line = ft_strdup(static_str);
		free(static_str);
		static_str = NULL;
		return (FINISH);
	}
	*line = ft_strdup("");
	return (FINISH);
}
