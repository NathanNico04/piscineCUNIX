CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRCS = dlist.c
OBJS = $(SRCS:.c=.o)

library: libdlist.a

libdlist.a: $(OBJS)
	ar rcs libdlist.a $(OBJS)

clean:
	$(RM) $(OBJS) libdlist.a
