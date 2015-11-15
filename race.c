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

#include<stdio.h>
#include<ncurses.h>
#include<stdlib.h>
#include<menu.h>
#include "stack.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
int main(int g);
int score1 = 0;
static int qm = 0;
int missed = 0;
int moto(int i); 
int scores();
void mgame_over();
char game_over();
int hflag = 0;
int hflag2 = 0;
void hearts(int x, int y);
void moves(int x1, int yy);
void moves2(int x1, int yy);
void moves3(int x1, int yy);
void moves4(int x1, int yy);
void moves5(int x1, int yy);
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color);
void instructions_race();
void start_moto();
void race_menu();
char *choices_race[] = {
                        "      START GAME      ",
                        "     INSTRUCTIONS     ",
                        "      MAIN MENU       ",
                        "         Exit       ",
                        (char *)NULL,
                  };

void main_call2() {
	main(2);
}
void res_race();
	
int mainm() {
	endwin();
	clear();
	missed = 0;
	refresh();
	initscr();
	curs_set(0);
	moto(1);
	start_moto();
	endwin();
	return 0;
}
int d_player = 0;
int var = 80;
/* Starts motoGT gameplay */
void start_moto(){
	endwin();
	initscr();	
	hflag = 0;
	hflag2 = 0;
	start_color();
	noecho();
	cbreak();
	missed = 0;
	srand(time(NULL));
	nodelay(stdscr,TRUE);
	keypad(stdscr, TRUE);
	int wrap = 0, count = 0, yy = 72, flag2 = 0,k = 0, i = 0, j = 0, m = 0, flag = 0,delay = 0;
	int ch , ch2 , ch3 = 8, ch4 = 2, yy2 = 80, yy3 = 89, yy4 = 98, yy5 = 107, dob = 0, dob1 = 0, dob2 = 0, dob3 = 0;
	stack sc;
	init(&sc);
	int color_f = 0;
	int ck;
	int  co, diffc;
	co = 87;
	int x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0;
	int flag3 = 1,jk = 0, nflag = 0;
	scores();
	int co2;
		
	if(d_player == 1){	
		co2 = var - 25;
	}	
	int road_l = 0;
	int i3 = 0;
	ST:
 	j = 0;
	int i2;
	flag = 0;
	flag2 = 0;
	int flag_p1 ;
	init_pair(7,7,7);
	init_pair(8,COLOR_GREEN,COLOR_GREEN);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(2,COLOR_BLACK,COLOR_RED);
	attrset(COLOR_PAIR(7));
	i = 0;
	i2 = 0;
	int i1 = 0;

	if(d_player == 0)
	var = 65;
	while(!flag2 && ch != 'p' && ch != 'o') { 
		i1++;
		i3++;
		count++;
		road_l = 0;
		if(!nflag) {
			if(i < 10) delay = 1000;
			else if (i < 30) delay = 30000;
			else if (i < 50) delay = 45000;
			else delay = 60000;	
		}
		else jk++;
		m = 0;
		/* Checking keystrokes */
		if(ch == KEY_LEFT){
			flag = 0;
			ch4 = ch;
			flag2 = 0;
			co--;
			if(ch3 == 'd') co2++;
			else if(ch3 == 'a') co2--;
			else if(ch3 == 8) flag_p1 = 1;
		}
		else if(ch == KEY_RIGHT){
			flag = 0; 
			flag2 = 0;
			ch4 = ch;
			co++;
			if(ch3 == 'd') co2++;
			else if(ch3 == 'a') co2--;
			else if(ch3 == 8) flag_p1 = 1;
		}
		else if( ch == 'd'){
			co2++;
			ch3 = ch;
			if(ch4 == KEY_RIGHT) co++;
			else if(ch4 == KEY_LEFT) co--;
			flag = 0;
		}else if(ch == 'a'){
			flag = 0;
			ch3 = ch;
			if(ch4 == KEY_RIGHT) co++;
			else if(ch4 == KEY_LEFT) co--;
			co2--;
		}else road_l++;
		attrset(COLOR_PAIR(8));
		attrset(COLOR_PAIR(7));
		if(co > 110 || co <= var){
			//i = 0;
			hflag++;
			if(d_player == 0)
				co = 87;
			else
				co = 90;
			ch = 2;
			ch4 = 9;
			
			flag = 1;
			nflag = 0;
		}
		if(d_player == 1) {
			if(co2 > var - 10 || co2 <= var - 40){
				hflag2++;
				co2 = var - 25;
				ch = 2;
				ch3 = 1;
				flag_p1 = 1;
			}
		}
		if(i % 2 != 0)
			k = j + 1;
		else k = j;
		/* Printing Road lines */
		while(j < 40) {
			if(j % 4 > 1) {
				if(d_player == 1) {
					move(k, var + (110 - var)/2);
					printw("||");
				}
				if(d_player == 0) {
					move(k, var + (110 - var)/3);
					printw("||");
				}
				if(d_player == 1) {
					move(k, var - 25);
					printw("||");
				}
				if(d_player == 0) {
					move(k, var + (110 - var)*2/3);
					printw("||");
				}
			}
			j++;
			k++;	
		}
		/* Printing bike */
		if(color_f % 2 == 0){
			attrset(COLOR_PAIR(5));
		}
	
		else attrset(COLOR_PAIR(8));
		move(40, co);
		printw(" ");	
		move(39, co-1);
		printw("   ");
		move(38, co);
		printw(" ");

		if(d_player == 1) {
			move(40, co2);
			printw("|");	
			move(39, co2 - 1);
			printw("(|)");	
			move(38, co2);
			printw("|");	
		}
		attrset(COLOR_PAIR(7));


		j = 0;	
		if(ch != KEY_LEFT && ch != KEY_RIGHT && ch != 'd' && ch != 'a')
				flag2 = 1;
		m = 0;	
		attrset(COLOR_PAIR(2));
		/* Printing obstacles */
		if(!flag2) {
			moves(++x1, yy);
			if(dob) moves2(++x2, yy2);
			if(dob1) moves3(++x3, yy3);
			if(dob2) moves4(++x4, yy4);
			if(dob3) moves5(++x5, yy5);
			attrset(COLOR_PAIR(7));
			
			diffc = 110 - var;
			if(x1 == 40 && wrap % 2 == 0){
				wrap++;
				x1 = 0;
				yy = var + (rand() % (diffc - 10));
			}
			else if(x1 == 40 && wrap % 3 == 0){
				wrap++;
				x1 = 0;
				yy = var + (rand() % (diffc - 10));
			}
			else if(x1 == 40){
				wrap++;
				x1 = 0; 
				yy = var + (rand() % (diffc - 10));
			}
			else if(x1 == 8 || x2 == 40){
				dob = 1;
				x2 = 0; 
				yy2 = var + (rand() % (diffc - 10));
			}
			else if(x2 == 8 || x3 == 40){
				dob1 = 1;
				x3 = 0; 
				yy3 = var + (rand() % (diffc - 10));
			}
			else if(x3 == 8 || x4 == 40){
				dob2 = 1;
				x4 = 0; 
				yy4 = var + (rand() % (diffc - 10));
			}
			else if(x4 == 8 || x5 == 40) {
				dob3 = 1;
				x5 = 0;
				yy5 = var + (rand() % (diffc - 10));
			}


		}
		/* Using stack */
		attrset(COLOR_PAIR(7));
		if(count > 2 && !flag2){
			ck = pop(&sc);
			if(x1 > x2 && x1 > x3 && x1 > x4 && x1 > x5) {
				if(ck == yy)
					push(&sc, ck);
				else 
					push(&sc, yy);
			}
			else if(x2 > x3 && x2 > x1 && x2 > x4 && x2 > x5){
				if(ck == yy2)
					push(&sc, ck);
				else 
					push(&sc, yy2);
			}
			else if(x3 > x1 && x3 > x2 && x3 > x4 && x3 > x5){
				if(ck == yy3)
					push(&sc, ck);
				else
					push(&sc, yy3);
			}
			else if(x4 > x1 && x4 > x2 && x4 > x3 && x4 > x5){
				if(ck == yy4)
					push(&sc, ck);
				else
					push(&sc, yy4);
			}
			else if(x5 > x1 && x5 > x2 && x5 > x3 && x5 > x4){
				if(ck == yy5)
					push(&sc, ck);
				else
					push(&sc, yy5);
			}
		}
		else 
			push(&sc, yy);
		attrset(COLOR_PAIR(7));
		usleep(100000 - delay);
		refresh();
		m = 0;
		if(jk % 200 == 0)
			nflag = 0;
		/* Checking for collisions */
		ck = pop(&sc);
		if((x1 == 38 || x2 == 39 || x3 == 38 || x4 == 39 || x4 == 38 || x5 == 38) && (co <= (ck+9) && co >= (ck-3))) {
			score1++;
			i = 31;
			hflag++;
			color_f++;
			nflag = 0;
			if((x4 == 39 || x4 == 38) && (co <= (ck+9) && co >= (ck-3))){
				nflag++;
				delay = 68000;
				hflag--;
				score1--;
				jk = 0;
			}
		}
		else if((x4 == 39 || x1 == 39 || x2 == 39 || x3 == 39))
			missed++; 
		push(&sc, ck);
		timeout(0);
		ch = getch();
		
		if(ch == ERR && !flag)
			ch = ch2;
		ch2 = ch;
		if(ch3 != 8 || ch4 != 2 || !flag2)
			clear();
		i++;
		i2++;
		while(m <= 40){
			scores();
			attrset(COLOR_PAIR(5));

			mvprintw(25, 143, "SCORE: %d", missed);
			attrset(COLOR_PAIR(7));
			if(i1 == 12) 
				flag3 = 0;
			if(x1 == 40)
				flag3 = 1;
	
			
			init_pair(5,1,7);
			init_pair(3,1,COLOR_BLUE);
			init_pair(4, COLOR_BLACK, COLOR_RED);

			attrset(COLOR_PAIR(5));
			if(j % 2 == 0)
				attron(A_BOLD);
			else 
				attroff(A_BOLD);
			moto(1);
			/* Printing road boundaries */
			attrset(COLOR_PAIR(7));	
			if(d_player == 1) {			
				move(m, var - 40);
				printw("||");
				move(m, var - 10);
				printw("||");
			}
			move(m, var);
			printw("||");
			move(m, 110);
			printw("||");
			move(41, 4*m);
			printw("||");
			m++;		
		}	
	}
	if(flag2) {
		attrset(COLOR_PAIR(2));

		if(flag2) {
			moves(x1, yy);
			if(dob) moves2(x2, yy2);
			if(dob1) moves3(x3, yy3);
			if(dob2) moves4(x4, yy4);
			if(dob3) moves5(x5, yy5);
			attrset(COLOR_PAIR(7));
		}
		goto ST;	
	}
	
	if(ch == 'o')
		race_menu();/* pause work */
	else { 
	flag2 = 0;
	ch = 0;
	goto ST;
	}

}
/* Prints score */
int scores() {
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(9, COLOR_GREEN, COLOR_BLACK);
	attrset(COLOR_PAIR(9));
	mvprintw(38, 115, "Press once <- or -> to start and change directions.");	
	mvprintw(39, 125, "Press 'p' to pause the game.");	
	mvprintw(40, 128, "Press 'o' for options.");	
	attrset(COLOR_PAIR(5));
	int x, y;
	x = 130;
	y = 25;
	
//s
	mvprintw(y,x-8, " ");
	mvprintw(y-2,x-8 ," ");
	mvprintw(y-3,x-8, " ");
	mvprintw(y-4,x-8, " ");
	mvprintw(y-4,x-7, " ");
	mvprintw(y-4,x-6, " ");
	mvprintw(y-2,x-7, " ");
	mvprintw(y,x-7, " ");
	mvprintw(y,x-6, " ");
	mvprintw(y-1,x-6, " ");
	mvprintw(y-2,x-6, " ");

//c
	mvprintw(y,x-4, " ");
	mvprintw(y-1,x-4 ," ");
	mvprintw(y-2,x-4, " ");
	mvprintw(y-2,x-3, " ");
	mvprintw(y,x-3, " ");
	mvprintw(y,x-2, " ");
	mvprintw(y-2,x-2, " ");

//O
	mvprintw(y,x, " ");
	mvprintw(y-1,x ," ");
	mvprintw(y-2,x, " ");
	mvprintw(y-2,x+1, " ");
	mvprintw(y,x+1, " ");
	mvprintw(y,x+2, " ");
	mvprintw(y-1,x+2, " ");
	mvprintw(y-2,x+2, " ");

//r
	mvprintw(y,x+4, " ");
	mvprintw(y-1,x+4 ," ");
	mvprintw(y-2,x+4, " ");
	mvprintw(y-1,x+5, " ");
	mvprintw(y-2,x+6, " ");
	mvprintw(y,x+8, " ");
	mvprintw(y-1,x+8 ," ");
	mvprintw(y-2,x+8, " ");
	mvprintw(y-2,x+9, " ");
	mvprintw(y,x+9, " ");
	mvprintw(y-1,x+9, " ");
	mvprintw(y,x+10, " ");
	mvprintw(y-2,x+10, " ");
//hearts
	y -= 10;
	x -= 20;
	y = 32;
	hearts(x, y);
	return 0;
}

