#include "get_next_line.h"

int main(void)
{
	char *line;
	int fd;
	int i;
/*	
	fd = open("texts/1_newline", O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);
	if (i == -1)
		printf("Error\n\n");
	else if (i == 2)
		printf("Right number of lines\n\n");
	else
		printf("Wrong number of lines, i = %d\n\n", i);
*/
	fd = open("texts/2_simple", O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	printf("%s\n", line);
	free(line);
/*
	fd = open("texts/empty_lines", O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);

	fd = open("texts/line.txt", O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);

	fd = open("texts/64bit_line.txt", O_RDONLY);
	i = 0;
	while((get_next_line(fd, &line)))
	{
		printf("%s\n", line);
		free(line);
		i++;
	}
	free(line);

	fd = open("texts/no_newline", O_RDONLY);
	i = 0;
	while((get_next_line(42, NULL)) > 0 )
	{
		printf("%s\n", line);
		free(line);
		i++;
	}

*/
	return (1);
}
