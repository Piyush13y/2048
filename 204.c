/*********************************************************************************
 * This program includes 2048 and motoGT; games developed for recreational purpose
 * and as a part of project.
 * Copyright (C) 2015 Piyush Yadav piyush13y@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *********************************************************************************/

#include<ncurses.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<menu.h>
#include "grid.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
static int q = 0;
int main(int qw);
int dup_check();
int score = 0;
int res_flag = 1;
void initial();
char game_over(int g);
void difficulty();
void easy_game();
void hard_game();
void back();
void instructions();
void move_left(grid *g, int * flag1, int * score);
void randm();
void print_board(grid *g, int score);
void acw_rotate(grid *g);
void move_right(grid *g, int * flag1, int * score);
void move_up(grid *g, int * flag1, int * score);
void move_down(grid *g, int * flag1, int * score);
int start_game();
int menu();
int banner(int qq);
void resume_game();
FILE *fp;
int kk = 0, flag1 = 0;
static int res = 0;
grid g;

void main_call() {
	main(2);
}
char *choices[] = {
                        "     START GAME       ",
                        "     RESUME GAME      ",
                        "   DIFFICULTY LEVEL   ",
                        "     INSTRUCTIONS     ",
                        "      MAIN MENU       ",
                        "         Exit       ",
                        (char *)NULL,
                  };
char *choices1[] = {
                        "     EASY       ",
                        "     HARD       ",
                        "     BACK       ",
			(char *)NULL,
                  };
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);

