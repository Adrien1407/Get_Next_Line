/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlancel <adlancel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 23:14:27 by adlancel          #+#    #+#             */
/*   Updated: 2020/12/25 01:18:41 by adlancel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# define ERROR -1
# define SUCCESS 1
# define FINISH 0

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>

char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strjoin_free(char *s1, char *s2);
int		ft_strlen_gnl(const char *s, int i);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
int		ft_eol(char *str);
int		ft_get_next_line(int fd, char **line);

#endif
