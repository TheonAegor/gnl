# include "get_next_line.h"
/*
static void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*p;
	size_t	numel;
	
	numel = nmemb;
	p = malloc(nmemb * size);
	while(nmemb--)
	{
		*p++ = '\0';
	}
	return (p + numel);
}
*/
void ft_bzero(char *s)
{
	while(*s)
	{
		*s++ = '\0';
	}
}
/*
Нужно записать символы до \n в переменную 

Записываем посимвольно в лайн 
1)в буффер выделим 1 байт памяти
Как сделать чтобы файл читался с места на котором остановился
----------------------
1)сколько памяти нужно выделить под line
2)
*/
int			get_next_line(int fd, char **line)
{
	char		*buf;
	int			bytes_was_read;
	int			flag;
	int			i;

	flag = 1;
	if (!fd || !*line)
		return (-1);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	*line = malloc(sizeof(char) + 1);
	ft_bzero(buf);
	ft_bzero(*line);
	i = 0;
	while (flag && (bytes_was_read = read(fd,buf,BUFFER_SIZE) != 0)) //записываем в буффер количество символов равное BUFFER_SIZE
	{																//и мы не знаем сколько символово туда записано, поэтому 
																	//нужно каждый проверить не является ли он '\n', и записать в line
		line[bytes_was_read] = '\0';
		while (buf[i] != '\n' && buf[i] != '\0' && i < BUFFER_SIZE)
		{
			line[i] = buf[i];
			i++;
		}

	}
	
	return (1);
}
