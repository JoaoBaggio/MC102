/*
 * lab13.c
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

typedef struct _habilidade {
    int id;
    int nivel;
    int habilidade_pre_req;
    int nivel_pre_req;
    int n_filhos;
    int filhos[5];
} habilidade;

void troca (habilidade *a, habilidade *b){
	habilidade aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
void selection_sort(habilidade num[], int tam) { 
	int i, j, min;
	for (i = 0; i < (tam-1); i++) {
		min = i;
		for (j = (i+1); j < tam; j++)
			if(num[j].id < num[min].id) 
				min = j;
		if (i != min) 
			troca(&num[i], &num[min]);
	}
}
int find_id(habilidade arvore[], int chave, int n){
	int retorno = -1, i;
	for(i = 0; i < n; i++)
		if(arvore[i].id == chave)
			retorno = i;
	return retorno;
}
void uppa(habilidade arvore[], int n, int id){
	int i;
	for(i = 0; i < n; i++){
		if(arvore[i].id ==  id){
			if(arvore[i].nivel_pre_req  > arvore[  find_id(arvore, arvore[i].habilidade_pre_req, n)   ].nivel)
				arvore[  find_id(arvore, arvore[i].habilidade_pre_req, n)   ].nivel = arvore[i].nivel_pre_req;
			uppa(arvore, n, arvore[i].habilidade_pre_req);
		}		
	}
}
int main(int argc, char **argv){
	int i, j, n, na, id, nivel, total, indice;
	habilidade arvore[100];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d %d %d", &arvore[i].id, &arvore[i].nivel_pre_req, &arvore[i].n_filhos);
		for(j = 0; j < arvore[i].n_filhos; j++){
			scanf("%d ", &arvore[i].filhos[j]);
		}
		arvore[i].nivel = 0;
		arvore[i].habilidade_pre_req = -1;
	}
	selection_sort(arvore, n);
	for(i = 0; i < n; i++){
		for(j = 0; j < arvore[i].n_filhos; j++){
			id = find_id(arvore, arvore[i].filhos[j], n);
			arvore[id].habilidade_pre_req = arvore[i].id;
		}
	}
	scanf("%d", &na);
	for(i = 0; i < na; i++){
		scanf("%d %d", &id, &nivel);
		indice = find_id(arvore, id, n);
		arvore[indice].nivel = nivel;
		uppa(arvore, n, id);	
	}
	
	for(i = 0, total = 0; i < n; i++)
		total += arvore[i].nivel;
	for(i = 0; i < n; i++)
		printf("ID: %d\tNiv: %d\n", arvore[i].id, arvore[i].nivel);
	printf("TOTAL: %d\n", total);

	return 0;
}
