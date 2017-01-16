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

/* Aloca espaço para a estrutura Cidade e atribui valores para algumas váriaveis */ 
Car *init_car(void)
{
	Car *car = malloc(sizeof (Car));				/* Aloca espaço para a estrutura de dados da cidade */
	
	/* Se estrutura cidade = vazio então*/	
	if (car == NULL) {
		printf("Espaço insuficiente na memória para alocação");
		exit(1);
	}
	/* inicializa o mapa */
	car->carro = CARRO;
	car->max_col = 60;
	car->max_row = 14;
	car->msg_line_counter = 1;
	car->pos_x = rand() % car->max_row;
	car->pos_y = rand() % car->max_col;
	return car;
}
