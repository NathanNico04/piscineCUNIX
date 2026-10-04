CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

main: main.o
	$(CC) $(FLAGS) -o $@ $^

debug: CFLAGS += -fsanitize=address -g
debug: LDFLAGS += -fsanitize=address -g
debug: main.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

clean:
	${RM} main.o main debug