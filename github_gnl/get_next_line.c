# include "get_next_line.h"
void ft_bzero(char *s)
{
	while(*s)
	{
		*s++ = '\0';
	}
}

char	*ft_strnew(size_t size)
{
	return((char *)malloc(sizeof(char)  * (size + 1)));
}
/*
Нужно записать символы до \n в переменную 

Записываем посимвольно в лайн 
1)в буффер выделим 1 байт памяти
Как сделать чтобы файл читался с места на котором остановился
----------------------
1)сколько памяти нужно выделить под line
2)как передать буффер
	-если новой строки после первого прочтения не было
	-если новая строка была, и буфера зашел за нее
	-если буффер дошел до конца строки
*/
int			get_next_line(int fd, char **line)
{
	char *buf;
	char *p_n;
	char *tmp;
	int flag;
	static char *reminder;
	int bytes_was_read;
//	char *str;
	
	if (reminder)
	{
		if ((p_n = ft_strchr(reminder, '\n')))
			p_n[0] = '\0';
//		printf("%s\n+++++++++++++++++++++\n", reminder); //it works
		*line = ft_strdup(reminder);
//		printf("line = reminder: %s\n", *line);
		if (p_n)
		{
			tmp = reminder;
			reminder = ft_strdup(++p_n);
//			printf("%s\n---------------\n", reminder); //it works
			free(tmp);
//			printf("%s\n---------------\n", reminder); //it works
			return (1);
		}
	}
	else
		*line = ft_strnew(1);
	flag = 1;
	p_n = NULL;
	if (!(buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1)))
		return (-1);
	while(!(p_n) && (bytes_was_read = read(fd, buf, BUFFER_SIZE)) && flag)
	{
		buf[bytes_was_read] = '\0';
		if ((p_n = ft_strchr(buf, '\n')))
		{
			flag = 0;	
			*p_n = '\0';
			p_n++;
			reminder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
//		printf("buf = %s; line =%s\n", buf, *line);
		free(tmp);
	}
	if (bytes_was_read <= 0)
		return (0);
	return (1);
}
