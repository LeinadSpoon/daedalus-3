/**************************
 * interact.h
 * (c) 2013 Daniel Burgener
 * Functions for interacting with the environment
 **************************/

#include "map.h"
#include "tile.h"

void open_door(map_t *cur_map, int xPos, int yPos);

void close_door(map_t *cur_map, int xPos, int yPos);
