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

/* Esse arquivo inicia o modo ncurses */

#include "mapa.h"
#include <locale.h>

void init_curses(void)
{
	setlocale(LC_ALL, "");
	
	initscr();
	raw();
	noecho();
	curs_set(0);
	nl();
	keypad(stdscr, TRUE);
	if (has_colors() == FALSE) {
		endwin();
		printf("Your terminal does not support colors");
		system("clear");
		exit(1);
	}
	start_color();
}
