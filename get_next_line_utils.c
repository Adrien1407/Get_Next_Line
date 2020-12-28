/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:20:45 by adlancel          #+#    #+#             */
/*   Updated: 2020/12/28 21:23:10 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!(res = (char *)malloc(count * size)))
		return (NULL);
	while (i < count)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strjoin_free(char *s1, char *s2, int ret)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	s2[ret] = '\0';
	if (!s1)
		return (ft_strdup(s2));
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1, 0) +
						ft_strlen_gnl(s2, 0) + 1))))
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	free(s1);
	s1 = NULL;
	str[i + j] = '\0';
	return (str);
}

size_t	ft_strlen_gnl(const char *s, int i)
{
	int		j;

	j = 0;
	while (s[i])
	{
		j++;
		i++;
	}
	return (j);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		i;

	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * ft_strlen_gnl(s1, 0) + 1)))
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int		ft_eol(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (ERROR);
}