int mains() {
	g.size = 4;
	initscr();
	noecho();
	banner(1);
	curs_set(0);
	clear();
	menu();
	getch();
	printf("Main finished\n");
	return 0;
}
/* Prints 2048 banner */
int banner(int qq) {
	int i = 0, j = 0;
	int x1 = 0;
	int y1 = 16;
	q++;
	if(qq == 1 || qq == 2){
		y1 = 5;
		x1 = 74;
	} 
	while(i < 8) {
		initscr();
		start_color();
		init_pair(1,1,7);
		init_pair(2,7,1);
		init_pair(3,1,COLOR_BLACK);
		init_pair(4, COLOR_BLACK, COLOR_RED);
		wbkgd(stdscr, COLOR_PAIR(3));
		if(qq == 1 || qq == 2)
			x1 = 73;
		else 
			x1 = 128;

		attrset(COLOR_PAIR(1));
		if(j % 2 == 0)
			attron(A_BOLD);
		else 
			attroff(A_BOLD);

		mvprintw(y1+2,x1-7,"*");
		mvprintw(y1+1,x1-7,"*");
		mvprintw(y1,x1-7,"*");
		mvprintw(y1+3,x1-7,"*");
		mvprintw(y1+4,x1-7,"*");
		mvprintw(y1+2,x1-6,"*");
		mvprintw(y1+2,x1-5,"*");
		mvprintw(y1+2,x1-8,"*");
		mvprintw(y1+2,x1-9,"*");
		mvprintw(y1+1,x1-6,"*");
		mvprintw(y1,x1-5,"*");
		mvprintw(y1+1,x1-8,"*");
		mvprintw(y1,x1-9,"*");
		mvprintw(y1+3,x1-8,"*");
		mvprintw(y1+4,x1-9,"*");
		mvprintw(y1+4,x1-5,"*");
		mvprintw(y1+3,x1-6,"*");

		if(i == 0 && (qq == 1 || qq == 3)) {
			usleep(700000);
			refresh();
		}

		mvprintw(y1,x1,"*");
		mvprintw(y1,x1+1,"*");
		mvprintw(y1,x1+2,"*");
		mvprintw(y1+1,x1+2,"*");
		mvprintw(y1+2,x1+2,"*");
		mvprintw(y1+2,x1+1,"*");
		mvprintw(y1+2,x1,"*");
		mvprintw(y1+3,x1,"*");
		mvprintw(y1+4,x1,"*");
		mvprintw(y1+4,x1+1,"*");
		mvprintw(y1+4,x1+2,"*");

		if(i == 0 && (qq == 1 || qq == 3)) {
			usleep(700000);
			refresh();
		}
		mvprintw(y1,x1+4,"*");
		mvprintw(y1,x1+5,"*");
		mvprintw(y1,x1+6,"*");
		mvprintw(y1+1,x1+6,"*");
		mvprintw(y1+2,x1+6,"*");
		mvprintw(y1+3,x1+6,"*");
		mvprintw(y1+4,x1+6,"*");
		mvprintw(y1+4,x1+5,"*");
		mvprintw(y1+4,x1+4,"*");
		mvprintw(y1+3,x1+4,"*");
		mvprintw(y1+2,x1+4,"*");
		mvprintw(y1+1,x1+4,"*");
		mvprintw(y1,x1+4,"*");

		if(i == 0 && (qq == 1 || qq == 3)) {
			usleep(700000);
			refresh();
		}
		mvprintw(y1,x1+8,"*");
		mvprintw(y1+1,x1+8,"*");
		mvprintw(y1+2,x1+8,"*");
		mvprintw(y1+2,x1+9,"*");
		mvprintw(y1+2,x1+10,"*");
		mvprintw(y1+3,x1+10,"*");
		mvprintw(y1+4,x1+10,"*");
		mvprintw(y1,x1+10,"*");
		mvprintw(y1+1,x1+10,"*");

		if(i == 0 && (qq == 1 || qq == 3)) {
			usleep(700000);
			refresh();
		}
		mvprintw(y1,x1+12,"*");
		mvprintw(y1,x1+13,"*");
		mvprintw(y1,x1+14,"*");
		mvprintw(y1+1,x1+14,"*");
		mvprintw(y1+2,x1+14,"*");
		mvprintw(y1+3,x1+14,"*");
		mvprintw(y1+4,x1+14,"*");
		mvprintw(y1+4,x1+13,"*");
		mvprintw(y1+4,x1+12,"*");
		mvprintw(y1+3,x1+12,"*");
		mvprintw(y1+2,x1+12,"*");
		mvprintw(y1+1,x1+12,"*");
		mvprintw(y1,x1+12,"*");
		mvprintw(y1+2,x1+13,"*");
		x1 = x1 + 26;

		if(i == 0 && (qq == 1 || qq == 3)) {
			usleep(700000);
			refresh();
		}
		mvprintw(y1+2,x1-5,"*");
		mvprintw(y1+1,x1-5,"*");
		mvprintw(y1,x1-5,"*");
		mvprintw(y1+3,x1-5,"*");
		mvprintw(y1+4,x1-5,"*");
		mvprintw(y1+2,x1-4,"*");
		mvprintw(y1+2,x1-3,"*");
		mvprintw(y1+2,x1-6,"*");
		mvprintw(y1+2,x1-7,"*");
		mvprintw(y1+1,x1-4,"*");
		mvprintw(y1,x1-3,"*");
		mvprintw(y1+1,x1-6,"*");
		mvprintw(y1,x1-7,"*");
		mvprintw(y1+3,x1-6,"*");
		mvprintw(y1+4,x1-7,"*");
		mvprintw(y1+4,x1-3,"*");
		mvprintw(y1+3,x1-4,"*");

		if(i == 0 && (qq == 1 || qq == 3)) {
			usleep(700000);
			refresh();
		}
		if(q != 2) 
			break;
		if(qq != 1 && qq != 3)
			break;
		if( q == 2){
			endwin();
			refresh();
			usleep(300000);
		}	
		j++;
		i++;
	}
	if(q != 1)
		endwin();
	return 0;
}
/* Prints 2048 menu */
int menu(){	
	ITEM **my_items;
	int c;				
	MENU *my_menu;
        WINDOW *my_menu_win;
        int n_choices, i;
	ITEM *cur;
	/* Initialize curses */
	initscr();
	start_color();
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);      cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	START:
	bkgd(COLOR_PAIR(6));
	attrset(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	/* Create items */
        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i){
                my_items[i] = new_item(choices[i], NULL);
		if(i == 0)
			/* Set the user pointer */
			set_item_userptr(my_items[i], start_game);
		else if(i == 1)
			set_item_userptr(my_items[i], resume_game);
		else if(i == 2)
			set_item_userptr(my_items[i], difficulty);
		else if(i == 3)
			set_item_userptr(my_items[i], instructions);
		else if(i == 4)
			set_item_userptr(my_items[i], main_call);
		else if(i == 5)
			set_item_userptr(my_items[i], exit);
	}

	my_items[n_choices] = (ITEM *)NULL;
	/* Crate menu */
	my_menu = new_menu((ITEM **)my_items);

	/* Create the window to be associated with the menu */
        my_menu_win = newwin(10, 30, 15, 70);
        keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 7, 26, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu, "--> ");

	/* Print a border around the main window and print a title */
        box(my_menu_win, 0, 0);
	print_in_middle(my_menu_win, 1, 0, 30, "--2048--", COLOR_PAIR(1));
	attrset(COLOR_PAIR(1));
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 29);
	mvwaddch(my_menu_win, 2, 29, ACS_RTEE);
	mvprintw(LINES - 2, 1, " Press F1 to exit");
	attrset(COLOR_PAIR(5));
	/* Post the menu */
	mvprintw(LINES - 3, 1, " Press <ENTER> to see the option selected");
	mvprintw(LINES - 2, 1, " Up and Down arrow keys to navigate (F1 to Exit)");
	post_menu(my_menu);
	refresh();
	attrset(COLOR_PAIR(2));
	refresh();
        
	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);

	while((c = wgetch(my_menu_win)) != KEY_F(1))
	{       switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10:
				cur = current_item(my_menu);
				endwin();
				unpost_menu(my_menu);
				void (*p)(char *);
				if(cur == my_items[0])
				{
					res = 0;
				}
				cur = current_item(my_menu);
				p = item_userptr(cur);
				p((char *)item_name(cur));
				pos_menu_cursor(my_menu);
				initscr();	/* Post the menu */
				attrset(COLOR_PAIR(1));
				mvprintw(LINES - 3, 1, " Press <ENTER> to see the option selected");
				mvprintw(LINES - 2, 1, " Up and Down arrow keys to navigate (F1 to Exit)");
				goto START;//post_menu(my_menu);
				refresh();
				attrset(COLOR_PAIR(2));
				break;

		}
                wrefresh(my_menu_win);
	}	

	/* Unpost and free all the memory taken up */
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	free_menu(my_menu);
	endwin();
	exit(1);
	return 0;
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color){
	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	wattron(win, A_BOLD);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, A_BOLD);
	wattroff(win, color);
	refresh();
	return;
}

