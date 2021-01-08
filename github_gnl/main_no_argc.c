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
	int res;
	
//	fd = open("texts/01_text.txt", O_RDONLY);
//	fd = open("texts/07_only_newlines.txt", O_RDONLY);
//	fd = open("texts/line.txt", O_RDONLY);
//	fd = open("texts/3_words.txt", O_RDONLY);
//	fd = open("texts/1_newline", O_RDONLY);
//	fd = open("texts/empty_lines", O_RDONLY);
//	fd = open("texts/4_newlines", O_RDONLY);
//	fd = open("texts/only_new_lines.txt", O_RDONLY);
//	fd = open("texts/63_line.txt", O_RDONLY);
//	fd = open("texts/64_line", O_RDONLY);
//	fd = open("texts/one_line.txt", O_RDONLY);
//	fd = open("texts/linux_book", O_RDONLY);
//	fd = open("texts/08_no_newlines.txt", O_RDONLY);
//	fd = 180;
	fd = 0;
	while((res = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);	
	}
//	printf("%s\n", line);
	free(line);
//	get_next_line(fd, &line);
//	printf("%s\n", line);
	return (1);
}
