/*
 * lab09.c
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
#include "lab09.h"

unsigned int converter_graus(unsigned int entrada){
	return entrada/6;
}
char qual_personagem(unsigned int minutos){
	char personagem = '\0';
	if(minutos == 7 || minutos == 30)
		personagem ='R';
	else if(minutos == 23 || minutos == 25)
		personagem ='V';
	else if(minutos == 9 || minutos == 48)
		personagem ='L';
	else if(minutos == 34 || minutos == 55)
		personagem ='M';
	else if(minutos == 15 || minutos == 50)
		personagem ='D';
	else if(minutos == 42)
		personagem ='C';
	return personagem;
}
int rainha(unsigned int tempo){
	int ganhou;
	/*incluso 42 ou nao, fica a duvida*/ /*Resposta: para os testes tanto faz*/
	if(tempo<42) 
		ganhou = 1;
	else 
		ganhou = 0;
	return ganhou;
}
int valete(unsigned int jogou_criquete, unsigned int ganhou_criquete){
	int dec;
	if(jogou_criquete && ganhou_criquete)
		dec =  1; /*Decapitada*/
	else
		dec = 0;
	return dec;
}
int coelho(unsigned int jogou_criquete){
	return jogou_criquete;
}
int imprimir_personagens(char personagens[], int numero){
	int i;
	for(i = 0; i < numero; i++)
		printf("%c ", personagens[i]);
	printf("\n");
	return 0;
}
void imprimir_horario(unsigned int segundos){
	printf("%.2d:%.2d:%.2d\n", segundos/3600, (segundos/60)%60, segundos%60);
}
int main(int argc, char **argv){
	int minutos = 0, minuto_ant = 0, inteiro, jogou = 0, ganhou = 0;
	int saiu = 0, morreu = 0, total = 0, relogio = 0, tam = 0, ignorar = 0;
	char unidade, personagem, encontrados[50];
	while(saiu == 0 && morreu  == 0){
		scanf("%d %c", &inteiro, &unidade);
		switch (unidade){
			case 'S':
				total += converter_graus(inteiro);
				relogio += converter_graus(inteiro);
				break;
			case 'M':
				total += 60*converter_graus(inteiro);
				relogio += 60*converter_graus(inteiro);
				break;
			case 's':
				total += inteiro;
				relogio += inteiro;
				break;
			case 'm':
				total += 60*inteiro;
				relogio += 60*inteiro;
				break;
		}
		minuto_ant = minutos;
		minutos = (relogio/60)%60;
		if(minuto_ant != minutos){
			personagem = qual_personagem(minutos);
			if(personagem){
				encontrados[tam] = personagem;
				tam++;
			}
			if(ignorar == 0) /*sem ingnorar*/
				switch (personagem){
					case 'R':
						jogou = 1;
						ganhou = rainha(total/60);
						break;
					case 'V':
						morreu = valete(jogou, ganhou);
						if(morreu){
							printf("MORREU\n");
							imprimir_horario(total);
						}
						break;
					case 'L':
						tam = imprimir_personagens(encontrados, tam);
						tam = 0;
						break;
					case 'M':
						relogio = 0;
						break;
					case 'D':
						ignorar = 1;
						break;
					case 'C':
						saiu = coelho(jogou);
						if(saiu){
							printf("SAIU\n");
							imprimir_horario(total);
						}
						break;
				}
			/*ignorando*/
			else if (ignorar == 1 && personagem != '\0'){ 
				ignorar = 0;
				tam--;
			}
		}	
	}
	return 0;
}
