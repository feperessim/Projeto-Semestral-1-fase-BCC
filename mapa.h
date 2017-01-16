/* Copyright (C) 2017 Felipe de Lima Peressim
 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* mapa.h: Arquivo cabeçalho com protótipos */

#ifndef MAPA_H
#define MAPA_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define LEFT	(1<<0)
#define RIGHT 	(1<<1)
#define DOWN 	(1<<2)
#define UP 	(1<<3)

#define CARRO '@'

typedef struct car {	
	char carro;
	int direction, pos_x, pos_y, max_col, max_row, msg_line_counter;
	short shift;
} Car;	

void init_curses(void);
Car *init_car(void);
int init_colors(void);
void add_color(char);
void end_color(char);
#endif
