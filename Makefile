DEBUG?=0

ifeq (${DEBUG}, 1)
	CFLAGS=-g --std=c99
else
	CFLAGS=-O2 --std=c99
endif

all: rougelike

main.o: main.c map.h tile.h
	gcc -c ${CFLAGS} main.c

map.o: map.c map.h tile.h
	gcc -c ${CFLAGS} map.c

tile.o: tile.c tile.h
	gcc -c ${CFLAGS} tile.c

rougelike: main.o map.o tile.o
	gcc -lncurses tile.o map.o main.o -o rougelike

clean:
	rm rougelike *.o
