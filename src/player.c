/**************************
 * player.c
 * (c) 2013 Daniel Burgener
 * The character
 **************************/

#include "player.h"

void move_player(player_t *player, map_t *cur_map, int deltaX, int deltaY) {
	if (deltaX != 0 || deltaY != 0) {
		if ((*cur_map)[player->yPos+deltaY][player->xPos+deltaX].passable) {
				player->xPos += deltaX;
				player->yPos += deltaY;
			}
	}
}

