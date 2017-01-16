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

#define CENTER_X LINES / 4
#define CENTER_Y COLS / 4
#define ESC 27
#define RESET 'r'

char *map[]= { 	"##############################I#################O###########",
                "##############################v#################^###########",
                "I>>>>>>>>>>>>>>>>>>>>>>>>>>>>>+>>>>>>>>>>>>>>>>>E###########",
                "##############################v#############################",
                "O<<<<<<<<<<<<<<<<<<<<<<<<<<<<+======================+======X",
                "#############################^######################D<<<<<<I",
                "#############################^##############################",
                "I============================+====================+>>>>>>>>O",
                "#############################v####################v#########",
                "#############################E>>>>>>>>>>>>>>>>>>>>D#########",
                "##################################################v#########",
                "##################################################v#########",
                "I=================================================v#########",
                "##################################################E>>>>>>>>O"
};

int end_car(Car *car)
{
	if (car != NULL) {
		free(car);
	}
	endwin();
	return 0;	
}

void print_map(void)
{
	int i, j, x, y;
		
	for (i = x = 0; map[i] != NULL; i++, x++) {
		for (j = y = 0; map[i][j] != '\0'; j++, y++){
			add_color(map[i][j]);
			mvaddch(CENTER_X + x, CENTER_Y + y, map[i][j]);
			end_color(map[i][j]);
		}
	}
	return;
}

/* Printa o carro na tela em uma posição já valida dentro do mapa */
void print_car(Car *car)
{
        add_color(CARRO);
        mvaddch(CENTER_X + car->pos_x, CENTER_Y + car->pos_y, car->carro);
        end_color(CARRO);
        return;
}

/* funcao que apaga mensagens da tela */
void clear_scr()
{
	clear();
	print_map();
}

/* funcao printa mensagens de alerta */
void print_alert(int msg_n)
{
        char intransitavel[] =  	"Area intransitavel, cuidado para nao bater";
        char conver_proib_d[]  =  	"Conversao para direita proibida";
        char contramao[] =      	"Atencao! Pista de sentido unico! Voce esta tentando ir pela contramao.";
        char conver_proib_e[] =  	"Conversao proibida para a esquerda";
        char conver_direita[] = 	"Conversao obrigatoria a direita";
	char rua_s_saida[] =		"Rua sem saida.";
	char sentido_cima[] =		"Voce esta tentando voltar pela contramao! Pista de sentido para cima apenas";
	char sentido_baixo[] =		"Voce esta tentando voltar pela contramao! Pista de sentido para baixo abaixo";

	attron(A_BLINK | A_REVERSE | A_BOLD);
	if (msg_n == 1) {
	        mvprintw(CENTER_X - 2, CENTER_Y, "%s", intransitavel);
	}
	if (msg_n == 2) {
		mvprintw(CENTER_X - 2, CENTER_Y, "%s", conver_proib_d);
	}
	if (msg_n == 3) {
	        mvprintw(CENTER_X - 2, CENTER_Y, "%s", contramao);
	}
        if (msg_n == 4) {
                mvprintw(CENTER_X - 2, CENTER_Y, "%s", conver_proib_e);
        }
        if (msg_n == 5) {
                mvprintw(CENTER_X - 2, CENTER_Y, "%s", conver_direita);
        }
	if (msg_n == 6) {
        	mvprintw(CENTER_X - 2, CENTER_Y, "%s", rua_s_saida);
	}
	if (msg_n == 7) {
	        mvprintw(CENTER_X - 2, CENTER_Y, "%s", sentido_cima);
	}
	if (msg_n == 8) {
		mvprintw(CENTER_X - 2, CENTER_Y, "%s", sentido_baixo);
	}
	attroff(A_BLINK | A_REVERSE | A_BOLD);
}

