# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Main program target
TARGET = Prob2.out

# Source files (excluding test files)
SRCS = $(filter-out ../libs/iom361_r2/test_iom361_r2.c ../libs/colors_api/test_colors.c \
../libs/SLLinkedList/test_LinkedList.c ../libs/stackADT_LL/test_stackADT_LL.c, \
$(wildcard ./*.c) $(wildcard ../libs/colors_api/*.c) $(wildcard ../libs/iom361_r2/*.c) \
$(wildcard ../libs/*.c) $(wildcard ../libs/SLLinkedList/*.c) $(wildcard ../libs/stackADT_LL/*.c))

# Object files for main program
OBJS = $(SRCS:.c=.o)

# Rule to build the main program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile each source file into an object file
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
