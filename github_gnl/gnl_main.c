#include "get_next_line.h"

int main()
{
/*
	char str1[] = "hello world";
	char str2[] = " oh hi mark";
	char *str3;

	str3 = NULL;
	printf("%s\n", ft_strjoin(str1, str2));
	printf("%s\n", ft_strjoin("", str2));
	printf("%s\n", ft_strjoin(str3, str2));
*/

	char *line;
	int fd;
	
//	line = (char *)malloc(sizeof(char));
	fd = open("texts/01_text.txt", O_RDONLY);
	while((get_next_line(fd, &line)))
	{
		printf("%s\n\n", line);
		free(line);
	}	

	get_next_line(fd, &line);
	printf("%s\n", line);
	free(line);

	return (1);
}