/* Função diz se o movimento é valido e exibe mensagens de alerta */
bool is_valid_move(Car *car)
{
	if (car->direction & LEFT) {
		if (car->pos_y - 1 < 0) {
			return false;
		}
		if (map[car->pos_x][car->pos_y] == '>' || map[car->pos_x][car->pos_y - 1] == '>') {
			clear_scr();
			print_car(car);
			print_alert(3);
			return false;
		}	
		else if (map[car->pos_x][car->pos_y - 1] == '#') {
			clear_scr();
			print_car(car);
			print_alert(1);
			return false;

		}
                else if (map[car->pos_x][car->pos_y - 1] == 'X') {
                        car->pos_y--;
			clear_scr();
                        print_car(car);
                        print_alert(6);
                        return false;

                }

	}
	if (car->direction & RIGHT) {
		if (car->pos_y + 1 > car->max_col-1) {
			return false;
		}
		if (map[car->pos_x][car->pos_y] == '<' || map[car->pos_x][car->pos_y + 1] == '<') {
                        clear_scr();
			print_car(car);
                        print_alert(3);
                        return false;
                }
                else if (map[car->pos_x][car->pos_y + 1] == '#') {
                        clear_scr();
                        print_car(car);
                        print_alert(1);
                        return false;
		}
                else if (map[car->pos_x][car->pos_y + 1] == 'X') {
                        car->pos_y++;
			clear_scr();
                        print_car(car);
                        print_alert(6);
                        return false;
                }
	}
	if (car->direction & DOWN) {
                if (car->pos_x + 1 > car->max_row-1) {
                        return false;
                }
                if (map[car->pos_x][car->pos_y] == '^' || map[car->pos_x + 1][car->pos_y] == '^') {
                        clear_scr();
                        print_car(car);
                        print_alert(7);
                        return false;
                }
                else if (map[car->pos_x + 1][car->pos_y] == '#') {
                        clear_scr();
                        print_car(car);
                        print_alert(1);
                        return false;
                }
                else if (map[car->pos_x + 1][car->pos_y] == 'X') {
                        car->pos_x++;
			clear_scr();
                        print_car(car);
                        print_alert(6);
                        return false;
                }
        }
        if (car->direction & UP) {
                if (car->pos_x - 1 < 0) {
                        return false;
                }
                if (map[car->pos_x][car->pos_y] == 'v' || map[car->pos_x - 1][car->pos_y] == 'v') {
                        clear_scr();
                        print_car(car);
                        print_alert(8);
                        return false;
                }
                else if (map[car->pos_x - 1][car->pos_y] == '#') {
                        clear_scr();
                        print_car(car);
                        print_alert(1);
                        return false;
                }
                else if (map[car->pos_x - 1][car->pos_y] == 'X') {
                        car->pos_x--;
			clear_scr();
                        print_car(car);
                        print_alert(6);
                        return false;
                }
        }
	return true; 	
}

void print_city_name(Car *car)
{
	char lontras[] = "Lontras";
	char agrolandia[] = "Agrolandia";
	char itajai[] = "Itajai";
	char taio[] = "Taio";
	char trombudo_central[] = "Trombudo Central";
	char braco_do_trombudo[] = "Braco do Trombudo";
	char ituporanga[] = "Ituporanga";
	char rio_do_sul[] = "Rio do Sul";
	char rio_do_oeste[] = "Rio do Oeste";

	clear_scr();
	print_car(car);
        attron(A_BLINK | A_REVERSE | A_BOLD);
        mvprintw(LINES - 2, CENTER_Y, "Pressione a tecla 'r' se quiser recomecar");
	if (map[car->pos_x][car->pos_y] == 'O') {
		if (car->pos_x == 0) {
	                mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", lontras);
		}
                if (car->pos_x == 4) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", ituporanga);
                }
                if (car->pos_x == 7) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", taio);
                }
                if (car->pos_x == 13) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", itajai);
                }
	}
        if (map[car->pos_x][car->pos_y] == 'I') {
                if (car->pos_x == 0) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", agrolandia);
                }
                if (car->pos_x == 2) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", trombudo_central);
                }
                if (car->pos_x == 5) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", braco_do_trombudo);
                }
                if (car->pos_x == 7) {
                        mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", rio_do_sul);
                }
		if (car->pos_x == 12) {
                       mvprintw(CENTER_X - 2, CENTER_Y, "Voce chegou em %s", rio_do_oeste);
                }
        }
        attron(A_BLINK | A_REVERSE | A_BOLD);
}

