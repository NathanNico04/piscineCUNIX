CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
AR = ar
ARFLAGS = rcs

LIB = libgtree.a
OBJ = gtree.o print.o serialize.o

library: $(LIB)

$(LIB): $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

clean:
	$(RM) $(OBJ) $(LIB)

.PHONY: library clean
