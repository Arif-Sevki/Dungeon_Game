CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = Run
SRC = dungeon.c enemy.c item.c main.c map.c player.c room.c
OBJ = $(SRC:.c=.o)

# Rules
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)