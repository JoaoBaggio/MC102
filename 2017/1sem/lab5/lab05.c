/*
 * lab05.c
 * 
 * Copyright 2017 João <joao@Baggio>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 #include <stdio.h>

int main(int argc, char **argv){
	char lab[100], efeito;
	int n, x, s, st[102], sm[100], efeito_pos, efeito_pos2; 
	int pos_teseu, pos_teseu_ant, pos_mino, martelo = 0, vida = 1, i, j;
	/*inicia o labrinto*/
	for(i = 0; i < 100; i++)
		lab[i] = '\0';
		
	/*Coloca os personagens nas posicoes inicias*/
	scanf("%d %d", &n, &x);
	pos_teseu = pos_teseu_ant = n-1;
	pos_mino = 1;
	
	/*Constroi o labrinto*/
	for(i = 0; i < x; i++){
		scanf(" %c", &efeito);
		switch (efeito){
			case 'S':
				scanf("%d %d", &efeito_pos, &efeito_pos2);
				lab[efeito_pos] = '0'+ efeito_pos2;
				break;
			default:
				scanf("%d", &efeito_pos);
				lab[efeito_pos] = efeito;
				break;
		}
	}
	
	/*le os 2 sprints*/
	scanf("%d", &s);
	for(i = 0; i < s; i++)
		scanf("%d", &st[i]); 
	for(i = 0; i < s; i++)
		scanf("%d", &sm[i]);
	
	/*Caso borda nao haja sprints e o lab seja de tamanho 2*/
	if(pos_teseu == pos_mino && martelo != 1){
		printf("Morreu\n%d\n", pos_teseu);
		vida = 0;
	}
	
	
	
	/*executa os 's' sprints*/
	for(i = 0; i < s && vida; i++){
		pos_teseu_ant = pos_teseu;

		
		if(st[i] > 0){ /*sprint positivo para a esquerda*/
			for(j = 0; j < st[i] && pos_teseu != 0 && vida; j++){
				pos_teseu--;
				if(pos_teseu == pos_mino && martelo != 1){
					printf("Morreu\n%d\n", pos_teseu);
					vida = 0;
				}
			}

		}
		
		
		else if(st[i] < 0){ /*sprint negativo para a direira*/
			for(j = 0; j < (-1)*st[i] && vida; j++){
				pos_teseu++;
				if(pos_teseu == pos_mino && martelo != 1){
					printf("Morreu\n%d\n", pos_teseu);
					vida = 0;
				}
			}
			if(pos_teseu > n-1) /*Caso seja um sprint invalido*/
				pos_teseu = n-1;
		}
		
		
		/*Esta com vida e ainda esta no labrinto*/
		if(pos_teseu > 0 && vida){
			switch (lab[pos_teseu]){ 
				case '\0': /*posicao vazia nao faz nada*/
					break;
				case 'A': /*abraca de morfeu*/
					st[i+1] = 0;
					lab[pos_teseu] = '\0';
					break;
				case 'E': /*Embuste de Cronos*/
					pos_teseu = pos_teseu_ant;
					break;
				case 'F': /*Festim de Dionísio*/
					if(st[i+1]>2)
						st[i+1]=2;
					else if(st[i+1]<-2)
						st[i+1]=-2;
					if(st[i+2]>2)
						st[i+2]=2;
					else if(st[i+2]<-2)
						st[i+2]=-2;
					lab[pos_teseu] = '\0';
					break;
				case 'M': /*Martelo de Hefesto*/
					martelo = 1;
					lab[pos_teseu] = '\0';
					break;
				default: /*Segredo de Dedalo (numero)*/
					pos_teseu = lab[pos_teseu] - '0';
					if(pos_teseu == pos_mino && martelo != 1){
						printf("Morreu\n%d\n", pos_teseu);
						vida = 0;
					}
					break;
			}
		}
	
		/*Sprint do minotauro*/
		if(sm[i] > 0){ /*sprint positivo para a esquerda*/
			for(j = 0; j < sm[i] && vida; j++){
				if(pos_mino > 1)
					pos_mino--;
				if(pos_teseu == pos_mino && martelo != 1){
					printf("Morreu\n%d\n", pos_teseu);
					vida = 0;
				}
			}
		}
		else if(sm[i] < 0){ /*sprint negativo para a direira*/
			for(j = 0; j < (-1)*sm[i] && vida; j++){
				pos_mino++;
				if(pos_teseu == pos_mino && martelo != 1){
					printf("Morreu\n%d\n", pos_teseu);
					vida = 0;
				}
			}
			if(pos_mino > n-1) /*Caso seja um sprint invalido*/
				pos_mino = n-1;
		}
				
	}
	/*Tem vida e chega ao final*/
	if (vida == 1 && pos_teseu == 0)
		printf("Fugiu\n");

	return 0;
}
