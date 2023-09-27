## get_next_line

### 📜 Project Overview

The `get_next_line` project is an essential tool for C programmers. It provides a function for reading one line at a time from a file descriptor, offering a deep dive into file I/O in the C programming language.

### 🌟 Key Features

- Efficiently reads text from files or streams, one line at a time.
- Supports multiple file descriptors simultaneously.
- Handles memory allocation dynamically.
- Ensures modular and maintainable code.

### 🚀 How to Use

To use `get_next_line`, follow these steps:

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

### 🛠️ Compilation

#### Standard Configuration

To compile with default settings, use the following command:

```shell
$ clang -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8
```

You can modify BUFFER_SIZE as needed.

#### Additional Features 🚀

For extra features, compile with this command:

```shell
$ clang -Wall -Werror -Wextra *.c -D BUFFER_SIZE=8 -D INTER_LINE=5
```

You can customize both BUFFER_SIZE and INTER_LINE.

### 💡 Additional Information

Depending on your operating system, you may need to adjust the definition of OPEN_MAX. To find the limit of open files your operating system can support, use the following command:

```shell
$ ulimit -n
```
