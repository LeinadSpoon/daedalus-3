DEBUG?=0

ifeq (${DEBUG}, 1)
	CFLAGS=-g --std=c99
else
	CFLAGS=-O2 --std=c99
endif

TILE_DEPS = src/tile.h
MAP_DEPS = src/map.h ${TILE_DEPS}
INTERACT_DEPS = src/interact.h ${MAP_DEPS} ${TILE_DEPS}
MAIN_DEPS = ${MAP_DEPS} ${TILE_DEPS} ${INTERACT_DEPS}

all: rougelike

src/main.o: src/main.c ${MAIN_DEPS}
	gcc -c ${CFLAGS} src/main.c -o src/main.o

src/map.o: src/map.c ${MAP_DEPS}
	gcc -c ${CFLAGS} src/map.c -o src/map.o

src/tile.o: src/tile.c ${TILE_DEPS}
	gcc -c ${CFLAGS} src/tile.c -o src/tile.o

src/interact.o: src/interact.c ${INTERACT_DEPS}
	gcc -c ${CFLAGS} src/interact.c -o src/interact.o

rougelike: src/main.o src/map.o src/tile.o src/interact.o
	gcc -lncurses src/tile.o src/interact.o src/map.o src/main.o -o rougelike

clean:
	rm rougelike src/*.o
