CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRCS = tic_tac.c result_tic_tac.c
OBJS = $(SRCS:.c=.o)

library: libtictac.a

libtictac.a: $(OBJS)
	ar rcs libtictac.a $(OBJS)

clean:
	$(RM) $(OBJS) libtictac.a
