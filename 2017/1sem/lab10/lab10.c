/*
 * lab10.c
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
#include <lab10.h>

int tamanho (char maoJogador[]){
	int i;
	for(i = 0; maoJogador[i]; i++);
	return i;
} 
void cria_basic(char m[22][12]){
	int i, j;
	
	for(i = 0; i<22;i++)
		for(j = 0; j < 12; j++)
			m[i][j] = 'X';
	
	for(i = 17; i<22;i++)
		for(j = 0; j < 12; j++)
			m[i][j] = 'S';
	
	for(i = 12; i<17;i++)
		for(j = 0; j < 7; j++)
			m[i][j] = 'S';
	
	for(i = 9; i<12;i++)
		for(j = 3; j < 7; j++)
			m[i][j] = 'D';
	
	for(i = 0; i<22;i++)
		for(j = 0; j < 12; j++)
			if(m[i][j] == 'X')
				m[i][j] = 'H';
}

void cria_soft(char m[22][12]){
	int i, j;
	
	for(i = 0; i<22;i++)
		for(j = 0; j < 12; j++)
			m[i][j] = 'X';
	for(i = 12; i<19;i++)
		for(j = 4; j < 7; j++)
			m[i][j] = 'D';
	for(i = 19; i<22;i++)
		for(j = 0; j < 12; j++)
			m[i][j] = 'S';
	m[17][2] = 'S';
	m[17][3] = 'D';
	m[17][7] = 'S';
	m[17][8] = 'S';
	m[18][2] = 'S';
	m[18][3] = 'D';
	m[18][7] = 'S';
	m[18][8] = 'S';
	for(i = 0; i<22;i++)
		for(j = 0; j < 12; j++)
			if(m[i][j] == 'X')
				m[i][j] = 'H';
}

int valor(char mao[]){
	int i, tam, as = 0, flag = 0, soma = 0;
	tam = tamanho(mao);
	for(i=0; i< tam; i+=2){
		if(mao[i] <= '9' && mao[i] >= '1')
			soma += mao[i] -'0';
		else if(mao[i] != 'A')
			soma +=10;
		else
			soma +=11;
	}
	/*verifica se tem as*/
	for(i=0; i < tam; i+=2)
		if(mao[i] == 'A')
			as = 1;
	
	if(as && soma < 21) /*Soft Hand*/{		
		soma *= (-1);
	}
	else{
		while(as && soma > 21){	
			if (soma>21 && as){
				for(i=0, flag = 0; i < tam && !flag; i+=2){
					if(mao[i] == 'A'){
						soma-=10;
						flag =1;
						mao[i] = '1';
						as = 0;
					}
				}
			}
			/*verifica se tem as*/
			for(i=0; i < tam; i+=2)
				if(mao[i] == 'A')
					as = 1;
		}
	}
	return soma;
}

int basicStrategy(char maoJogador[], int valorCartaCrupie){
	int value, retorna = -1;
	char basic[22][12], softbasic[22][12], jogada;
	cria_basic(basic);
	cria_soft(softbasic);
	
	value = valor(maoJogador);
	if(value < 0) /*soft*/
		jogada = softbasic[value*(-1)][valorCartaCrupie];
	else
		jogada = basic[value][valorCartaCrupie];

	if(jogada == 'H')
		retorna = 0;
	else if(jogada == 'D')
		retorna = 1;
	else if(jogada == 'S')
		retorna = 2;
		
	return retorna;
}


void hit(char baralho[], char mao[]){
	int tambaralho, tammao, i;
	tambaralho = tamanho(baralho);
	tammao = tamanho(mao);
	/*Coloca na mao a primeira carta*/
	mao[tammao] = baralho[0];
	mao[tammao+1] = baralho[1];
	/*retira a carta do topo do baralho*/
	for(i = 0; i < tambaralho; i++)
		baralho[i] = baralho[i+2];
}

int crupie(char baralho[], char mao[]){
	int value;
	value = valor (mao);
	if(value < 0)
		value *=-1;
	while (value <= 17){
		hit(baralho, mao);
		value = valor(mao);
		if(value < 0)
			value *=-1;
	}
	return value;
}

int blackjack(char mao[]){
	int value, retorno;
	value = valor(mao);
	if(value < 0)
		value *=-1;
		
	if(value == 21)
		retorno =  1;
	else
		retorno = 0;
	return retorno;
}

