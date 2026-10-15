#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	
	/*for(i=0, j=1;i<10; i++, j--){
	printf("este eh o laco FOR\n");
	}
	*/
	/*
	while (i<10){
	printf("%d, laco While", i);
	if(n%2 == 0 ) i++;
	n++;
	}
	*/
	/*
    do{
	printf("%d, laco DO\n", i);
	if(n%2 == 0 ) i++;
	n++;
	}while (i<10);
	*/
	
	/* ex1
	int in, fim, passo, i;

    printf("Digite o primeiro valor: ");
    scanf("%d", &in);

    printf("Digite o segundo valor: ");
    scanf("%d", &fim);

    printf("Digite o passo: ");
    scanf("%d", &passo);

    for (i = in; i < fim; i += passo) {
        printf("%d ", i);
    }
	*/
	
	/*
	ex2
int n, i;
    double termo = 0.5, soma = 0;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
    soma = soma + termo;
    termo = termo / 2;
    }

    printf("A soma e: %.10lf\n", soma);	
	*/
	//ex3
	int n, i, j, num;

    printf("Digite o numero de linhas: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
    num = 1;
    for (j = 0; j <= i; j++) {
    printf("%d ", num);
    num = num * (i - j) / (j + 1);
}
    printf("\n");
    }
	
	
	
	
	
	
	
	return 0;
}
