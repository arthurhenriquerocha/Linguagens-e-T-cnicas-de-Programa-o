#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int a, b, c, d, maior, maior_temp1, maior_temp2;
	printf("Digite os valores a serem comparados: ");
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	maior_temp1 = (a+b+abs(a-b)) /2;
	//compara os dois primeiros
	maior_temp2 = (maior_temp1+ c + abs(maior_temp1-c))/2;
	//compara o maior dos primeiros com o c
	maior = (maior_temp2+ d + abs(maior_temp2 - d))/2;
	// compara o maior dos tres primeiros e o quarto
	printf("O maior entre |%d|%d|%d|%d| = |%d|", a, b, c, d, maior);
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
