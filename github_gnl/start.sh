#/!/bin/bash

#size=32

if [ -n "$size" ]; then
	gcc -Wall -Wextra -Werror -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c 
else
	read size
	gcc -Wall -Wextra -Werror -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c 
fi
./main *.txt
