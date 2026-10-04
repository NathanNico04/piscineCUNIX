CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
LDLIBS = -lm

SRCS = my_price.c compute_price.c compute_quantity.c
OBJS = $(SRCS:.c=.o)
TARGET = my_price

$(TARGET): $(OBJS)

clean:
	$(RM) $(OBJS) $(TARGET)
