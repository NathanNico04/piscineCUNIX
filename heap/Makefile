CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRCS = create.c add.c pop.c del.c print.c
OBJS = $(SRCS:.c=.o)

library: libheap.a

libheap.a: $(OBJS)
	ar rcs libheap.a $(OBJS)

clean:
	$(RM) $(OBJS) libheap.a
