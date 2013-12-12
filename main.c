/**************************
 * main.c
 * (c) 2013 Daniel Burgener
 * Main game loop
 **************************/

#include <ncurses.h>

#include "map.h"

int main()
{
	int running = 1;
	int c;
	int xLoc = 30;
	int yLoc = 10;

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
			case 'h':
				xLoc -= 1;
				break;
			case 'j':
				yLoc -= 1;
				break;
			case 'k':
				yLoc += 1;
				break;
			case 'l':
				xLoc += 1;
				break;
			default:
				break;
		}		
	}
	endwin();
	return 0;
}