void show_route(Car *car)
{
	int i, j, meters;
        char lontras[] = "Lontras";
        char agrolandia[] = "Agrolandia";
        char itajai[] = "Itajai";
        char taio[] = "Taio";
        char trombudo_central[] = "Trombudo Central";
        char braco_do_trombudo[] = "Braco do Trombudo";
        char ituporanga[] = "Ituporanga";
        char rio_do_sul[] = "Rio do Sul";
        char rio_do_oeste[] = "Rio do Oeste";

	meters = 0;
	i = car->pos_x;
	j = car->pos_y;
	if (car->direction & RIGHT) {
		if (j + 1 > car->max_col) {
			return;
		}
	        while ((map[i][j] == '>' || map[i][j] == '=') && j + 1 < car->max_col) {
	                meters++;
        	        j++;
        	}
	}
	if (car->direction & LEFT) {
		if(j - 1 < 0) {
			return;
		}
                while ((map[i][j] == '<' || map[i][j] == '=') && j - 1 >= 0) {
                        meters++;
                        j--;
                }
        }
	if (car->direction & DOWN) {
                if (i + 1 > car->max_row) {
                        return;
                }
                while (map[i][j] == 'v' && i + 1 < car->max_row) {
                        meters++;
                        i++;
                }
		if (meters == 0 && i + 1 <= car->max_row) {
			i++;
			meters++;
		}
        }
        if (car->direction & UP) {
                if(i - 1 < 0) {
                        return;
                }
                while (map[i][j] == '^' && i - 1 >= 0) {
                        meters++;
                        i--;
                }
		if (meters == 0 && i - 1 > 0) {
	              	i--;
                        meters++;
                }
        }
	meters *= 100;
	clear_scr();
	print_car(car);
        attron(A_BLINK | A_REVERSE | A_BOLD);
        mvprintw(CENTER_X - 2, CENTER_Y, "Voce esta a %d ", meters);
	if (map[i][j] == 'O') {
		if (i == 0) {
                        printw(" metros de %s", lontras);
                }
                if (i == 4) {
                        printw(" metros de %s", ituporanga);
                }
                if (i == 7) {
                        printw(" metros de %s", taio);
                }
                if (i == 13) {
                        printw(" metros de %s", itajai);
                }
        }
        if (map[i][j] == 'I') {
                if (i == 0) {
                        printw(" metros de %s", agrolandia);
                }
                if (i == 2) {
                        printw(" metros de %s", trombudo_central);
                }
                if (i == 5) {
                        printw(" metros de %s", braco_do_trombudo);
                }
                if (i == 7) {
                	printw(" metros de %s", rio_do_sul);
                }
                if (i == 12) {
                	printw(" metros de %s", rio_do_oeste);
                }
        }
	if (map[i][j] == '+') {
		printw(" metros do proximo cruzamento");
	}
	if (map[i][j] == 'X') {
		printw(" metros da rua sem saida");
	}
	if (map[i][j] == 'E') {
		printw(" metros da conversao a esquerda");
	}
	if (map[i][j] == 'D') {
		printw(" metros da conversao a direita");
	}
	if (map[i][j] == 'v') {
		printw(" metros da rua de sentido para baixo");
	}
	if (map[i][j] == '^') {
		printw(" metros da rua de sentido para cima");
	}
	if (map[i][j] == '=') {
		printw(" metros da pista de mao dupla");
	}
        attroff(A_BLINK | A_REVERSE | A_BOLD);
}

