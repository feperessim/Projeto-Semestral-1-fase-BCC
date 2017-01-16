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

#include "mapa.h"

void add_color(char c)
{
        if (c == '#') {
                attron(COLOR_PAIR(1) | A_REVERSE | A_BOLD);
        }
        else if (c == '>' || c == '<') {
              attron(COLOR_PAIR(2));

        }
        else if (c == '+') {
                attron(COLOR_PAIR(3) | A_REVERSE | A_BOLD);
        }
        else if (c == 'I') {
                attron(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
        }
        else if (c == '=') {
                attron(COLOR_PAIR(5) | A_BOLD);
        }
        else if (c == 'E') {
                attron(COLOR_PAIR(6) | A_BOLD);
        }
        else if (c == 'v') {
                attron(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
        }
        else if (c == 'X') {
                attron(A_REVERSE | A_BOLD);
        }
        else if (c == 'O') {
                attron(COLOR_PAIR(8) | A_REVERSE | A_BOLD);
        }
        else if (c == 'D' || c == '^') {
                attron(COLOR_PAIR(5) | A_REVERSE | A_BOLD);
        }
        else if (c == '@') {
               attron(COLOR_PAIR(9) | A_BLINK | A_REVERSE | A_BOLD);
        }
}
void end_color(char c)
{
        if (c == '#') {
                attroff(COLOR_PAIR(1)| A_REVERSE | A_BOLD);
        }
        else if (c == '>' || c == '<') {
              attroff(COLOR_PAIR(2));

        }
        else if (c == '+') {
                attroff(COLOR_PAIR(3) | A_REVERSE | A_BOLD);

        }
        else if (c == 'I') {
                attroff(COLOR_PAIR(4) | A_REVERSE | A_BOLD);
        }
        else if (c == '=') {
                attroff(COLOR_PAIR(5) | A_BOLD);
        }
        else if (c == 'E') {
            attroff(COLOR_PAIR(6) | A_BOLD);
        }

        else if (c == 'v') {
                attroff(COLOR_PAIR(7) | A_REVERSE | A_BOLD);
        }
        else if (c == 'X') {
                attroff(A_REVERSE | A_BOLD);
        }
        else if (c == 'O') {
                attroff(COLOR_PAIR(8) | A_REVERSE | A_BOLD);
        }
        else if (c == 'D' || c == '^') {
                attroff(COLOR_PAIR(5) | A_REVERSE | A_BOLD);
        }
        else if (c == '@') {
        	attroff(COLOR_PAIR(9) | A_BLINK | A_REVERSE | A_BOLD);
        }
}

