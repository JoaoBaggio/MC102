/*
 * lab07.c
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
#include <string.h>
#define MAX_LINHAS 100
#define MAX_COLUNAS 151

/*Funcao Principal*/
int main(){
	char RD[26] = "JAMTUDFRVENWBCLHOXYQIPKZGS";
	char RC[26] = "RWOPEJTLYBCNQGAIHVMSFXKDZU";
	char RE[26] = "TJKAOZUMFHIGNVCSLYBDPQEWRX";
	char RF[26] = "QYHOGNECVPUZTFDJAXWMKISRBL";
	char mensagem[MAX_LINHAS][MAX_COLUNAS], chave[MAX_COLUNAS];
	char B1, B2, B3, c;
	int b1, b2, b3;
	int i, j, linhas, indic, lchave;
	
	
	/*Le a entrada*/
	scanf("%c%c%c", &B1,&B2,&B3);
	scanf("%d", &linhas);
	for(i = 0; i< linhas; i++)
		scanf("%s", mensagem[i]);
	scanf("%d", &lchave);
	scanf("%s", chave);
	
	/*Troca para inteiro*/
	b3 = B3 - 'A';
	b1 = B1 - 'A';
	b2 = B2 - 'A';
	
	/*Percorre todos os caracteres*/
	for(i = 0; i<linhas; i++){
		for(j = 0; j < strlen(mensagem[i]); j++){
			c = mensagem[i][j];
			/*Incrementa as bases verificando o limete*/
			b3 = (b3 +1)%26;
			if((b3+'A')  == 'R'){
				b2 = (b2 +1)%26;
				if((b2+'A') == 'W')
					b1 = (b1 +1)%26;
			}
			/*Passa pelo rotor direito*/
			c = RD[(c-'A'+b3)%26];
			/*passa pelo rotor central*/
			c = RC[(c-'A'+b2)%26];
			/*passa pelo rotor esquero*/
			c = RE[(c-'A'+b1)%26];
			/*passa pelo refletor*/
			c = RF[(c-'A')%26];
			
			/*Descobre qual e a posicao da letra no rotor esquerdo*/
			for(indic=0; RE[indic]!=c; indic++);
			indic = indic - b1;
			if(indic < 0) /*caso negativo*/
				indic = indic + 26;
			c = 'A' + indic;
			
			/*Descobre qual e a posicao da letra no rotor central*/
			for(indic=0; RC[indic]!=c; indic++);
			indic = indic - b2;
			if(indic < 0)
				indic = indic + 26;
			c = 'A' + indic;
		
			/*Descobre qual e a posicao da letra no rotor da direito*/
			for(indic=0; RD[indic]!=c; indic++);
			indic = indic - b3;
			if(indic < 0)
				indic = indic + 26;
			c = 'A' + indic;
			
			/*Guarda a variavel que iluminou*/
			mensagem[i][j] = c;
		}
	}
	/*Imprime colocando ' ' nos lugares de XX*/
	if(strstr(mensagem[lchave], chave)){ /*Se existe a chave na linha*/
		for(i = 0; i < linhas; i++){
			for(j = 0; mensagem[i][j] != '\0'; j++)
				if(mensagem[i][j] == 'X' && mensagem[i][j+1] == 'X')
					mensagem[i][j+1] = ' ';
				else
					printf("%c", mensagem[i][j]);
			printf("\n");
		}
	}
	else /*nao tem chave*/
		printf("Chave Incorreta\n");
	return 0;
}
