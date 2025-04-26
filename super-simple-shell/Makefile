CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = hsh

.PHONY: all clean betty

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(NAME)

betty:
	betty *.c *.h

