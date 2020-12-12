#/!/bin/bash

#size=32

src=./texts/*.txt

if [ -n "$size" ]; then
	gcc -Wall -Wextra -Werror -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c 
else
	read size
	gcc -Wall -Wextra -Werror -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c
fi
./main $src
