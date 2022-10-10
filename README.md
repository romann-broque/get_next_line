# get_next_line

A useful function returning the last read line from a file descriptor (with, if there is, the \n).
Returns NULL if the file is over or if there is an error.

## Compiling

### CLASSIC Part

	$ clang -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8
You just have to change BUFFER_SIZE according to your interests.

### BONUS Part

	$ clang -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8 -D INTER_LINE=5
You just have to change BUFFER_SIZE and INTER_LINE according to your interests.

## Set OPEN_MAX

Depending on your operating system, you can modify the definition of OPEN_MAX.
If you want to know the limit of open files that your operating system can support,
just type the following command:
	$ ulimit -n