/* Resume game function */
void resume_game() {
	if(res_flag == 0){
		res_flag = 1;
		start_game();
		return;
	}
	res++;
	scr_restore("/tmp/virtual.dump");
	doupdate();
	refresh();
	fp = fopen("size.txt", "r");
	fread(&(g.size), sizeof(int), 1, fp);
	fclose(fp);
	fp = fopen("array_rec2.txt", "r");
	if(fp == 0){ 
		start_game();
		res = 0;
	}	
	int ll2 = 0, lll2 = 0;
	for(ll2 = 0; ll2 < g.size; ll2++){
		for(lll2 = 0; lll2 < g.size; lll2++){
			fread(&(g.a[ll2][lll2]), sizeof(int),1, fp);
		}
	}
	getch();
	fclose(fp);
	fp = fopen("score.txt", "r");
	fread(&score, sizeof(int), 1, fp);
	fclose(fp);
	
	start_game();
	return;
}

/* Start game function */
int start_game() {
	int ch;	
	res_flag = 1;
	int i = 0, m = 0, j = 0;
	initscr();
	noecho();
	cbreak();
	start_color();
	init_pair(2,COLOR_WHITE,COLOR_RED);
	init_pair(1,COLOR_BLACK,COLOR_BLACK);
	init_pair(4,COLOR_RED,COLOR_RED);
	attrset(COLOR_PAIR(2));
	bkgd(COLOR_PAIR(1));

	if(res == 0) {
		score = 0;
		initial(&g);
		randm();
		randm();
	}

	print_board(&g, score);
	endwin();
	initscr();
	attrset(COLOR_PAIR(1));
	move(2,2);
	attrset(COLOR_PAIR(2));
	char check;
	while((ch = getch()) != 'z') { 
		attrset(COLOR_PAIR(4));
		if(ch == KEY_LEFT)
			move_left(&g, &flag1, &score);
		else if(ch == KEY_RIGHT)
			move_right(&g, &flag1, &score);
		else if(ch == KEY_UP)
			move_up(&g, &flag1, &score);	
		else if(ch == KEY_DOWN)
			move_down(&g, &flag1, &score);
		else if(ch == 'p'){
			break;
		}
		else
			continue;
		initscr();
		start_color();
		print_board(&g, score);
		attrset(COLOR_PAIR(2));
		m++;
		endwin();	

		if(flag1) randm();
		int flag2 = 0;
		int flag3 = 2;
		if(!flag1){
			for(i = 0; i < g.size; i++){
				for(j = 0; j < g.size; j++){
					if(g.a[i][j] != 0)
						flag2 = 1;
					else {
						flag2 = 0;
						flag3 = 1;
					}
				}
			}
			int chk = dup_check();
			if(flag3 != 1 && !chk) {
				endwin();
				refresh();
				clear();
				check = game_over(1);
				if(check != 'm') {
					refresh();
					endwin();
					clear();
					exit(1);
				}
				else break;
			}	
		}
		refresh();
		usleep(150000);
		initscr();
		start_color();
	
		print_board(&g, score);
		attrset(COLOR_PAIR(1));
		move(2,2);

		attrset(COLOR_PAIR(2));
		endwin();

	}
	/* Writing data to a file */
	scr_dump("/tmp/virtual.dump");
	fp = fopen("size.txt", "w");
	fwrite(&(g.size), sizeof(int), 1, fp);
	fclose(fp);
	
	fp = fopen("array_rec2.txt", "w");
	int ll = 0, lll = 0;
	for(ll = 0; ll < g.size; ll++){
		for(lll = 0; lll < g.size; lll++){
			fwrite(&(g.a[ll][lll]), sizeof(int),1, fp);
		}
	}
	fclose(fp);
	fp = fopen("score.txt", "w");
	fwrite(&score, sizeof(int), 1, fp);
	fclose(fp);
		
	clear();
	menu();

	clear();
	initscr();
	move(60,70);
	printw("GAME OVER!");
	
	getch();
	endwin();
	return 0;
}
/* Produces random numbers at random locations in the gameplay */
void randm() {
	int r[3] = {2,4,8};
	int r1,r2,r3, flag = 0;
	srand(time(NULL));
	while(!flag) {
		r1=rand() % g.size;
		r2=rand() % g.size;
		if(g.a[r1][r2] == 0){
			if(kk == 0 || kk == 1)
				r3 = rand() % 2;
			else
				r3 = rand() % 3;
			g.a[r1][r2] = r[r3];		
			flag = 1;
		}
	}
	return;
}
/* Game over function */
char game_over(int g) {
	char check1;
	int i = 0;
	while(i < 25) {
	initscr();
	start_color();
	nocbreak();
	init_pair(7, 1, COLOR_RED);
	init_pair(8, 1, COLOR_BLACK);
	if(i % 3 == 0) bkgd(COLOR_PAIR(8));
	else bkgd(COLOR_PAIR(7));	
	attrset(COLOR_PAIR(5));
	box(stdscr, 0, 0);	
	attrset(COLOR_PAIR(1));
	move(20,78);
	printw("GAME OVER!");
	move(20, 90);
	if(g == 1)
		printw("Score: %d", score);	
	else 	
		printw("Score: %d", g);	
	move(40, 67);
	move(40, 62);
	printw("Press 'm' for Main Menu or any other key to exit");
	usleep(400000);
	timeout(0);
	check1 = getch();
	if(check1 != ERR)
		return check1;
	i++;
	endwin();
	refresh();		
	}
	move(40, 62);printw("Press 'm' for menu or any other key to exit");//getch();
	
	return check1;
}
		
