#include "get_next_line.h"

int		fill_reminder(char **p_n, char **line, char **reminder)
{
	char		*tmp;

	if (*reminder)
	{
		if ((*p_n = ft_strchr(*reminder, '\n')))
			*p_n[0] = '\0';
		*line = ft_strdup(*reminder);
		if (*p_n)
		{
			tmp = *reminder;
			*reminder = ft_strdup(++(*p_n));
			free(tmp);
			return (1);
		}
	}
	else
	{
		if (!(*line = (char *)malloc(sizeof(char) * (1 + 1))))
			return (-1);
	}
	*p_n = NULL;
	return (0);
}

int		do_gnl(char **p_n, int fd, char **line, char **reminder)
{
	char		*buf;
	int			bytes_was_read;
	char		*tmp;

	if (!(buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	while (!(*p_n) && (bytes_was_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[bytes_was_read] = '\0';
		if ((*p_n = ft_strchr(buf, '\n')))
		{
			**p_n = '\0';
			*reminder = ft_strdup(++(*p_n));
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	free(buf);
	return (bytes_was_read);
}

int		get_next_line(int fd, char **line)
{
	char		*p_n;
	static char	*reminder;
	int			res;

	if ((res = fill_reminder(&p_n, line, &reminder)) == 1)
		return (1);
	if (res == -1)
		return (-1);
	if (do_gnl(&p_n, fd, line, &reminder) == 0)
		return (0);
	return (1);
}
