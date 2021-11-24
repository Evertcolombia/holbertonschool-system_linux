CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g3

RC = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRC))
LIBS = $(patsubst %.c, %.o, helpers.c)
0 = $(patsubst %.c, %.o, $(wildcard 0-*.c)) $(LIBS)

.PHONY: strace_0 clean

strace_0: $(0)
		$(CC) $(CFLAGS) $(0) -o strace_0

clean:
		rm -f $(OBJS) strace_*
