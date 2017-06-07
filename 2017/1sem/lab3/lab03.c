/*
 * lab03.c
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
	int passos, estrelas, x = 50, y = 50, temp; /*Declaracao de variaveis*/
	char ix = 'N', iy = 'O', itemp;
	int i, flag;
	scanf("%d", &passos);
	for (i = 0; i < passos; i++){ /*Loop com o numero de passos*/
		scanf("%d %c", &temp, &itemp); /*Le o proximo passo*/
	
		if(itemp == 'N'){ /*Se for para norte*/
			if(itemp == ix){ /*Se for para norte e voce esta ja no norte*/
				x += temp;
				if( x > 90){ /*Caso ultrapasse o limite*/
					x = 180 - x;
					y = 180 - y;
					if(iy == 'L')
						iy = 'O';
					else
						iy = 'L';
				}
			}
			else{
				x -= temp; /*Se for para norte e voce esta no sul*/
				if(x <= 0){  /*Caso ultrapasse o equador*/
					x = (-1)*x;
					ix = 'N';
				}
			}
		}
		
		else if(itemp == 'S'){ /*Se for para o Sul*/
			if(itemp == ix){ /*Se for para o Sul e vc esta ja no sul*/
				x += temp; 
				if( x > 90){ /*Caso ultrapasse o limite inferior*/
					x = 180 - x;
					y = 180 - y;
					if(iy == 'L')
						iy = 'O';
					else
						iy = 'L';
				}
			}
			else{
				x -= temp; /*Se for para o Sul mas esta no norte*/
				if(x < 0){ /*Caso ultrapasse o equador*/
					x = (-1)*x;
					ix = 'S';
				}
			}
		}
		
		else if(itemp == 'O'){ /*Se for para o Oeste*/
			if(itemp == iy){ /*Voce esta no oeste*/
				y += temp;
				if(y > 180){ /*troca de hemisferio*/
					y = 360 - y;
					iy = 'L';
				}
			}
			else { /*voce esta no leste*/
				y -= temp;
				if( y < 0){ /*troca de hemisferio*/
					y = (-1)*y;
					iy = 'O';
				}
			}
		}

		else if(itemp == 'L'){ /* se for para o leste*/
			if(itemp == iy){ /* voce esta no leste*/
				y += temp;
				if(y >= 180){ /*troca de hemisferio*/
					y = 360 - y;
					iy = 'O';
				}
			}
			else{ /*voce esta no oeste*/
				y -= temp;
				if( y <= 0){ /*troca de hemisferio*/
					y = (-1)*y;
					if(y != 180)
						iy = 'L';
				}
			}
		}
	}
	scanf("%d", &estrelas);
	for (i = 0, flag = 0; i < estrelas; i++){ /*loop verifica corretude do mapa*/
		scanf("%d %c", &temp, &itemp);
		/*flag = 1 indica que pelo menos foi achada uma estrela guia*/
		if(itemp == ix && temp == x){ 
			scanf("%d %c", &temp, &itemp);
			if(itemp == iy && itemp == 'O' && temp <= y+10 && temp >= y)
				flag = 1;
			if(itemp == iy && itemp == 'L' && temp >= y-10 && temp <= y)
				flag = 1;
			if(itemp != iy && (temp + y) <= 10 && itemp == 'O')
				flag = 1;
			if(itemp != iy && (temp + y) >= 350 && itemp == 'L')
				flag = 1;	
		}
		else{
			scanf("%d %c", &temp, &itemp);
		}
	}
	/*Imprime resposta*/
	printf("%d %c %d %c\n", x, ix, y, iy);
	if(flag)
		printf("Mapa Correto\n");
	else
		printf("Mapa Incorreto\n");	
	return 0;
}
