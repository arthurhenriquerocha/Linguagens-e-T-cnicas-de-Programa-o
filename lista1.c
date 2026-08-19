#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(int argc, char *argv[]) {
	
/*	int primeiro, segundo, aux;
	
	printf("Insira o primeiro Valor:");
	scanf("%d", &primeiro); 
	printf("Insira o Segundo Valor:");
	scanf("%d", &segundo);
	
	aux = primeiro;
	primeiro = segundo;
	segundo = aux;
	
	
	
	
	
	
	printf("%d, %d\n\n", primeiro, segundo);
	
	//primeiro ex
	
	double numero, mantissa;
	int expoente = 0;
	printf("Digite o numero que deseja ver em notacao cientifica: ");
	scanf("%lf", &numero);
	mantissa = numero; 
	if (mantissa != 0) {
        while (mantissa >= 10) {
            mantissa /= 10;
            expoente++;
        }
        while (mantissa < 1) {
            mantissa *= 10;
            expoente--;
        }
    }

    printf("Valor em notacao cientifica: %.2lf x 10^%d\n\n\n", mantissa, expoente);
	
	
	//segundo ex
	
	
	int n, bit_64, bit_32, bit_16, bit_8, bit_4, bit_2, resultado;
	
	printf("Digite o valor para conversao: ");
	scanf("%d", &n);
	
	
	bit_64 = n%2;
	resultado = n/2;
	
	
	bit_32 = resultado%2;
	resultado = resultado/2;
	
	
	bit_16 = resultado%2;
	resultado = resultado/2;
	
	bit_8 = resultado%2;
	resultado = resultado/2;
	
	bit_4 = resultado%2;
	resultado = resultado/2;
	
	
	bit_2 = resultado%2;
	resultado = resultado/2;
	
	
	printf("O numero %d em binario = %d%d%d%d%d%d%d", n, resultado%2, bit_2, bit_4, bit_8, bit_16, bit_32, bit_64);
	

//terceiro ex
	
	float venda, comi, salario, total;
	
	printf("Digite o valor do salario:");
	scanf("%f", &salario);
	
	printf("Digite o valor total de vendas:");
	scanf("%f", &venda);
	
	
	comi = venda *0.15;
	
	
	total = venda + comi + salario;
	
	printf( "%.2f\n\n", total);

// quarto ex

*/


int x1, x2, y1, y2, p1, p2;
float dist;

printf("Insira as cordenadas do ponto P1: ");
scanf("%d, %d", &x1, &y1);



printf("Insira as cordenadas do ponto P2: ");
scanf("%d, %d", &x2, &y2);

p1 = pow(x2-x1, 2);
p2 = pow(y2-y1, 2);

dist = sqrt(p1+p2);

printf("Distancia (%f)", dist);
// resolver problema de mostrar resultado no p2




	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
