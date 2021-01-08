#/!/bin/bash

size=4

if [ -n "$size" ]; then
	gcc -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c 
else
	read size
	gcc -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c
fi
./main
: '
size=2

if [ -n "$size" ]; then
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c 
else
	read size
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c
fi
./main >> results/2_simple
size=100

if [ -n "$size" ]; then
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c 
else
	read size
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c
fi
./main >> results/2_simple
'

