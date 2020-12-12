#include "get_next_line.h"

int main(int argc, char *argv[])
{

	int fd;
//	int fd2;
	char *line;
	int i;

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

/*	fd = 0;
	while ( get_next_line(fd, &line) > 0)
		{
			printf("%s\n", line);
		}
	return 1;*/
}
