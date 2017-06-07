/*
 * lab06.c
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
	int i, j, k, l, r, num_pts, x, y;
	char matriz[MAX][MAX];
	for(i = 0; i < MAX; i++)
		for(j = 0; j < MAX; j++)
			matriz[i][j] = '0';
	scanf("%d %d", &r, &num_pts);
	for(k = 0; k < num_pts; k++){
		scanf("%d %d", &x, &y);
		for(i = 0; i < r; i++)
			for(j = 0; j < r; j++)
				if(i==x-1 &&j==y-1){
					matriz[i][j] = matriz[i][j+r] = matriz[i][j+2*r] = '*'; 
					matriz[i+r][j] = matriz[i+r][j+r] = matriz[i+r][j+2*r] = '*'; 
					matriz[i+2*r][j] = matriz[i+2*r][j+r] = matriz[i+2*r][j+2*r] = '*'; 
				}
	}
	for(i = r; i < 2*r; i++)
		for(j = r; j < 2*r; j++)
			if(matriz[i][j] == '0')
				for(k = i-1; k < i+2; k++)
					for(l = j-1; l < j+2; l++)
						if(matriz[k][l] == '*')
							matriz[i][j]++;
	for(i = r; i < 2*r; i++){
		for(j = r; j < 2*r; j++)
			printf("%c ", matriz[i][j]);
		printf("\n");
	}
	return 0;
}
