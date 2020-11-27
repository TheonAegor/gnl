#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h> 
#include <stdio.h> 

int main(void)
{
	char *p;
	int i;
	char b[] = "hello world again privet ";

	i = 0;
//	p = malloc(sizeof(char) * 10);
//	free(p);
	p = malloc(sizeof(char));
	while(i < ft_strlen(b))
	{
		*p++ = b[i];
		i++;
	}
	printf("%d\n", i);
	p = p - i;
	while(*p)
	{
		printf("%c", *p);
		p++;
	}
	printf("%d\n", ft_strlen(p));
	return (0);
}
