/**************************
 * interact.c
 * (c) 2013 Daniel Burgener
 * Functions for interacting with the environment
 **************************/

#include "interact.h"
#include "ncurses.h"

static void get_adjacent_target(int xPos_in, int yPos_in, int *xPos_out, int *yPos_out)
{
	int c = getch();

	switch (c) {
		case 'y':
			*xPos_out=xPos_in-1;
			*yPos_out=yPos_in-1;
			break;
		case 'u':
			*xPos_out=xPos_in+1;
			*yPos_out=yPos_in-1;
			break;
		case 'h':
			*xPos_out=xPos_in-1;
			*yPos_out=yPos_in;
			break;
		case 'j':
			*xPos_out=xPos_in;
			*yPos_out=yPos_in-1;
			break;
		case 'k':
			*xPos_out=xPos_in;
			*yPos_out=yPos_in+1;
			break;
		case 'l':
			*xPos_out=xPos_in+1;
			*yPos_out=yPos_in;
			break;
		case 'b':
			*xPos_out=xPos_in-1;
			*yPos_out=yPos_in+1;
			break;
		case 'n':
			*xPos_out=xPos_in+1;
			*yPos_out=yPos_in+1;
			break;
		default:
			*xPos_out=xPos_in;
			*yPos_out=yPos_in;
	}
}

void open_door(map_t *cur_map, int xPos, int yPos)
{
	int xTar,yTar;

	get_adjacent_target(xPos,yPos,&xTar,&yTar);
	if ((*cur_map)[xTar][yTar].type == CLOSED_DOOR) {
		(*cur_map)[xTar][yTar] = OPEN_DOOR_TILE;
	}
}

void close_door(map_t *cur_map, int xPos, int yPos)
{
	int xTar,yTar;

	get_adjacent_target(xPos,yPos,&xTar,&yTar);
	if ((*cur_map)[xTar][yTar].type == OPEN_DOOR) {
		(*cur_map)[xTar][yTar] = CLOSED_DOOR_TILE;
	}
}
