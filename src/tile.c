/**************************
 * tile.c
 * (c) 2013 Daniel Burgener
 * Map tiles
 **************************/

#include "tile.h"

const tile_t WALL_TILE = {0,'#',WALL};
const tile_t FLOOR_TILE = {1,'.',FLOOR};
const tile_t OPEN_DOOR_TILE = {1,'\'',OPEN_DOOR};
const tile_t CLOSED_DOOR_TILE = {0,'+',CLOSED_DOOR};
