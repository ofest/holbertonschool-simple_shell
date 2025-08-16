# Simple Shell Makefile
# This Makefile compiles the Holberton Simple Shell project

# Compiler and flags
CC = gcc
# Compilation flags required by Holberton School
# -Wall: Enable all warnings
# -Werror: Treat warnings as errors
# -Wextra: Enable extra warnings
# -pedantic: Strict ISO C compliance
# -std=gnu89: Use GNU C89 standard
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Target executable name
TARGET = hsh

# Source files (all .c files in the project)
SOURCES = main.c execute_command.c path_checker.c handle_builtins.c arg_filler.c arg_counter.c _strdup.c

# Object files (generated from source files)
# $(SOURCES:.c=.o) converts all .c files to .o files
OBJECTS = $(SOURCES:.c=.o)

# Phony targets (targets that don't represent files)
.PHONY: all clean fclean re

# Default target: build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile source files to object files
# $< represents the first dependency (the .c file)
# $@ represents the target (the .o file)
%.o: %.c main.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJECTS)

# Remove object files and executable (full clean)
fclean: clean
	rm -f $(TARGET)

# Rebuild everything (clean and rebuild)
re: fclean all
