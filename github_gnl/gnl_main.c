#include "get_next_line.h"

int main(int argc, char *argv[])
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
	int i;
	
	i = 1;
	while (argc > 1)
	{
//	line = (char *)malloc(sizeof(char));
		fd = open(argv[i], O_RDONLY);
		while((get_next_line(fd, &line)))
		{
			printf("%s\n\n", line);
			free(line);
		}	

		get_next_line(fd, &line);
		printf("%s\n", line);
		free(line);
		argc--;
		i++;
	}

	return (1);
}
