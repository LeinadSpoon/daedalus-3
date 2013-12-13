/**************************
 * map.c
 * (c) 2013 Daniel Burgener
 * Map
 **************************/

#include <ncurses.h>
#include <stdlib.h>

#include "map.h"

// Generate a map.
// For now it just generates a big floor with a wall and a door in the middle.
map_t *gen_map() {
	// Let's just start with a static map for now.
	map_t *map = malloc(sizeof(map_t));

	// Initialize to all floors
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			(*map)[i][j] = FLOOR_TILE;
		}
	}

	//Put in a wall
	(*map)[15][15] = WALL_TILE;
	(*map)[15][16] = WALL_TILE;
	(*map)[15][17] = WALL_TILE;
	(*map)[15][18] = CLOSED_DOOR_TILE;
	(*map)[15][19] = WALL_TILE;
	(*map)[15][20] = WALL_TILE;
	(*map)[15][21] = WALL_TILE;

	return map;
}

// Print a map
void print_map(map_t map) {
	for (int i = 0; i < MAX_HEIGHT; i++) {
		for (int j = 0; j < MAX_WIDTH; j++) {
			mvaddch(i,j,map[i][j].disp);
		}
	}
}
