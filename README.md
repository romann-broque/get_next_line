# get_next_line

A useful function returning the last read line from a file descriptor (with, if there is, the \n).
Returns NULL if the file is over or if there is an error.

## Compiling

	$ cc -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8 // just change BUFFER_SIZE according to your interests
