# Makefile for the writer application
# Define the compiler based on the CROSS_COMPILE variable.
# If CROSS_COMPILE is not set, it defaults to the native gcc.
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror -g

# Target executable
TARGET := writer

# Source files
SRCS := writer.c
OBJ := $(SRCS:.c=.o)

# The default target: build writer
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# The clean target to remove built files.
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets prevent conflicts with files of the same name.
.PHONY: all clean
