CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRCS = rbtree.c print.c
OBJS = $(SRCS:.c=.o)

library: libredblacktree.a

libredblacktree.a: $(OBJS)
	ar rcs libredblacktree.a $(OBJS)

clean:
	$(RM) $(OBJS) libredblacktree.a
