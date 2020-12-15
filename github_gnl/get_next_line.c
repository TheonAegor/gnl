# include "get_next_line.h"
void ft_bzero(char *s)
{
	while(*s)
	{
		*s++ = '\0';
	}
}

char	*ft_strnew()
{
	return(ft_calloc(sizeof(char), 1));
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
//	char *tmp;
//	int flag;
	int bytes_was_read;
	
	*line = ft_strnew();	
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	while((bytes_was_read = read(fd, buf, BUFFER_SIZE)))
	{
	//	printf("%s\n", buf);
		
		buf[BUFFER_SIZE] = '\0';
		*line = ft_strdup(buf);
//		printf("%s\n", *line);
	}

	return (0);
}
