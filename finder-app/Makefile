# Makefile for the writer application
# Define the compiler based on the CROSS_COMPILE variable.
# If CROSS_COMPILE is not set, it defaults to the native gcc.
CC ?= $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror -g

# Define the source file and the resulting executable.
SRCS = writer.c
EXEC = writer

# The default target. It depends on the executable.
all: $(EXEC)

#Rule to build the executable from the source file.
# We use the defined compiler and include necessary libraries (if any).
$(EXEC): $(SRCS)
	$(CC) $(SRCS) -o $(EXEC) $(CFLAGS)

# The clean target to remove built files.
clean:
	rm -f $(EXEC) *.o

# Phony targets prevent conflicts with files of the same name.
.PHONY: all clean
