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
	char		buf[BUFFER_SIZE];
	int			byte_was_read;
	static int	num_of_lines;

//	printf("addres of line in func:\t%p\n", *line);
//	printf("addres of buf in func:\t%p\n", buf);
	ft_bzero(buf);
//	if (!(*line) || num_of_lines > 0)
//		*line = malloc(sizeof(char));
	while ((byte_was_read = read(fd,buf,1) > 0))
	{	
		if (buf[0] == '\n')
		{
			num_of_lines++;
			break;
		}
		*line = ft_strjoin(*line, &(buf[0]));
	}
	if (byte_was_read == 0)
		return (0);
	return (1);
}
/*
int main(void)
{
	int fd;
	char *line;
	char pathname[] = "./text2.txt";

//	line = malloc(sizeof(char));
	fd = open(pathname, O_RDONLY);
//	line = "hello world";
//	fd = 0;
//	printf("%d\n", ft_strlen(line));
	while(get_next_line(fd,&line) > 0)
	{
//	get_next_line(fd,&line);
		printf("%s\n", line);
//		ft_bzero(line);
		free(line);
//		printf("addres of line in main after free:\t%p\n", line);
//		line = malloc(sizeof(char));
	}
	return 1;
}
*/