void hearts(x, y){
	int jj = 0;
	init_pair(9, COLOR_WHITE, COLOR_RED);
	while(jj < (3 - hflag)){
		x += 8;
		init_pair(9, COLOR_WHITE, COLOR_RED);
		attrset(COLOR_PAIR(9));
		mvprintw(y-3,x+12, " ");
		mvprintw(y-2,x+12, " ");
		mvprintw(y-2,x+13, " ");
		mvprintw(y-3,x+13, " ");
		mvprintw(y-1,x+13, " ");
		mvprintw(y-2,x+14, " ");
		mvprintw(y-1,x+14, " ");
		mvprintw(y,x+14, " ");
		mvprintw(y-1,x+15, " ");
		mvprintw(y-3,x+15, " ");
		mvprintw(y-2,x+15, " ");
		mvprintw(y-2,x+16, " ");
		mvprintw(y-3,x+16, " ");
		
		attrset(COLOR_PAIR(1));
		jj++;		
	}
	jj = 0;
	if(d_player == 1) {
		x = -4;
		while(jj < (3 - hflag2)){
			init_pair(9, COLOR_WHITE, COLOR_RED);
			attrset(COLOR_PAIR(9));
			mvprintw(y-3,x+12, " ");
			mvprintw(y-2,x+12, " ");
			mvprintw(y-2,x+13, " ");
			mvprintw(y-3,x+13, " ");
			mvprintw(y-1,x+13, " ");
			mvprintw(y-2,x+14, " ");
			mvprintw(y-1,x+14, " ");
			mvprintw(y,x+14, " ");
			mvprintw(y-1,x+15, " ");
			mvprintw(y-3,x+15, " ");
			mvprintw(y-2,x+15, " ");
			mvprintw(y-2,x+16, " ");
			mvprintw(y-3,x+16, " ");
			x += 8;
		
			attrset(COLOR_PAIR(1));
			jj++;		
		}
	}
	if(hflag == 3)
		mgame_over();
	
}
/* Prints game logo */
int moto(int i) {
	int j = 0, x  = 45, y = 20;
	
	qm++;
	
	initscr();
	start_color();
	init_pair(1,1,7);
	init_pair(3,1,COLOR_BLACK);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	x  = 14;
	y = 15;
	init_pair(2,7,1);
	if(d_player == 1 && (qm != 1)) {
		x = 127;
		y = 5;
	}
	attrset(COLOR_PAIR(2));
	if(j % 2 == 0)
	attron(A_BOLD);
	else 
	attroff(A_BOLD);
//0
	mvprintw(y+1,x-4, " ");
	mvprintw(y+1,x-5, " ");
	mvprintw(y+1,x-6, " ");
	mvprintw(y-3,x-4, " ");
	mvprintw(y-3,x-5, " ");
	mvprintw(y-3, x-6, " ");
	mvprintw(y,x-6, " ");
	mvprintw(y-1,x-6 ," ");
	mvprintw(y-2,x-6, " ");
	mvprintw(y-2,x-5, " ");
	mvprintw(y,x-5, " ");
	mvprintw(y-1, x-5, " ");
	mvprintw(y,x-4, " ");
	mvprintw(y-1,x-4, " ");
	mvprintw(y-2,x-4, " ");
	mvprintw(y+1,x-1, " ");//
	mvprintw(y+1,x-2, " ");
	mvprintw(y+1,x-3, " ");
	mvprintw(y-3,x-1, " ");
	mvprintw(y-3,x-2, " ");
	mvprintw(y-3, x-3, " ");//
	mvprintw(y,x-3, " ");
	mvprintw(y-1,x-3 ," ");
	mvprintw(y-2,x-3, " ");
	mvprintw(y-2,x-2, " ");
	mvprintw(y,x-2, " ");
	mvprintw(y-1, x-2, " ");
	mvprintw(y,x-1, " ");
	mvprintw(y-1,x-1, " ");
	mvprintw(y-2,x-1, " ");

	x = 20; 
	y = 20;

	if(d_player == 1 && (qm != 1)) {
		x = 133 - (var % 4);
		y = 10;
	}	
//1
	mvprintw(y+1,x-4, " ");
	mvprintw(y+1,x-5, " ");
	mvprintw(y+1,x-6, " ");
	mvprintw(y-3,x-4, " ");
	mvprintw(y-3,x-5, " ");
	mvprintw(y-3, x-6, " ");
	mvprintw(y,x-6, " ");
	mvprintw(y-1,x-6 ," ");
	mvprintw(y-2,x-6, " ");
	mvprintw(y-2,x-5, " ");
	mvprintw(y,x-5, " ");
	mvprintw(y-1, x-5, " ");
	mvprintw(y,x-4, " ");
	mvprintw(y-1,x-4, " ");
	mvprintw(y-2,x-4, " ");
	mvprintw(y+1,x-1, " ");
	mvprintw(y+1,x-2, " ");
	mvprintw(y+1,x-3, " ");
	mvprintw(y-3,x-1, " ");
	mvprintw(y-3,x-2, " ");
	mvprintw(y-3, x-3, " ");
	mvprintw(y,x-3, " ");
	mvprintw(y-1,x-3 ," ");
	mvprintw(y-2,x-3, " ");
	mvprintw(y-2,x-2, " ");
	mvprintw(y,x-2, " ");
	mvprintw(y-1, x-2, " ");
	mvprintw(y,x-1, " ");
	mvprintw(y-1,x-1, " ");
	mvprintw(y-2,x-1, " ");
//2
	mvprintw(y+4,x, " ");
	mvprintw(y+3,x, " ");
	mvprintw(y+2,x, " ");
	mvprintw(y+2,x+1, " ");
	mvprintw(y+3,x+1, " ");
	mvprintw(y+4, x+1, " ");
	mvprintw(y+2,x+2, " ");
	mvprintw(y+3,x+2, " ");
	mvprintw(y+4,x+2, " ");
//3
	mvprintw(y-4,x, " ");
	mvprintw(y-5,x, " ");
	mvprintw(y-6,x, " ");
	mvprintw(y-6,x+1, " ");
	mvprintw(y-5,x+1, " ");
	mvprintw(y-4, x+1, " ");
	mvprintw(y-6,x+2, " ");
	mvprintw(y-5,x+2, " ");
	mvprintw(y-4,x+2, " ");
//4
	mvprintw(y-7,x+3, " ");
	mvprintw(y-8,x+3, " ");
	mvprintw(y-7,x+4, " ");
	mvprintw(y-8,x+4, " ");

	attrset(COLOR_PAIR(1));
	
	mvprintw(y,x+1, " ");
	mvprintw(y-1,x+1, " ");
	mvprintw(y-2,x+1, " ");
	mvprintw(y-2,x+2, "V");
	mvprintw(y-1,x+2, "V");
	mvprintw(y-2,x+3, " ");
	mvprintw(y-1,x+3, " ");
	mvprintw(y,x+3, " ");
	if(i == 0) {
		usleep(700000);
		refresh();
	}

	mvprintw(y,x+5, " ");
	mvprintw(y-1,x+5 ," ");
	mvprintw(y-2,x+5, " ");
	mvprintw(y-2,x+6, " ");
	mvprintw(y,x+6, " ");
	mvprintw(y,x+7, " ");
	mvprintw(y-1,x+7, " ");
	mvprintw(y-2,x+7, " ");

	if(i == 0) {
		usleep(700000);
		refresh();
	}
	mvprintw(y-2,x+9, " ");
	mvprintw(y-2,x+10, " ");
	mvprintw(y-1,x+10, " ");
	mvprintw(y,x+10, " ");
	mvprintw(y-2,x+11, " ");

	if(i == 0) {
		usleep(700000);
		refresh();
	}
	mvprintw(y,x+13, " ");
	mvprintw(y-1,x+13, " ");
	mvprintw(y-2,x+13, " ");
	mvprintw(y-2,x+14, " ");
	mvprintw(y,x+14, " ");
	mvprintw(y,x+15, " ");
	mvprintw(y-1,x+15, " ");
	mvprintw(y-2,x+15, " ");

	if(i == 0) {
		usleep(700000);
		refresh();
	}
	
	attrset(COLOR_PAIR(4));

	mvprintw(y,x+17, " ");
	mvprintw(y,x+18, " ");
	mvprintw(y,x+19, " ");
	mvprintw(y,x+20, " ");
	mvprintw(y-1,x+17, " ");
	mvprintw(y-1,x+19, " ");
	mvprintw(y-1,x+20, " ");
	mvprintw(y-2,x+17, " ");
	mvprintw(y-3,x+18, " ");
	mvprintw(y-3,x+19, " ");
	mvprintw(y-3,x+20, " ");
	mvprintw(y-3,x+17, " ");

	if(i == 0) {
		usleep(700000);
		refresh();
	}
	mvprintw(y,x+24, " ");
	mvprintw(y-1,x+24, " ");
	mvprintw(y-2,x+24, " ");
	mvprintw(y-3,x+24, " ");
	mvprintw(y-3,x+24, " ");
	mvprintw(y-3,x+25, " ");
	mvprintw(y-3,x+26, " ");
	mvprintw(y-3,x+23, " ");
	mvprintw(y-3,x+22, " ");
	attrset(COLOR_PAIR(5));

	if(i == 0) {
		usleep(700000);
		refresh();
		usleep(300000);
		j++;
	}
	i++;

	return 0;
}
/* Next 5 functions print the obstacles and Nitro (N) object */
void moves(int x1, int yy) {
	move(x1, yy);
	
	printw("         ");
	move(x1-1, yy+1);
	printw("       ");
	move(x1-2, yy);
	printw("         ");
	return;
}
void moves2(int x1, int yy) {
	move(x1, yy);
	printw("          ");
	return;
}
void moves3(int x1, int yy) {
	move(x1, yy);
	printw("    ");
	move(x1+1, yy-1);
	printw("      ");
	move(x1+2, yy-2);
	printw("        ");
	return;
}
void moves4(int x1, int yy) {
	move(x1, yy);
	printw(" ");
	move(x1 - 1, yy);
	printw(" ");
	move(x1 - 2, yy);
	printw(" ");
	move(x1 - 2, yy+1);
	printw(" ");
	move(x1 - 1, yy+2);
	printw(" ");
	move(x1 , yy+3);
	printw(" ");
	move(x1 , yy+4);
	printw(" ");
	move(x1 - 1, yy+4);
	printw(" ");
	move(x1 - 2, yy+4);
	printw(" ");
	return;
}
void moves5(int x1, int yy) {
	move(x1, yy);
	printw("    ");
	move(x1+1, yy-1);
	printw("      ");
	move(x1+2, yy-2);
	printw("        ");
	return;
}
/* Game over */
void mgame_over(){
	char check;
	clear();
	check = game_over(missed);
	if(check != 'm') {
		refresh();
		endwin();
		clear();
		exit(1);
	}
	refresh();
	usleep(100000);
	initscr();
	start_color();	
	clear();
	main(2);
	return;
}
/* Prints motoGT menu */
void race_menu() {	
	endwin();
	clear();
	refresh();
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
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
        noecho();
		keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	START:
	attrset(COLOR_PAIR(1));
	box(stdscr, 0, 0);
	/* Create items */
        n_choices = ARRAY_SIZE(choices_race);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i){
                my_items[i] = new_item(choices_race[i], NULL);
		if(i == 0)
			/* Set the user pointer */
			set_item_userptr(my_items[i], mainm);
		else if(i == 1)
			set_item_userptr(my_items[i], instructions_race);
		else if(i == 2)
			set_item_userptr(my_items[i], main_call2);
		else if(i == 3)
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
	print_in_middle(my_menu_win, 1, 0, 30, "-motoGT-", COLOR_PAIR(1));
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
	return;
}
/* Prints instructions of motoGT */
void instructions_race() {
	clear();
	endwin();
	initscr();
	start_color();
	timeout(10000);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	attrset(COLOR_PAIR(2));
	box(stdscr, 0, 0);
	attron(A_STANDOUT);
	mvprintw(8, 80, "||   motoGT   ||");
	attroff(A_STANDOUT);	
	mvprintw(10, 0, "\n\n\n\t\t\t\tMotoGT is a single player obstacle dodge game which enables the player to experience racing like environment.\n\t\t\t\t\t\t   The objective is to get the maximum score by dodging randomly generated obstacles.\n\t\t\t\t\t\t\tThis is a 'C' adapted version of 'motoGT' written by Piyush Yadav.\n\t\tThe game goes on until the player has made 3 collisions after which its game over. Make sure to collide with Nitro (N) to gain speed and score.\n \n\t\t\t\t\t\t\tHearts on the right side of the screen show your remaining lives.\n\n\n\t\t\tCONTROLS:\n\n\t\t\t <-\t\t\t\t Press once to change direction to left\n\t\t\t ->\t\t\t\t Press once to change direction to right\n\t\t\t p\t\t\t\t Pause the game\n\t\t\t o\t\t\t\t View Options(Menu)");
	attron(A_UNDERLINE);
	mvprintw(30, 72, "ENJOY THE GAME PEOPLE! :D");
	attroff(A_UNDERLINE);	
	getch();
	refresh();
	endwin();
	refresh();
	clear();
	return;
}
