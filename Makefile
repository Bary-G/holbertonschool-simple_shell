CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89
SRC = shell.c exec_cmd.c prompt.c
OBJ = $(SRC:.c=.o)
TARGET = hsh

all: $(TARGET)

$(TARGET): $(OBJ)
$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
$(CC) $(CFLAGS) -c $< -o $@

clean:
rm -f $(OBJ) $(TARGET)

fclean: clean
rm -f $(TARGET)

re: fclean all

