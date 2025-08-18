# 🐚 Holberton Simple shell
## 📌 Description
This project is a custom shell named hsh for Holberton shell.
It was developed as out fourth group project at Holberton School with the goal to reinforce everything we saw for the C language, all within a peer programming environment.

## 🚀 Getting Started
### 🛠️ Technologies Used
[![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)](#)
[![GitHub](https://img.shields.io/badge/GitHub-%23121011.svg?logo=github&logoColor=white)](#)
[![GCC](https://img.shields.io/badge/gcc-13.3.0-blue)](#)

## 🧭 Overview
`hsh` reads lines from standard input, tokenizes the input, resolves commands using the `PATH` environment variable, and executes them in child processes. It supports interactive and non-interactive modes and implements a small set of built-ins.

## ✨ Features
- Execute programs by absolute/relative path or via `PATH`
- Argument parsing separated by whitespace
- Built-ins: `exit`, `env`
- Interactive prompt: `($) `
- Non-interactive (piped or redirected) execution
- Basic error reporting for unknown commands and system call failures

### ✅ Requirements
- GCC (version 13.3.0 or higher recommended)
- Make (optional, for easier compilation)
- Unix-like OS (tested on [![Arch Linux](https://img.shields.io/badge/Arch-1793D1?logo=arch-linux&logoColor=fff)](#), [![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?logo=ubuntu&logoColor=white)](#) and [![Windows](https://custom-icon-badges.demolab.com/badge/Windows-0078D6?logo=windows11&logoColor=white)](#)).

## 🛠️ Build
```sh
git clone https://github.com/ofest/holbertonschool-simple_shell
cd holbertonschool-simple_shell
make
```
This produces an executable named `hsh` in the project root.

## ▶️ Usage
### 💬 Interactive mode
```sh
./hsh
($) ls -l
($) exit
```
Exit with Ctrl-D (EOF) or the `exit` built-in.

### 🤖 Non-interactive mode
```sh
echo "ls -l" | ./hsh
# or
./hsh < scriptfile
```

### 🔗 Optional alias
Create a convenient alias (adjust the absolute path to your clone):
```sh
alias hsh='/absolute/path/to/holbertonschool-simple_shell/hsh'
```
Persist the alias by adding the same line to your `~/.bashrc` or `~/.zshrc`.

## 🧰 Built-ins
- `exit`: terminate the shell process
- `env`: print the current environment, one variable per line

## 🚪 Exit status
- The shell process exits with code 0 on normal termination.
- Internal failures may cause an exit code of 1.

## 🔍 Examples
```sh
# Run a command from PATH
($) echo Hello
Hello

# Run with an absolute path
($) /bin/ls

# Command not found (example)
($) foo
./hsh: 1: foo: not found
```

## 📖 Man page (with colors)
To view the manual with colors support enabled:
```sh
groff -k -Tutf8 -man man_1_simple_shell | less -R
```
You can also use:
```sh
man -l man_1_simple_shell
```
(Depending on your `man`/`less` configuration, color output may vary.)

## 📁 Project Structure
```txt
.
<<<<<<< HEAD
├── AUTHORS              # Project contributors
├── LICENSE              # License (GNU GPL v3.0)
├── README.md            # Documentation
├── arg_counter.c        # Counts number of arguments in a command
├── arg_filler.c         # Splits command into tokens (fills argv array)
├── execute_command.c    # Handles fork/execvp execution of commands
├── handle_builtins.c    # Checks and executes built-in commands (exit, env, etc.)
├── main.c               # Main loop of the shell (interactive + non-interactive)
├── main.h               # Header file with prototypes, structs, and macros
├── man_1_simple_shell   # Manual page for the shell
└── path_checker.c       # Handles PATH resolution (search command in PATH dirs)
```

## Limitations:

-Does not implement advanced features like piping (|), redirection (>, <), or job control (fg, bg).
-No command history.

## 👥 Authors
- [Daniel R.](https://github.com/ofest)
- [Franck S.](https://github.com/Franck-dev-hub)

## 📜 License
This project is licensed under the GNU GPL v3.0. See the 'LICENSE' file for details.

## <a href="https://www.holbertonschool.com" target="_blank" rel="noopener noreferrer" style="display: inline-flex; align-items: center; gap: 6px;"><img src="https://cdn.prod.website-files.com/6105315644a26f77912a1ada/611e13a82c74407dfebd313f_semi-logo-holberton-01.svg" alt="Holberton" width="24" height="24" style="vertical-align: middle;" /></a> Acknowledgments
Made with love for [Holberton](https://www.holbertonschool.com/) bisous.
