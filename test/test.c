#include <ncurses.h>

int main()
{	
	initscr();			/* Start curses mode 		  */
	
	char a[9];
	int i;
	for (i=0;i<9;i++){
		a[i]=' ';
	}
	a[2]='x';
	printw("|%c|%c|%c|\n",a[0],a[1],a[2]);
//	refresh();
	printw("|%c|%c|%c|\n",a[3],a[4],a[5]);
//	refresh();
	printw("|%c|%c|%c|\n",a[6],a[7],a[8]);
	refresh();
	getch();
	clear();
	printw("ewafewafew\n");
	printw("feffffff\n");
	getch();
	clear();	
	
	
	
	
	getch();
	endwin();			/* End curses mode		  */

	return 0;
}
