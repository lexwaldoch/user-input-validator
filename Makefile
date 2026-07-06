CC=gcc
CFLAGS=-Wall -Wextra

all:
	$(CC) $(CFLAGS) src/main.c src/functions.c -o validator

clean:
	rm -f validator