/* Checks for duplicates in the grid */
int dup_check(){
	int i = 0, flag_dup = 0;
	int j = 0;
	for(++i; i < g.size; i++){
		for(++j; j < g.size; j++) {
			if(g.a[i][j] == g.a[i-1][j] || g.a[i][j] == g.a[i][j-1] || g.a[i][j] == g.a[i+1][j] || g.a[i][j] == g.a[i][j+1])
				flag_dup++;
		}
	}	
	for(i = 0; i < g.size - 1; i++)
		if(g.a[i][0] == g.a[i+1][0] || g.a[i][g.size - 1] == g.a[i + 1][g.size - 1]|| g.a[0][i] == g.a[0][i+1] || g.a[g.size - 1][i] == g.a[g.size - 1][i+1])
			flag_dup++;
	
	if(flag_dup == 0)
		return 0;
	return 1;
}
/* Prints menu for difficulty */
void difficulty() {

	ITEM **my_items;
	int c;				
	MENU *my_menu;
        WINDOW *my_menu_win;
        int n_choices, i;
	ITEM *cur;
	/* Initialize curses */
	initscr();
	start_color();
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_RED);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);      cbreak();
        noecho();
		keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	bkgd(COLOR_PAIR(6));
	attrset(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	/* Create items */
        n_choices = ARRAY_SIZE(choices1);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i){
                my_items[i] = new_item(choices1[i], NULL);
		if(i == 0)
			/* Set the user pointer */
			set_item_userptr(my_items[i], easy_game);
		else if(i == 1)
			set_item_userptr(my_items[i], hard_game);
		else if(i == 2)
			set_item_userptr(my_items[i], back);
	}

	my_items[n_choices] = (ITEM *)NULL;
	/* Crate menu */
	my_menu = new_menu((ITEM **)my_items);

	/* Create the window to be associated with the menu */
        my_menu_win = newwin(8, 25, 15, 74);
        keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 5, 19, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu, "--> ");

	/* Print a border around the main window and print a title */
        box(my_menu_win, 0, 0);
	print_in_middle(my_menu_win, 1, 0, 25, "--2048--", COLOR_PAIR(1));
	attrset(COLOR_PAIR(1));
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 24);
	mvwaddch(my_menu_win, 2, 24, ACS_RTEE);
	mvprintw(LINES - 2, 1, " Press F1 to exit");
	attrset(COLOR_PAIR(5));
	/* Post the menu */
	mvprintw(LINES - 3, 1, " Press <ENTER> to see the option selected");
	mvprintw(LINES - 2, 1, " Up and Down arrow keys to navigate (F1 to Exit)");
	post_menu(my_menu);
	refresh();
	attrset(COLOR_PAIR(2));
	int kkk = 0;
	refresh();
        
	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);

	while((c = wgetch(my_menu_win)) != KEY_F(1))
	{       switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10:
				cur = current_item(my_menu);
				endwin();
				unpost_menu(my_menu);
				void (*p)(char *);
				kkk = 1;
				cur = current_item(my_menu);
				p = item_userptr(cur);
				p((char *)item_name(cur));
				pos_menu_cursor(my_menu);
				initscr();	/* Post the menu */
				attrset(COLOR_PAIR(1));
				mvprintw(LINES - 3, 1, " Press <ENTER> to see the option selected");
				mvprintw(LINES - 2, 1, " Up and Down arrow keys to navigate (F1 to Exit)");
				refresh();
				attrset(COLOR_PAIR(2));
				break;


		}
                wrefresh(my_menu_win);
	if(kkk == 1) break;
	}	

	/* Unpost and free all the memory taken up */
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
	free_menu(my_menu);
	endwin();
	return;
}
void easy_game() {
	g.size = 4;
	res_flag = 0;
	return;
}
void hard_game() {
	g.size = 8;
	res_flag = 0;
	return;
}
void back() {
	return;
}
/* Prints instructions */
void instructions() {
	clear();
	endwin();

	initscr();
	start_color();
	timeout(100000);
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	bkgd(COLOR_PAIR(1));
	
	attrset(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	attron(A_STANDOUT);
	mvprintw(8, 80, "||  2048  ||");
	attroff(A_STANDOUT);	
	mvprintw(10, 0, "\n\n\n\t\t2048 is a single-player puzzle game created in March 2014 by 19-year-old Italian web developer Gabriele Cirulli, in which the objective is to\n\t\t\t\t   slide numbered  tiles on a grid to combine them and create a tile with the number 2048.\n\t\t\t\t\t\tThis is a 'C' adapted version of 2048 written by Piyush Yadav.\n\t\t\t\tThe game goes on until there are no pairable adjacent entries left or until 2048 tile is made.\n \n\t\t\t\tThere are 3 modes in the game namely : Easy, Medium and Hard. You can toggle these in the menu. \n\t\t\t\tAlso, you can RESUME THE GAME from the moment you left it the last time you played.\n\n\n\t\t\tCONTROLS:\n\n\t\t\t <-\t\t\t\t Slide left\n\t\t\t ->\t\t\t\t Slide right\n\t\t\t ^(Up Arrow)\t\t\t Slide Up \n\t\t\t v(Down Arrow)\t\t\t Slide down\n\t\t\t p\t\t\t\t Pause(Menu)");
	attron(A_UNDERLINE);
	mvprintw(30, 72, "ENJOY THE GAME PEOPLE! :D");
	attroff(A_UNDERLINE);	

	getch();
	refresh();
	endwin();
	clear();
	return;	
}
