# include "get_next_line.h"

char	*ft_strnew(size_t size)
{
	return((char *)malloc(sizeof(char)  * (size + 1)));
}

int			get_next_line(int fd, char **line)
{
	char *buf;
	char *p_n;
	char *tmp;
	static char *reminder;
	int bytes_was_read;
	
	if (BUFFER_SIZE <= 0)
		return(-1);
	if (reminder)
	{
		if ((p_n = ft_strchr(reminder, '\n')))
			p_n[0] = '\0';
		*line = ft_strdup(reminder);
		if (p_n)
		{
			tmp = reminder;
			reminder = ft_strdup(++p_n);
			free(tmp);
			return (1);
		}
	}
	else
		*line = ft_strnew(1);
	p_n = NULL;
	if (!(buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	while(!(p_n) && (bytes_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			*p_n = '\0';
			reminder = ft_strdup(++p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	free(buf);
	if (bytes_was_read <= 0)
	{
//		free(reminder);
		return (0);
	}
	return (1);
}
