/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:37:32 by taegor            #+#    #+#             */
/*   Updated: 2021/01/10 01:52:05 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct		s_list
{
	int				fd;
	char			*reminder;
	struct s_list	*next;
}					t_list;

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
int					get_next_line(int fd, char **line);
char				*ft_strdup(const char *s);
int					ft_strjoin(char **s1, char *s2);
int					ft_strlen(char *s);
char				*ft_substr(char *s, unsigned int start, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
int					find_n(char *buf);

#endif
