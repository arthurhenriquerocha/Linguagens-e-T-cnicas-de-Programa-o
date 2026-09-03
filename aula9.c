#include <stdio.h>
#include <stdlib.h>

void  exec3(){
float reais, cota;  
printf("Insira a cotação e o valor: \n");
scanf("%f %f", &cota, &reais);

printf("Os %f são %f dolares", reais, (reais/cota));
}

void exec4(){
float tempc, tempf;

printf("Insira a temperatura em C° para a conversão: \n");
scanf("%f", &tempc);


tempf = tempc * (9.0 / 5.0) + 32.0;
printf("Os %f C° são %f F \n", tempc, tempf );
}


void exec8(){
int segundos, hor, min;

printf("Insira o tempo em segundos: \n");
scanf("%d", &segundos);
hor = segundos /3600;
min = (segundos - (segundos%3600)) / 60;
segundos = segundos - ((hor * 3600) + (min*60));
printf("\t %d: %d: %d", hor, min, segundos);
}








int main(int argc, char *argv[]) {
	
	int op;
	
	printf("Insira qual ex quer resolver: [3|4|8] \n");
	scanf("%d", &op);
	
	switch (op) {
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
long double idade, ano, anonas;
	
	printf("Digite a sua idade atual: ");
	scanf("%Lf", &idade);
	printf("Digite o ano em que voce esta: ");
	scanf("%Lf", &ano);
	
	anonas = ano - idade;
	
	printf("O ano em que voce nasceu é: %.0Lf", anonas);
//ex 1

*/



case 3:
exec3();
break;
//3 ex

case 4:
exec4();
break;
//4 ex

case 8:
exec8();
break;
//erro, olhar de alguem


	/*
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
	
	// ex 10
	
	*/
	
	
	
	
	
	
	}
	return 0;
}