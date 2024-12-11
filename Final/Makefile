# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Source files
SRCS = main_app.c functions.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = program.exe

# Default target
all: $(TARGET)

# Linking step
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compilation step
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)


