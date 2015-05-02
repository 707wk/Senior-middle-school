#include <ncurses.h>

int main(void){
	initscr();
	printw("Hello World!\n");
	refresh();
	getchar();
	endwin();
	return 0;
}

