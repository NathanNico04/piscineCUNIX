CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

all: csv

csv: csv.c
	$(CC) $(CFLAGS) csv.c -o csv

clean:
	$(RM) csv

