/**************************
 * interact.c
 * (c) 2013 Daniel Burgener
 * Functions for interacting with the environment
 **************************/

#include "interact.h"
#include "ncurses.h"
#include "log.h"

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
	gamelog("open door called with %d and %d\n",xPos, yPos);
	int xTar,yTar;

	get_adjacent_target(xPos,yPos,&xTar,&yTar);

	gamelog("The adjacent target was %d and %d\n",xTar, yTar);

	if ((*cur_map)[yTar][xTar].type == CLOSED_DOOR) {
		(*cur_map)[yTar][xTar] = OPEN_DOOR_TILE;
	}
}

void close_door(map_t *cur_map, int xPos, int yPos)
{
	int xTar,yTar;

	get_adjacent_target(xPos,yPos,&xTar,&yTar);
	if ((*cur_map)[yTar][xTar].type == OPEN_DOOR) {
		(*cur_map)[yTar][xTar] = CLOSED_DOOR_TILE;
	}
}
