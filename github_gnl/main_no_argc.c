#include "get_next_line.h"

int main(void)
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
	
//	fd = open("texts/01_text.txt", O_RDONLY);
//	fd = open("texts/07_only_newlines.txt", O_RDONLY);
	fd = open("texts/line.txt", O_RDONLY);
//	fd = open("texts/08_no_newlines.txt", O_RDONLY);
//	fd = 0;
	while(get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);	
	}
//	get_next_line(fd, &line);
//	printf("%s\n", line);
	return (1);
}
