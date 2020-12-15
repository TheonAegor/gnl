#include "get_next_line.h"

int main()
{
	char *line;
	int fd;
	
	fd = open('texts/01_text.txt', O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);	
	}
	return (1);
}
