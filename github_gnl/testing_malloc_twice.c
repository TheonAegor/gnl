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
	char *p2;
	int i;
	char b[] = "hello world again privet ";

	i = 0;
//	p = malloc(sizeof(char) * 10);
//	free(p);
	p = malloc(sizeof(char));
	p2 = malloc(sizeof(char));
	printf("address of p:%p\n", p);
	printf("address of p2:%p\n", p2);
/*
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
*/
	return (0);
}
