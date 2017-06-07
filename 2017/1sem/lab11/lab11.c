/*
 * lab11.c
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
#include "lab11.h"

int proxCombinacao(int *combinacao, int n);
void avaliaCombinacao(int *combinacao, int *melhorCombinacao, int *tempoVoo, int *paxIda, int *paxVolta, int *tempoA, int *tempoB, int n);
int combinacaoValida(int *combinacao, int *paxIda, int *paxVolta, int n);

int combinacaoValida(int *combinacao, int *paxIda, int *paxVolta, int n){
	int i, valida = 1;
	for(i = 0; i < n; i++)
		if(combinacao[i] == 0)
			if(paxIda[i] > 50 || paxVolta[i] > 50)
				valida = 0;
	return valida;
}

void avaliaCombinacao(int *combinacao, int *melhorCombinacao, int *tempoVoo, int *paxIda, int *paxVolta, int *tempoA, int *tempoB, int n){
	int i, diferenca, melhor_dif=200, ta, tb;
	/*zera as combinacoes e inicializa a variavael melhor_dif*/
	for(i = 0; i<n; i++){
		combinacao[i] = melhorCombinacao[i] = 0;
		melhor_dif += tempoVoo[i]; 
	}
	do {	
		for(i = 0, ta = 0, tb = 0; i < n; i++){
			if(combinacao[i] == 0)
				tb += tempoVoo[i];
			else
				ta += tempoVoo[i];
		}
		diferenca  = ta - tb;
		if(diferenca < 0)
			diferenca *=-1;
		if(diferenca < melhor_dif && combinacaoValida(combinacao, paxIda, paxVolta, n)){
			melhor_dif = diferenca;
			*tempoA = ta;
			*tempoB = tb;
			for(i = 0; i<n; i++)
				melhorCombinacao[i] = combinacao[i];			
		}
		else if(diferenca == melhor_dif && ta > tb && combinacaoValida(combinacao, paxIda, paxVolta, n)){
			*tempoA = ta;
			*tempoB = tb;			
			for(i = 0; i<n; i++)
				melhorCombinacao[i] = combinacao[i];
		}	
	}
	while(proxCombinacao(combinacao, n) == 0);
}

int proxCombinacao(int *combinacao, int n){
	int i, saida = 1;
	for(i = 0; i < n; i++)
		if(combinacao[i] == 0)
			saida = 0;
	if(saida == 0){
		combinacao[0]++;
		for(i = 0; i<n-1; i++)
			if(combinacao[i] == 2){
				combinacao[i] = 0;
				combinacao[i+1]++;
			}
	}
	return saida;
}

int main(int argc, char **argv){
	int qtd_aero, i, tempoVoo[MAX], paxIda[MAX], paxVolta[MAX], combinacao[MAX], melhorCombinacao[MAX], tempoGrande = 0, tempoPequeno = 0;
	char aeroportos[3*MAX];

	scanf("%d ", &qtd_aero);
	for(i = 0; i<qtd_aero; i++){
		scanf("%c%c%c", &aeroportos[i*3], &aeroportos[i*3+1], &aeroportos[i*3+2]);
		scanf("%d %d %d ", &tempoVoo[i], &paxIda[i], &paxVolta[i]);
	}

	avaliaCombinacao(combinacao, melhorCombinacao, tempoVoo, paxIda, paxVolta, &tempoGrande, &tempoPequeno, qtd_aero);
	
	for(i = 0; i<qtd_aero; i++){
		printf("%c%c%c ", aeroportos[i*3], aeroportos[i*3+1], aeroportos[i*3+2]);
		if(melhorCombinacao[i] == 0)
			printf("ERJ-145\n");
		else
			printf("EMB-195\n");
	}
	printf("\nERJ-145 %d minutos\n", tempoPequeno*2);
	printf("EMB-195 %d minutos\n", tempoGrande*2);

	return 0;
}

