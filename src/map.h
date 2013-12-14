/**************************
 * map.h
 * (c) 2013 Daniel Burgener
 * Map
 **************************/

#ifndef MAP_H
#define MAP_H

#include "tile.h"

#define MAX_WIDTH 40
#define MAX_HEIGHT 20

typedef tile_t map_t[MAX_HEIGHT][MAX_WIDTH];

map_t *gen_map();
void print_map(map_t);

#endif

