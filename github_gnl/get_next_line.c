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
*/
int			get_next_line(int fd, char **line)
{
	char		*buf;
	int			byte_was_read;
	int			flag;

	flag = 1;
	if (fd < -1 || !*line)
		return (-1);
	buf = malloc(sizeof(char) * BUFFER_SIZE);
	*line = malloc(sizeof(char) + 1);
	ft_bzero(buf);
	ft_bzero(*line);
	while (flag && (byte_was_read = read(fd,buf,1) != 0))
	{	
		buf[byte_was_read] = '\0';
		if (buf[0] == '\n')
		{
			flag = 0;
		}
		if (flag)
			*line = ft_strjoin(*line, buf);
	}
	if (byte_was_read == 0)
		return (0);
	return (1);
}


int main(int argc, char *argv[])
{

	int fd;
//	int fd2;
	char *line;
	int i;
//	char pathname[] = "./text.txt";
/*
	if (argc > 1)
		argc = 2;
	fd = open(argv[1], O_RDONLY);
	printf("1 call:%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	fd2 = open(argv[2], O_RDONLY);
	printf("1 call%d\n", get_next_line(fd2, &line));
	printf("%s\n", line);
	printf("2 call%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("2 call%d\n", get_next_line(fd2, &line));
	printf("%s\n", line);

//	printf("%d\n", argc);

*/
	i = 1;
	while (argc > 1)
	{
		
		fd = open(argv[i], O_RDONLY);
		while ( get_next_line(fd, &line) > 0)
		{
//		printf("%d\n", get_next_line(fd, &line));
			printf("%s\n", line);
		}
		argc--;
		i++;
	}
	fd = 0;
	while ( get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
		}
	return 1;
}
/*
	line = malloc(sizeof(char));
	fd = open(pathname, O_RDONLY);
	line = "hello world";
	fd = 0;
	printf("%d\n", ft_strlen(line));
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);
	printf("%d\n", get_next_line(fd, &line));
	printf("%s\n", line);

	while(get_next_line(fd,&line) > 0)
	{
		printf("%s\n", line);
		ft_bzero(line);
		free(line);
		printf("addres of line in main after free:\t%p\n", line);
		line = malloc(sizeof(char));
	}

}
*/



