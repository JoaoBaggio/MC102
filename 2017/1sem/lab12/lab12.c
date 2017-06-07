/*
 * lab12.c
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
#include "lab12.h"

void rotate_board_CW(char* board){
	int i, j, l, k;
	char aux[10][10];
	char *b = &aux[0][0];
	for(i = 0, l = 0; i < 10; i++, l++)
		for(j = 9, k = 0; j >=0; j--, k++)
			*(b+10*l+k) = *(board + j*10+i);
	for(i = 0; i<10; i++)
		for(j = 0; j<10; j++)
			*(board + i*10 + j) = *(b+10*i+j);
}

void rotate_board_CCW(char* board){
	int i, j, l, k;
	char aux[10][10];
	char *b = &aux[0][0];
	for(i = 9, l = 0; i >=0; i--, l++)
		for(j = 0, k = 0; j <10; j++, k++)
			*(b+10*l+k) = *(board + j*10+i);
	for(i = 0; i<10; i++)
		for(j = 0; j<10; j++)
			*(board + i*10 + j) = *(b+10*i+j);
}

void rotate_all_CW(char* cube){
	int i;
	for(i = 0; i < 10; i++)
		rotate_board_CW((cube+i*100));	
}

void rotate_all_CCW(char* cube){
	int i;
	for(i = 0; i < 10; i++)
		rotate_board_CCW((cube+i*100));	
}

void find_word(char *cube, char *word, int *begin, int *end, int len){
	int i, j;
	/*Caso esteja escrito de forma linear*/
	for(i = 0; i < 1000; i++){
		if(*(cube+i) == *word){
			for(j = 0; *(cube+i+j) == *(word+j); j++);
			if(j == len-1){
				*begin = i;
				*end = i+j-1;
				return;
			}
		}	
	}
	/*Caso esteja escrito de forma vertical*/
	for(i = 0; i < 1000; i++){
		if(*(cube+i) == *word){
			for(j = 0; *(cube+i+j*10) == *(word+j); j++);
			if(j == len-1){
				*begin = i;
				*end = i+j*10-10;
				return;
			}
		}	
	}
	/*Caso esteja entre as placas*/
	for(i = 0; i < 1000; i++){
		if(*(cube+i) == *word){
			for(j = 0; *(cube+i+j*100) == *(word+j) && j < len-1; j++);
			if(j == len-1){
				*begin = i;
				*end = i+j*100-100;
				return;
			}
		}	
	}
}
int main(int argc, char **argv){
	char board[10][10][10], comando[4], palavra[11];
	char *cubo = &board[0][0][0];
	int i, j, n, qual, tam;
	int inicio=0, final=0;
	for(j = 0; j < 10; j++)
		for(i = 0; i < 10; i++)
			scanf("%c%c%c%c%c%c%c%c%c%c ", cubo+100*j+10*i+0, cubo+100*j+10*i+1, cubo+100*j+10*i+2, cubo+100*j+10*i+3, cubo+100*j+10*i+4, cubo+100*j+10*i+5, cubo+100*j+10*i+6, cubo+100*j+10*i+7, cubo+100*j+10*i+8, cubo+100*j+10*i+9);
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf(" %c%c%c", comando, (comando+1), (comando+2));
		if(*(comando+2) == 'C')
			scanf("%c", comando+3);
			
		if(*comando == 'P')
			scanf(" %d", &qual);
			
		if(*comando == 'A'){
			if(*(comando+2) == 'C')
				rotate_all_CCW(cubo);
			else
				rotate_all_CW(cubo);
		}
		else if (*comando == 'P'){
			if(*(comando+2) == 'C')
				rotate_board_CCW(cubo+qual*100);
			else
				rotate_board_CW(cubo+qual*100);
		}
	}
	scanf("%s%n", palavra, &tam);
	find_word(cubo, palavra, &inicio, &final, tam);
	printf("%s entre (%d,%d,%d) e (%d,%d,%d)\n", palavra, inicio/100, (inicio/10)%10, inicio%10, final/100, (final/10)%10, final%10);

	return 0;
}
