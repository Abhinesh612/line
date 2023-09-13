CC=gcc
CFLAGS=-g -Wall -Wextra -pedantic -Werror -std=c11
CLIBS=-lm
SOURCE=$(wildcard ./*.c)
OBJECT=$(SOURCE:.c=.o)
EXEC=line


$(EXEC) : $(OBJECT)
	$(CC) $(CLIBS) $(OBJECT) -o $(EXEC)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC)
