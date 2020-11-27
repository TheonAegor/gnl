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
/*
Нужно записать символы до \n в переменную 

Записываем посимвольно в лайн 
1)в буффер выделим 1 байт памяти
Как сделать чтобы файл читался с места на котором остановился
*/
int			get_next_line(int fd, char **line)
{
	char		*buf;
	int			byte_was_read;

	buf = malloc(sizeof(char));
	printf("%p\n", *line);
	printf("%p\n", buf);
	while ((byte_was_read = read(fd,buf,1) > 0))
	{	
//		printf("i = %d, len_to_start = %d\n", i, len_to_start);
/*		while(i<len_to_start)
		{
			if (read(fd,buf,1) < 1)
				return (0);
			i++;
		}*/
//		printf("line[0] = %c | ", **line);
//		printf("buf = %s | ", buf);
		if (buf[0] == '\n')
		{
			break;
		}
		*line = ft_strjoin(*line, &(buf[0]));
//		printf("line = %s\n", *line);
	}
	if (byte_was_read == 0)
		return (0);
	return (1);
}

int main(void)
{
	int fd;
	char *line;
	char pathname[] = "./text.txt";

//	line = malloc(sizeof(char));
	fd = open(pathname, O_RDONLY);
	line = "hello world";
//	fd = 0;
//	printf("%d\n", ft_strlen(line));
	while(get_next_line(fd,&line) > 0)
	{
//	get_next_line(fd,&line);
		printf("%s\n", line);
		free(line);
	}
	return 1;
}