void print_msg_pos(Car *car)
{
	/*clear_scr();
	print_car(car);*/
        attron(A_BLINK | A_REVERSE | A_BOLD);
	if (map[car->pos_x][car->pos_y] == 'D') {
		mvprintw(CENTER_X - 4, CENTER_Y, "Voce esta na conversao a direita");
	}
	else if (map[car->pos_x][car->pos_y] == 'E') {
 	       mvprintw(CENTER_X - 4, CENTER_Y, "Voce esta na conversao a esquerda");
	}
	else if (map[car->pos_x][car->pos_y] == '+') {
	        mvprintw(CENTER_X - 4, CENTER_Y, "Voce esta no cruzamento, tome cuidado!");
	}
        attroff(A_BLINK | A_REVERSE | A_BOLD);
}

void reset(Car *car)
{
	do {
        	car->pos_x = rand() % car->max_row;
                car->pos_y = rand() % car->max_col;
        } while (map[car->pos_x][car->pos_y] == '#' || map[car->pos_x][car->pos_y] == 'X');
	clear_scr();
	print_car(car);
}

int start_map(Car *car)
{
	int ch;

	print_map();
        while (map[car->pos_x][car->pos_y] == '#' || map[car->pos_x][car->pos_y] == 'X') {
		car->pos_x = rand() % car->max_row;
                car->pos_y = rand() % car->max_col;
	}
	print_car(car);
	while ((ch = getch()) != ESC) {
		switch (ch) {
			case KEY_LEFT:
				car->direction = LEFT;
				if (is_valid_move(car)) {
					car->pos_y--;
					clear_scr();
					print_car(car);
					if (map[car->pos_x][car->pos_y] == 'I' || map[car->pos_x][car->pos_y] == 'O') {
						print_city_name(car);
					}
					else if (map[car->pos_x][car->pos_y] == '<' || map[car->pos_x][car->pos_y] == '=') {
                                                show_route(car);
                                        }
                                }
			break;
			case KEY_RIGHT:
				car->direction = RIGHT;
		                if (is_valid_move(car)) {
                                        car->pos_y++;
                                        clear_scr();
                                        print_car(car);
                                        if (map[car->pos_x][car->pos_y] == 'I' || map[car->pos_x][car->pos_y] == 'O') {
                                                print_city_name(car);
                                        }
					else if (map[car->pos_x][car->pos_y] == '>' || map[car->pos_x][car->pos_y] == '=') {
						show_route(car);
					}
                                }

			break;
			case KEY_DOWN:
				car->direction = DOWN;
	                        if (is_valid_move(car)) {
                                        car->pos_x++;
                                        clear_scr();
                                        print_car(car);
                                        if (map[car->pos_x][car->pos_y] == 'I' || map[car->pos_x][car->pos_y] == 'O') {
                                                print_city_name(car);
                                        }
					else if (map[car->pos_x][car->pos_y] == 'v') {
                                                show_route(car);
                                        }
                                }

			break;
			case KEY_UP:
				car->direction = UP;
	                        if (is_valid_move(car)) {
                                        car->pos_x--;
                                        clear_scr();
                                        print_car(car);
                                        if (map[car->pos_x][car->pos_y] == 'I' || map[car->pos_x][car->pos_y] == 'O') {
                                                print_city_name(car);
                                        }
					else if (map[car->pos_x][car->pos_y] == '^') {
                                                show_route(car);
                                        }
				}
			break;
			case RESET:
				reset(car);
			break;		
		}
		if (map[car->pos_x][car->pos_y] == 'E' || map[car->pos_x][car->pos_y] == 'D' || map[car->pos_x][car->pos_y] == '+') {
			print_msg_pos(car);
		}
	}		
	return 0;
}

int main(void)
{
	Car *car = NULL;
	
	srand(time(NULL));
	car = init_car();
	init_curses();
	init_colors();
	start_map(car);
	end_car(car);

	return 0;
}

