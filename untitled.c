#include <stdio.h>
#include <ncurses.h>
#include <time.h>
char input_char;
int rat_num;
int input_num;
void help_game();
void start_select();
void start_game();
void printtt();
int select;
char a[9];
void quit();
int score = 0;
int fail = 0;
char quit_char='a';
int main()
{
	initscr();
	//raw();
	noecho();	
	start_select();
	clear();
	printw("game over");
	refresh();
	getch();
	endwin();
	return 0;
}

void start_select(){
	clear();
	printw("please select number :\n");
	printw("1 : start game\n");
	printw("2 : game help \n");
	printw("3 : quit game \n");
	refresh();
	char csel;

	csel=getch();
	
	if (csel=='1'){
		start_game();
	}else if (csel == '2'){
		help_game();
	}else{
		printw("quit");
		getch();
		quit();
	}
}

void help_game(){
	clear();
	printw("when the rat appears ,\nhit the Num keyboard '1~9' !,\nThen the rat get hurt and hide ~\n");
	printw("Hit ANY key to exit help");	
	refresh();
	getchar();
	start_select();
}

void start_game(){
	while(quit_char!='q')
	{
		int i;
		for (i=0;i<10;i++)
		{
			a[i]='_';
		}
		printtt();
		srand(time(NULL));
		rat_num=rand()%9;
		a[rat_num] = 'x';
		printtt();
		input_char=getch();
		quit_char=input_char;
		input_num = input_char-'0';
		if ((rat_num+1) ==input_num){
			a[rat_num]='_';
			score++;
		}else
		{
			fail++;
		}
		printtt();	
			
	}
}
void printtt(){
	clear();
	printw("|%c|%c|%c|\n",a[6],a[7],a[8]);
	refresh();
	printw("|%c|%c|%c|\n",a[3],a[4],a[5]);
	refresh();
	printw("|%c|%c|%c|\n",a[0],a[1],a[2]);
	printw("\n\n\nscore is %d\nyou failed %d times\nhit 'q' to quit game! ",score,fail);
	refresh();
}
void quit(){
	endwin();
}
