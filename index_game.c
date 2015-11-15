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

#include<menu.h>
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<string.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
int mainm();
void race_menu();
int mains();
void banner();
void moto();
void print_in_middle1(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
char *choices_index[] = {
                        "      2048       ",
                        "     motoGT      ",
                        "      Exit       ",
                        (char *)NULL,
                  };

void exitit() {
	refresh();
	endwin();
	clear();
	refresh();
	endwin();
	exit(1);
}
/* Starts the program and prints the main menu */
int main(int qw) {
	static int mm = -1;
	mm++;
	initscr();
	curs_set(0);
	noecho();
	if(qw == 2)
		banner(4);
	else if(qw == 1)
		banner(3);
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
	init_pair(7, COLOR_CYAN, COLOR_BLACK);
	cbreak();
        noecho();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	START:
	attrset(COLOR_PAIR(7));
        n_choices = ARRAY_SIZE(choices_index);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i){
                my_items[i] = new_item(choices_index[i], NULL);
		if(i == 0)
			/* Set the user pointer */
			set_item_userptr(my_items[i], mains);
		else if(i == 1)
			set_item_userptr(my_items[i], race_menu);
		else if(i == 2)
			set_item_userptr(my_items[i], exitit);
	}
	my_items[n_choices] = (ITEM *)NULL;
	/* Crate menu */
	my_menu = new_menu((ITEM **)my_items);

	/* Create the window to be associated with the menu */
        my_menu_win = newwin(8, 25, 15, 70);
        keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 5, 19, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu, "--> ");

	/* Print a border around the main window and print a title */
        box(my_menu_win, 0, 0);
	print_in_middle1(my_menu_win, 1, 0, 25, "CHOOSE A GAME", COLOR_PAIR(7));
	attrset(COLOR_PAIR(7));
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 24);
	mvwaddch(my_menu_win, 2, 24, ACS_RTEE);
	mvprintw(LINES - 2, 1, " Press F1 to exit");
	/* Post the menu */
	mvprintw(LINES - 3, 1, " Press <ENTER> to see the option selected");
	mvprintw(LINES - 2, 1, " Up and Down arrow keys to navigate (F1 to Exit)");
	post_menu(my_menu);
	if(!mm)
		moto(0);
	else 
		moto(1);
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
				clear();
				refresh();
				void (*p)(char *);
				cur = current_item(my_menu);
				p = item_userptr(cur);
				p((char *)item_name(cur));
				pos_menu_cursor(my_menu);
				initscr();	/* Post the menu */
				attrset(COLOR_PAIR(7));
				mvprintw(LINES - 3, 1, " Press <ENTER> to see the option selected");
				mvprintw(LINES - 2, 1, " Up and Down arrow keys to naviage (F1 to Exit)");
				goto START;
				refresh();
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
}

void print_in_middle1(WINDOW *win, int starty, int startx, int width, char *string, chtype color){
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
}
