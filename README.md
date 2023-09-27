## get_next_line

A useful function returning the last read line from a file descriptor (with, if there is, the \n). Returns NULL if the file is over or if there is an error.

### Project Description

The `get_next_line` project is a vital component in any C programmer's toolkit. It's a function that reads a single line from a file descriptor each time it's called. This project is not only about reading lines but also about understanding the intricacies of file I/O in the C programming language.

### Features

- Reads text from a file or stream, one line at a time.
- Handles multiple file descriptors concurrently.
- Efficient memory management with dynamic memory allocation.
- Adheres to SOLID principles, ensuring modular and maintainable code.

### 🚀 Usage

1. Include the `get_next_line` function in your C project.
2. Call the function with a file descriptor to read lines from it.

```c
#include "get_next_line.h"

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

### 🚀 Compiling

#### CLASSIC Part

```shell
$ clang -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8
```

You just have to change BUFFER_SIZE according to your interests.

#### BONUS Part

```shell
$ clang -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8 -D INTER_LINE=5
```

You just have to change BUFFER_SIZE and INTER_LINE according to your interests.

### Set OPEN_MAX

Depending on your operating system, you can modify the definition of OPEN_MAX. If you want to know the limit of open files that your operating system can support, just type the following command:

```shell
$ ulimit -n
```

With these additional details, users will have a better understanding of how to compile the `get_next_line` project with different settings and how to set OPEN_MAX according to their operating system's capabilities.
