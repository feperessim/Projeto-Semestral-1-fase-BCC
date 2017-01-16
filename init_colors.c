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

int init_colors(void)
{
	init_pair(1, COLOR_RED, COLOR_WHITE);
        init_pair(2, COLOR_GREEN, COLOR_BLACK);
        init_pair(3, COLOR_YELLOW, COLOR_YELLOW);
        init_pair(4, COLOR_BLUE, COLOR_BLUE);
        init_pair(5, COLOR_MAGENTA, COLOR_MAGENTA);
        init_pair(6, COLOR_CYAN, COLOR_CYAN);
        init_pair(5, COLOR_WHITE, COLOR_BLACK);
	init_pair(6, COLOR_YELLOW, COLOR_RED);	
	init_pair(7, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_WHITE);
        init_pair(9, COLOR_BLUE, COLOR_WHITE);
	return 0;
}
