/**************************
 * main.c
 * (c) 2013 Daniel Burgener
 * Main game loop
 **************************/

#include <ncurses.h>

#include "map.h"
#include "interact.h"
#include "player.h"

int main()
{
	int running = 1;
	int c;
	player_t pl = { 30, 10, 10, 10 };

	initscr();
	clear();
	noecho();
	cbreak();
	map_t *cur_map = gen_map();
	while(running) {
		clear();
		print_map(*cur_map);
		mvprintw(pl.yPos,pl.xPos,"@");
		refresh();
		c = getch();
		switch (c) {
			case 'q':
				running = 0;
				break;
			case 'y':
				move_player(&pl,cur_map,-1,-1);
				break;
			case 'u':
				move_player(&pl,cur_map,1,-1);
				break;
			case 'o':
				open_door(cur_map,pl.xPos,pl.yPos);
				break;
			case 'h':
				move_player(&pl,cur_map,-1,0);
				break;
			case 'j':
				move_player(&pl,cur_map,0,1);
				break;
			case 'k':
				move_player(&pl,cur_map,0,-1);
				break;
			case 'l':
				move_player(&pl,cur_map,1,0);
				break;
			case 'c':
				close_door(cur_map,pl.xPos,pl.yPos);
				break;
			case 'b':
				move_player(&pl,cur_map,-1,1);
				break;
			case 'n':
				move_player(&pl,cur_map,1,1);
				break;
			default:
				continue;
		}
	}
	endwin();
	return 0;
}
