
CC = gcc
CFLAGS = -std=c99 -pedantic -Werror -Wall -Wextra -Wvla
AR = ar
ARFLAGS = rcs
 
SRC = size.c \
      height.c \
      dfs_print_prefix.c \
      dfs_print_infix.c \
      dfs_print_postfix.c \
      is_perfect.c \
      is_complete.c \
      is_degenerate.c \
      is_full.c \
      is_bst.c
 
OBJ = $(SRC:.c=.o)
 
NAME = libbinary_tree.a
 
library: $(NAME)
 
$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
 
%.o: %.c binary_tree_dynamic.h
	$(CC) $(CFLAGS) -c $< -o $@
 
clean:
	rm -f $(OBJ) $(NAME)
 
