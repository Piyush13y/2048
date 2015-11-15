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
#include "grid.h"

/* Initialises the data structure */
void initial(grid *g) {
	int i1 = 0, j1 = 0;
	for(i1 = 0; i1 < g->size; i1++) {
		for(j1 = 0; j1 < g->size; j1++){
			g->a[i1][j1] = 0;
		}
	}
	return;
}
/* Shifting gameplay to the left */
void move_left(grid *g, int *flag1, int * score) {
	int count = 0,count1 = 0, count2 = 0, k = 0, i, j = 0, n = 0;	
	int hh = 0;
	for(i = 0; i < g->size ; i++) {
		j = 1;
		while(j < g->size) {
			k = j;
			while(g->a[i][k-1] == 0 && k > 0)
			{
			k--;
			if(g->a[i][k+1] != 0)
				count++;
			}
			if(k != j) {
				hh = g->a[i][k];
				g->a[i][k] = g->a[i][j];
				g->a[i][j] = hh;
			}
			j++;
		}
		j = 0;
		while(j != g->size - 1){
			if(g->a[i][j] == g->a[i][j+1] && g->a[i][j] != 0){
				g->a[i][j] = 2* g->a[i][j];
				n = j+1;count2++;
				j++;
				(*score) += 2*(g->a[i][j]);
				while(n != g->size - 1) {
					g->a[i][n] = g->a[i][n+1];
					n++;
				}
				g->a[i][n] = 0;		
			}
			else {
				j++;
				count1++;
			}
		}
		j = 0;
	}
	if((count != 0) || count2 != 0){
	*flag1 = 1;
	}
	else 
		*flag1 = 0;
	return;
}
/* Prints board/grid */
void print_board(grid *g, int score) {
	banner(2);
	attrset(COLOR_PAIR(2));
	if(g->size == 4) {
		int m1,m2,m3,m4;
		m1 = 11;
		m2 = 63;
		m3 = 29;
		m4 = 98;	
		int i = 0, j = 0, k = 0, l = 0;
		for(i = m1 - (g->size - 4)*2; i < (m3 + (m3-m1-7)*((g->size-1)/4)); i++) {
			for(j = m2; j < (m4 + (m4-m2-1)*((g->size-1)/4)); j++) {
				move(i, j);
				printw(" ");
			}
		}
		attrset(COLOR_PAIR(2));
		for(i = m1+1 - (g->size - 4)*2, k = 0; i < (m3 + (m3-m1-7)*((g->size-1)/4)); i += 5, k++) {
			for(j = m2+3, l = 0; j < (m4 + (m4-m2-1)*((g->size-1)/4)); j += 9, l++) {
				attrset(COLOR_PAIR(2));
				attron(A_BOLD);
				if(g->a[k][l] == 0)
					mvprintw(i,j,".");
				else 
					mvprintw(i, j, "%d", g->a[k][l]);
				attroff(A_BOLD);
			}
		}
		attrset(COLOR_PAIR(1));
		move(27 + g->size,75 - (g->size - 4) * 12);
		printw("SCORE: %d", score);
		move(35, 72);
		printw("Press p to pause");
		box(stdscr, 0, 0);
		attrset(COLOR_PAIR(2));
	}
	else {

		int m1,m2,m3,m4;
		m1 = 16;
		m2 = 66;
		m3 = 25;
		m4 = 85;
		int i = 0, j = 0, k = 0, l = 0;
		for(i = m1; i < (m3 + (m3-m1-1)*((g->size-1)/4)); i++) {
			for(j = m2; j < (m4 + (m4-m2-4)*((g->size-1)/4)); j++) {
				move(i, j);
				printw(" ");
			}
		}
		attrset(COLOR_PAIR(2));
		for(i = m1+1, k = 0; i < (m3 + (m3-m1-1)*((g->size-1)/4)); i += 2, k++) {
			for(j = m2+3, l = 0; j < (m4 + (m4-m2-4)*((g->size-1)/4)); j += 4, l++) {
				attrset(COLOR_PAIR(2));
				attron(A_BOLD);
				if(g->a[k][l] == 0) 
					mvprintw(i,j,".");
				else 
					mvprintw(i, j, "%d", g->a[k][l]);
				attroff(A_BOLD);
			}
		}
		attrset(COLOR_PAIR(1));
		attron(A_BOLD);
		move(25,75 - (g->size - 4) * 12);
		printw("SCORE: %d", score);
		move(35, 75);
		printw("Press p to pause");
		box(stdscr, 0, 0);
		attroff(A_BOLD);
		attrset(COLOR_PAIR(2));
	}

	return;
}
/* Rotates grid anti clockwise */
void acw_rotate(grid *g) {
	int i, j, tmp, n = g->size;	
	for (i=0; i<n/2; i++) {
		for (j=i; j<n-i-1; j++) {
			tmp = g->a[i][j];
			g->a[i][j] = g->a[j][n-i-1];
			g->a[j][n-i-1] = g->a[n-i-1][n-j-1];
			g->a[n-i-1][n-j-1] = g->a[n-j-1][i];
			g->a[n-j-1][i] = tmp;
		}
	}
	return;
}
/* Slides game play to the right */
void move_right(grid *g, int *flag1, int *score) {
	acw_rotate(g);
	acw_rotate(g);
	move_left(g, flag1, score);
	acw_rotate(g);
	acw_rotate(g);
	return;
}
/* Slides game play upwards */
void move_up(grid *g, int *flag1, int * score) {
	acw_rotate(g);
	move_left(g, flag1, score);
	acw_rotate(g);
	acw_rotate(g);
	acw_rotate(g);
	return;
}	
/* Slides game play downwards */
void move_down(grid *g, int *flag1, int * score) {
	acw_rotate(g);
	acw_rotate(g);
	acw_rotate(g);
	move_left(g, flag1, score);
	acw_rotate(g);
	return;
}

