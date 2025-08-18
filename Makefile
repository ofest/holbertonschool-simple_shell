# Simple shell Makefile
# This Makefile compiles the Holberton Simple Shell project

# Compiler and flags
CC = gcc

# Compilation flags
# -Wall -> Enable al warnings
# -Werror -> Treat warnings as errors
# -Wextra -> Enable extra warnings
# -pedantic -> Strict ISO C compliance
# -std=gnu89 -> Use GNU C89 standard
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

# Target executable name
TARGET = hsh

# Source files
SOURCES = $(wildcard *.c)

# Object files
OBJECTS = $(SOURCES:.c=.o)

# Phony targets (targets that don't represent files)
.PHONY: all clean fclean re help

# Default target: build the executable
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

# Compile source files to object files
# $< represents the first dependency (the .c file)
# $@ represents the target (the .o file)
%.o: %.c shell.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJECTS)

# Remove object files and executable
fclean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything (clean and rebuild)
re: clean all

help:
	@echo "Commands allowed :"
	@echo "make -> Build project"
	@echo "make clean -> Remove objects"
	@echo "make fclean -> Remove objects + executable"
	@echo "make re -> Clean and Rebuild"
	@echo "make help -> For help"
