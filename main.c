#include <ncurses.h>

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
	while(running) {
		clear();
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
