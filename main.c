/**************************
 * main.c
 * (c) 2013 Daniel Burgener
 * Main game loop
 **************************/

#include <ncurses.h>

#include "map.h"
#include "interact.h"

int main()
{
	int running = 1;
	int c;
	int xLoc = 30;
	int yLoc = 10;
	int xMov = 0;
	int yMov = 0;

	initscr();
	clear();
	noecho();
	cbreak();
	map_t *cur_map = gen_map();
	while(running) {
		clear();
		print_map(*cur_map);
		mvprintw(yLoc,xLoc,"@");
		refresh();
		c = getch();
		switch (c) {
			case 'q':
				running = 0;
				break;
			case 'y':
				xMov = -1;
				yMov = -1;
				break;
			case 'u':
				xMov = 1;
				yMov = -1;
				break;
			case 'o':
				open_door(cur_map,xLoc,yLoc);
				break;
			case 'h':
				xMov = -1;
				break;
			case 'j':
				yMov = -1;
				break;
			case 'k':
				yMov = 1;
				break;
			case 'l':
				xMov = 1;
				break;
			case 'c':
				close_door(cur_map,xLoc,yLoc);
				break;
			case 'b':
				xMov = -1;
				yMov = 1;
				break;
			case 'n':
				xMov = 1;
				yMov = 1;
				break;
			default:
				continue;
		}
		if (xMov != 0 || yMov != 0) {
			if ((*cur_map)[yLoc+yMov][xLoc+xMov].passable) {
				xLoc += xMov;
				yLoc += yMov;
			}
			xMov = 0;
			yMov = 0;
		}
	}
	endwin();
	return 0;
}
