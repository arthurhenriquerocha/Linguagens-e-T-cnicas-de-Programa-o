#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14

int main(int argc, char *argv[]) {
	
	float area, raio;
	printf("Insira o valor do raio:");
	scanf("%f", &raio);
	
	area = M_PI* pow(raio,2);
	area = pi*(raio*raio);
	
	
	
	printf("A area do circulo de raio %f = %f", raio, area);
	
	
	
	
	
	
	
	
	printf("Agora a do trapezio");
	
	
	float areat, B, b, h, d;
	
	// B maisculo = base maior, b min = base menor e h = altura.
	
	printf("Digite o valor da base maior:");
	scanf("%f", &B);
	
	
	printf("Digite o valor da base menor:");
	scanf("%f", &b);
	
	
	printf("Digite o valor da altura");
	scanf("%f", &h);
	
	d = 2;
	areat = ((B+b)* h)/d;
	
	printf("A area do trapezio ((%f + %f)* %f) / %f = %f", B, b, h, d, areat);
	
	
	return 0;
}
