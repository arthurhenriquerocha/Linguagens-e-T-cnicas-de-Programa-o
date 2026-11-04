#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bandeira 9
#define bomba 0

int main(int argc, char *argv[]) {
	//CAMPO MINADO
	
	srand(time(NULL));
	int campo[9][9];
	int casaX, casaY, i, j;
	
	//limpa a mossa matriz e inserir 9 em todas as posicoes
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			campo [i][j] = 9;
		}
	}
	
	//preencha com bobas nosso jogo
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			if (rand()%10 == 0)
				campo[i][j] = 0;	
		} 
	}
	
	printf("CAMPO MINADO \n-------------------- \n");
		for(i=0; i<9; i++){
			for(j=0; j<9; j++)
			printf("|%d", campo[i] [j]);
		
		printf("|\n");
	}
	
	return 0;
}

