<h1 align="center">
	<img src="https://github.com/lkilpela/42-project-badges/blob/main/badges/get_next_linee.png" />
</h1>

<p align="center">
	<b><i>A C function to read lines from a file descriptor</i></b><br>
</p>

<p align="center">
    <img alt="score" src="https://img.shields.io/badge/score-100%2F100-brightgreen" />
<p align="center">
    <img alt="solo" src="https://img.shields.io/badge/solo-yellow" />
    <img alt="estimated time" src="https://img.shields.io/badge/estimation-70%20hours-blue" />
    <img alt="XP earned" src="https://img.shields.io/badge/XP-882-orange" />
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/lkilpela/get_next_line?color=lightblue" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/lkilpela/get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/lkilpela/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/lkilpela/get_next_line?color=green" />
</p>

## 📜 About The Project

The `get_next_line` function is a useful tool for parsing files or network connections. It reads from a file descriptor and returns a line, which is defined as a string of characters terminated by '\n' (newline) or EOF (End Of File). The function is designed to be called in a loop, and each subsequent call will return the next line until there are no more lines to return.

This project is a great exercise for understanding file descriptors, buffer management, and dynamic memory allocation in C. It also provides a foundation for working with files and network connections in more complex projects.

This project was completed as a **solo project**.

## 🏁 Getting Started

## 🛠️ Installation & Setup

1. Clone the repository: `git clone https://github.com/lkilpela/get_next_line.git`
2. Navigate into the project directory: `cd get_next_line`
3. Compile the project: `make`

## 🚀 Usage

After compiling the project, you can use the `get_next_line` function to read lines from a file descriptor. Here is a basic usage example:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while (get_next_line(fd, &line) > 0)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📝 Evaluation Requirements

The `get_next_line` project was evaluated based on the following criteria:

1. **Code Quality**: The code must be clear, concise, and efficient. It should be well-organized and easy to read. The use of global variables is forbidden and the project must conform to the school's norminette rules.

2. **Functionality**: The `get_next_line` function must work correctly and handle all possible edge cases. The function should return a line ending with a newline character from a file descriptor. The library should not have any memory leaks.

3. **Compiling**: The library must compile without any errors or warnings. The project should compile with the `-Wall -Wextra -Werror` flags.

### 🧑‍💻 Peer Evaluations (3/3)

Here are some of the comments received during the peer evaluation of the `libft` project:

> **Peer 1**: "The get_next_line worked perfectly as expected. Lumi could explain her code well and how it was done. We tested it ourselves as well as with a tester and all looks to be great. Keep up the good work! :)"

> **Peer 2**: "Lumi has done an amazing job with her get_next_line. She could explain her implementation very well! Went through the code and it looked clean, there are just few things I would have done differently. Went through the eval form and it seemed to work as it should and required by the subject. All the best Lumi and keep up the great work!"

> **Peer 3**: "Lumi has done a good job. We tested her code with hand written tests and with francinette. She could explain her code very well. Well made clean code. Only thing stopping me to give outstanding for this was (char *) just before malloc that could possibly hide some errors. It is not forbidden but bad coding style. Good luck in the future!"

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/lkilpela/libft/blob/main/docs/LICENSE) file for details.
