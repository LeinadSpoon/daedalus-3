/**************************
 * player.h
 * (c) 2013 Daniel Burgener
 * The character
 **************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "map.h"

typedef struct player {
	int xPos;
	int yPos;
	int curHealth;
	int maxHealth;
} player_t;

void move_player(player_t *player, map_t *cur_map, int deltaX, int deltaY);

#endif

