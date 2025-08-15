# Simple shell
## 📌 Description
This project is a custom shell named hsh for Holberton shell.
It was developed as out fourth group project at Holberton School with the goal to reinforce everything we saw for the C language, all within a peer programming environment.

## 🚀 Getting Started
### ✅ Prerequisites
- GCC (version 13.3.0 or higher recommended)
- Make (optional, for easier compilation)
- Unix-like OS (tested on [![Arch Linux](https://img.shields.io/badge/Arch-1793D1?logo=arch-linux&logoColor=fff)](#), [![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?logo=ubuntu&logoColor=white)](#) and [![Windows](https://custom-icon-badges.demolab.com/badge/Windows-0078D6?logo=windows11&logoColor=white)](#)).

### 🛠️ Technologies Used
[![C](https://img.shields.io/badge/C-00599C?logo=c&logoColor=white)](#)
[![GitHub](https://img.shields.io/badge/GitHub-%23121011.svg?logo=github&logoColor=white)](#)
[![GCC](https://img.shields.io/badge/gcc-13.3.0-blue)](#)


## 📥 Installation

1. **Clone the repository:**
   ```sh
   git clone https://github.com/ofest/holbertonschool-simple_shell
   cd holbertonschool-simple_shell
   ```

2. **Compile the source files with makefile:**
   ```sh
   make
   ```
   This will generate an executable named `hsh`.
3. **Create an alias (optional)**
    You can create an alias to reach easier hsh.

    For a temporary alias (reset after reboot) :
    ```shell
    alias hsh=/<path to the directory>./hsh
    ```

    For a permanent alias you have to open your `~/bashrc` or `~/zshrc` file depending on what you're using, then, at the end of the file add :
    ```shell
    alias hsh=/<path to the directory>./hsh
    ```
4. **Clean the object files from the directory:**
   ```shell
   make clean
   ```

## 💡 Usage
1. **Interactive mode**
    - You can use `./hsh` to enter interactive mode.
    - You can exit hsh whit the shortcut `ctrl + d` or with the command `exit`.
2. **Not interactive mode**
    You can pass commands through hsh like :
    ```shell
    echo "ls" | ./hsh
    ```

## 📁 Project Structure
```txt
.
├── AUTHORS
├── LICENSE
├── README.md
├── arg_counter.c
├── arg_filler.c
├── execute_command.c
├── handle_builtins.c
├── main.c
├── main.h
├── man_1_simple_shell
└── path_checker.c
```

## 👥 Authors
- [Daniel R.](https://github.com/ofest)
- [Franck S.](https://github.com/Franck-dev-hub)

## 📜 License
This project is licensed under the GNU GPL v3.0. See the LICENSE.txt file for details.

## <a href="https://www.holbertonschool.com" target="_blank" rel="noopener noreferrer" style="display: inline-flex; align-items: center; gap: 6px;"><img src="https://cdn.prod.website-files.com/6105315644a26f77912a1ada/611e13a82c74407dfebd313f_semi-logo-holberton-01.svg" alt="Holberton" width="24" height="24" style="vertical-align: middle;" /></a> Acknowledgments
Made with love for [Holberton](https://www.holbertonschool.com/) bisous.
