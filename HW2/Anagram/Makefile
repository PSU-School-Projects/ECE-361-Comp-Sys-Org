# Windows Cross-Compiler
CC = x86_64-w64-mingw32-gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable (Windows executable)
TARGET = anagram.exe

# Source files
SRCS = main.c helperFuncs.c ../libs/lineHelper.c

# Object files (derived from source files)
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to link object files and create the final Windows executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up the build
clean:
	rm -f $(OBJS) $(TARGET)