void printCards(char mao[]){
	int i, tam;
	tam = tamanho(mao);
	/*Corrige os As*/
	for(i = 0; i < tam; i+=2)
		if(mao[i] == '1')
			mao[i] = 'A';
	for(i = 0; i < tam; i+=2)
		printf(".--. ");
	printf("\n");
	for(i = 0; i < tam; i+=2)
		printf("|%c%c| ", mao[i], mao[i+1]);
	printf("\n");
	for(i = 0; i < tam; i+=2)
		printf("'--' ");
	printf("\n\n");
}

int main(int argc, char **argv){
	char maoCrupie[TAMANHO_HAND*2], maoJogador[TAMANHO_HAND*2];
	char baralho[TAMANHO_BARALHO*2+3];
	int i, stand = 0, jogada;
	int valorJogador, valorCartaCrupie, valorCrupie;
	float saldo = 100, aposta;
	/*Inicializa os vetores*/
	for(i = 0; i < TAMANHO_HAND*2; i++)
		maoCrupie[i] = maoJogador[i] = '\0';	
	for(i = 0; i < TAMANHO_BARALHO*2+3; i++)
		baralho[i] = '\0';
	/*Le o baralho e a aposta da rodada*/
	for(i = 0; i<TAMANHO_BARALHO*2; i++)
		scanf("%c ", &baralho[i]);
	scanf("%f", &aposta);
	saldo -= aposta;
	/*Entrega as 4 primeiras cartas*/
	hit(baralho, maoJogador);
	hit(baralho, maoCrupie);
	hit(baralho, maoJogador);
	hit(baralho, maoCrupie);
	
	/*Blackjack na primeira mao*/
	if(blackjack(maoJogador)){
		printCards(maoJogador);
		maoCrupie[2] = maoCrupie[3] = 'X';
		printCards(maoCrupie);
		printf("BLACKJACK\n");
		printf("R$ %.2f\n", (saldo+aposta) + 1.5*aposta);
	}
	/*Joga o jogo*/
	else {
		if(maoCrupie[0] == 'A')
			valorCartaCrupie = 11;
		else if (maoCrupie[0] <= '9' && maoCrupie[0] > '1')
			valorCartaCrupie = maoCrupie[0] - '0';
		else
			valorCartaCrupie = 10;
		
		valorJogador = valor(maoJogador);
		if(valorJogador < 0)
			valorJogador *= -1;
		while(stand == 0 && valor(maoJogador) <= 21){
			jogada = basicStrategy(maoJogador, valorCartaCrupie);
			/*hit*/
			if(jogada == 0){
				hit(baralho, maoJogador);
				valorJogador = valor(maoJogador);
				if(valorJogador < 0)
					valorJogador *= -1;
			}
			else if(jogada == 1){ /*double*/
				if(aposta < saldo){
					saldo -=aposta;
					aposta *=2;
				}
				hit(baralho, maoJogador);
				valorJogador = valor(maoJogador);
				if(valorJogador < 0)
					valorJogador *= -1;
			}
			/*stand*/
			else if(jogada == 2){
				stand = 1;
			}
		}
		/*Estourou*/
		if(valorJogador > 21){
			printCards(maoJogador);
			maoCrupie[2] = maoCrupie[3] = 'X';
			printCards(maoCrupie);
			printf("JOGADOR ESTOUROU\n");
			printf("R$ %.2f\n", saldo);
		}
		/*rodada crupie*/
		else if(stand == 1 && valorJogador <= 21){
			valorCrupie = crupie(baralho, maoCrupie);
			if(valorCrupie > 21){
				printCards(maoJogador);
				printCards(maoCrupie);
				printf("CRUPIE ESTOUROU\n");
				printf("R$ %.2f\n", saldo + aposta*2);	
			}
			else if(valorCrupie > valorJogador){
				printCards(maoJogador);
				printCards(maoCrupie);
				printf("CRUPIE VENCEU\n");
				printf("R$ %.2f\n", saldo);
			}
			else if (valorCrupie == valorJogador){
				printCards(maoJogador);
				printCards(maoCrupie);
				printf("EMPATE\n");
				printf("R$ %.2f\n", saldo + aposta);
			}
			else if(valorCrupie < valorJogador){
				printCards(maoJogador);
				printCards(maoCrupie);
				printf("JOGADOR VENCEU\n");
				printf("R$ %.2f\n", saldo + aposta*2);	
			}
			
		}
	}
	return 0;
}
