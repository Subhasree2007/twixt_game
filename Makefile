CC=gcc
CFLAGS=-Wall -Wextra -g

OBJ=main.o TwixtBoard.o check4links.o Win_check.o

twixt: $(OBJ)
	$(CC) $(OBJ) -o twixt

main.o: main.c TwixtBoard.h check4links.h Win_check.h
TwixtBoard.o: TwixtBoard.c TwixtBoard.h
check4links.o: check4links.c check4links.h TwixtBoard.h
Win_check.o: Win_check.c Win_check.h check4links.h

clean:
	rm -f *.o twixt
