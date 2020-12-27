#/!/bin/bash

#size=10

if [ -n "$size" ]; then
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c main_no_argc.c 
else
	read size
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c main_no_argc.c
fi
./main 
