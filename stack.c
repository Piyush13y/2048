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

#include<time.h>
#include "stack.h"
void init(stack *s) {
	s->i = 0;
}
void push(stack *s, int x) {
	s->a[s->i] = x;
	(s->i)++;
}
/* the caller must check for empty before calling */
int pop(stack *s) {
	(s->i)--;	
	return s->a[s->i];
}
int empty(stack *s) {
	return s->i == 0;
}
int full(stack *s) {
	return s->i == SIZE - 1;
}
