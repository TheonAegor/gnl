/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taegor <taegor@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 01:34:50 by taegor            #+#    #+#             */
/*   Updated: 2021/01/10 13:07:53 by taegor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	    ft_strcpy(char **dst, char *src, int newline)
{
    int i;

    i = 0;
    newline++;
    while (newline < BUFFER_SIZE && newline != 0)
    {
        dst[0][i] = src[newline];
        newline++;
        i++;
    }
    dst[0][i] = '\0';
}

int			check_start(char **buf, char **line, char **rem)
{
	if (BUFFER_SIZE < 1 || !line || BUFFER_SIZE > 10000000)
		return (-1);
	*buf = ft_calloc(sizeof(char*), BUFFER_SIZE + 1);
	if (*buf == 0)
		return (-1);
	if (*rem == 0)
    {
        *rem = ft_calloc(sizeof(char*), (BUFFER_SIZE + 1));
        if (*rem == 0)
        {
            free(*buf);
            return (-1);
        }
    }
	return (1);
}
	
int			act_line(char **rem,char **buf, char **line, int i)
{
	int		x;

	if (i == 0)
		x = ft_strjoin(line, *rem);
	else
		x = ft_strjoin(line, *buf);
	if (x == -1)
	{
		free(*buf);
		free(*rem);
		*rem = NULL;
		return (-1);
	}
	return (1);
}

int			check_bytes(char **buf, char **rem, int bytes_was_read)
{
	if (bytes_was_read < 1)
	{
		free(*buf);
		free(*rem);
		*rem = NULL;
		return (bytes_was_read);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*rem;
	int			p_newline;
	int			bytes_was_read;

	if (check_start(&buf, line, &rem) == -1)
		return (-1);	
	*line = NULL;
	if (act_line(&rem, &buf, line, 0) == -1)
		return (-1);
	p_newline = find_n(rem);
	ft_strcpy(&rem, rem, p_newline);
	while (p_newline < 0)	
	{
		bytes_was_read = read(fd, buf, BUFFER_SIZE);
		if (check_bytes(&buf, &rem, bytes_was_read) < 1)		
			return (bytes_was_read);
		buf[bytes_was_read] = '\0';
		p_newline = find_n(buf);
		ft_strcpy(&rem, buf, p_newline);
		if (act_line(&rem, &buf, line, 1) == -1)
			return (-1);
	}
	free(buf);
	return (1);
}
