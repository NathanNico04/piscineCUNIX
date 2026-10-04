CC = gcc
CLFAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla

SRC= sieve.c
OBJ = sieve.o

all: $(OBJ)

$(OBJ): $(SRC)
	$(CC) $(CLFAGS) -c $(SRC) -o $(OBJ)

clean: 
	rm -f $(OBJ)
