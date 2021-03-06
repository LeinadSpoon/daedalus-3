OBJS = src/tile.o src/log.o src/player.o src/items.o src/interact.o src/map.o src/main.o

DEBUG?=0

CFLAGS=--std=c99 -Wall -fstack-protector-strong

ifeq (${DEBUG}, 1)
	CFLAGS+=-g
else
	CFLAGS+=-O2
endif

TILE_DEPS = src/tile.h
MAP_DEPS = src/map.h ${TILE_DEPS}
LOG_DEPS = src/log.h
PLAYER_DEPS = src/player.h ${MAP_DEPS}
ITEMS_DEPS = src/items.h ${PLAYER_DEPS}
INTERACT_DEPS = src/interact.h ${MAP_DEPS} ${TILE_DEPS} ${LOG_DEPS}
MAIN_DEPS = ${MAP_DEPS} ${TILE_DEPS} ${INTERACT_DEPS} ${PLAYER_DEPS}

all: rougelike

src/main.o: src/main.c ${MAIN_DEPS}
	gcc -c ${CFLAGS} src/main.c -o src/main.o

src/map.o: src/map.c ${MAP_DEPS}
	gcc -c ${CFLAGS} src/map.c -o src/map.o

src/tile.o: src/tile.c ${TILE_DEPS}
	gcc -c ${CFLAGS} src/tile.c -o src/tile.o

src/log.o: src/log.c ${LOG_DEPS}
	gcc -c ${CFLAGS} src/log.c -o src/log.o

src/player.o: src/player.c ${PLAYER_DEPS}
	gcc -c ${CFLAGS} src/player.c -o src/player.o

src/items.o: src/items.c ${ITEMS_DEPS}
	gcc -c ${CFLAGS} src/items.c -o src/items.o

src/interact.o: src/interact.c ${INTERACT_DEPS}
	gcc -c ${CFLAGS} src/interact.c -o src/interact.o

rougelike: ${OBJS}
	gcc -lncurses ${OBJS} -o daedalus-3

clean:
	rm -f daedalus-3 src/*.o
