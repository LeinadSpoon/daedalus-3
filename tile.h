/**************************
 * tile.h
 * (c) 2013 Daniel Burgener
 * Map tiles
 **************************/

#ifndef TILE_H
#define TILE_H

typedef struct tile {
	int passable;
	char disp;
} tile_t;

extern const tile_t WALL;
extern const tile_t FLOOR;

#endif
