/**************************
 * tile.h
 * (c) 2013 Daniel Burgener
 * Map tiles
 **************************/

#ifndef TILE_H
#define TILE_H

typedef enum {WALL, FLOOR, OPEN_DOOR, CLOSED_DOOR} tile_type;

typedef struct tile {
	int passable;
	char disp;
	tile_type type;
} tile_t;

extern const tile_t WALL_TILE;
extern const tile_t FLOOR_TILE;
extern const tile_t OPEN_DOOR_TILE;
extern const tile_t CLOSED_DOOR_TILE;

#endif
