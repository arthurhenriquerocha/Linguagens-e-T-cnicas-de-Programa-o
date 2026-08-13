#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	
	int primeiro, segundo, aux;
	
	printf("Insira o primeiro Valor:");
	scanf("%d", &primeiro); 
	printf("Insira o Segundo Valor:");
	scanf("%d", &segundo);
	
	aux = primeiro;
	primeiro = segundo;
	segundo = aux;
	
	
	
	
	
	
	printf("%d, %d\n", primeiro, segundo);
	
	
	
	//primeiro ex
	
	double numero;
	
	printf("digite o numero que deseja ver em notacao:");
	scanf ("%lf", &numero);
	printf("Valor em notacao cientifica : %lf \n", numero);
	
	
	//segundo ex fazer sem %e
	
	
	
	float venda, comi, salario, total;
	
	printf("Digite o valor do salario:");
	scanf("%f", &salario);
	
	printf("Digite o valor total de vendas:");
	scanf("%f", &venda);
	
	
	comi = venda *0.15;
	
	
	total = venda + comi + salario;
	
	printf( "%.2f", total);

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
