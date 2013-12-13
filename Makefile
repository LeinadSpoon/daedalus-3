DEBUG?=0

ifeq (${DEBUG}, 1)
	CFLAGS=-g --std=c99
else
	CFLAGS=-O2 --std=c99
endif

TILE_DEPS = tile.h
MAP_DEPS = map.h ${TILE_DEPS}
INTERACT_DEPS = interact.h ${MAP_DEPS} ${TILE_DEPS}
MAIN_DEPS = ${MAP_DEPS} ${TILE_DEPS} ${INTERACT_DEPS}

all: rougelike

main.o: main.c ${MAIN_DEPS}
	gcc -c ${CFLAGS} main.c

map.o: map.c ${MAP_DEPS}
	gcc -c ${CFLAGS} map.c

tile.o: tile.c ${TILE_DEPS}
	gcc -c ${CFLAGS} tile.c

interact.o: interact.c ${INTERACT_DEPS}
	gcc -c ${CFLAGS} interact.c

rougelike: main.o map.o tile.o interact.o
	gcc -lncurses tile.o interact.o map.o main.o -o rougelike

clean:
	rm rougelike *.o
