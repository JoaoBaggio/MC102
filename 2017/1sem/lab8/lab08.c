/*
 * lab08.c
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
#define MAX 300

int main(){
	int i, j, v[MAX*MAX*3], coluna , linha, tam, inicio, fim, lixo;
	char bases[MAX*MAX*3/14];
	
	scanf("P3 %d %d 255", &coluna, &linha);
	tam = coluna * linha * 3;
	
	/*Le  somente as variaveis que realmente importam*/
	for(i = 0; i < tam/7; i++){
		scanf("%d %d %d %d %d %d", &lixo,&lixo,&lixo,&lixo,&lixo,&lixo);
		scanf("%d", &v[i]);
	}
	
	/*Acha todas as bases*/
	for(i = 0, j = 0; i < (tam/7) -1; i+=2, j++){
		if(v[i]%2 == 0 && v[i+1]%2 == 0) /*Dois pares*/
			bases[j] = 'G';
		else if(v[i]%2 == 0 && v[i+1]%2 == 1) /*Par e Impar*/
			bases[j] = 'A';
		else if(v[i]%2 == 1 && v[i+1]%2 == 0) /*Impar e Par*/
			bases[j] = 'C';
		else if(v[i]%2 == 1 && v[i+1]%2 == 1) /*Impar e Impar*/
			bases[j] = 'U';
	}
	/*Verifica se tem um codon de iniciacao*/
	for(i = 0, inicio = -1; i< (tam/7)-2 && inicio == -1; i++)
		if(bases[i] == 'A' && bases[i+1] == 'U' && bases[i+2] == 'G')
			inicio = i;
	
	/*verifica se tem acha um final se achou um inicio*/
	for(i=inicio+3, fim=-1; i<tam/7 && inicio >= 0 && fim == -1; i+=3){
		if(bases[i] == 'U'){
			if(bases[i+1] == 'A' && bases[i+2] == 'G')
				fim = i;
			else if(bases[i+1] == 'G' && bases[i+2] == 'A')
				fim = i;
			else if(bases[i+1] == 'A' && bases[i+2] == 'A')
				fim = i;	
		}
	}
	/*Imprime se achou uma fita valida*/
	if(inicio !=-1 && fim !=-1){	
		for(i = inicio; i <= fim; i+=3)
			printf("%c%c%c ", bases[i], bases[i+1], bases[i+2]);
		printf("\n");
	}
	else
		printf("Nao foi possivel encontrar uma fita de RNA valida\n");
	
	return 0;
}
