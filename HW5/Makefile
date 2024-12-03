# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Main program target
TARGET = tempHumLogger.out

# Source files (excluding test files)
SRCS = $(filter-out ./libs/iom361_r2/test_iom361_r2.c ./libs/random_float_generator/test_float_rndm.c, \
$(wildcard ./*.c)  $(wildcard ./libs/iom361_r2/*.c) \
$(wildcard ./libs/*.c) $(wildcard ./libs/random_float_generator/*.c))

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
