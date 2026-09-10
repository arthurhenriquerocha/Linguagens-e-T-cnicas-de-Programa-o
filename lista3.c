#include <stdio.h>
#include <stdlib.h>


float calinss(float salario){
	
	if(salario<= 1412.00) return salario * 0.075;
	
	else if (salario <= 2666.68 ) return salario * 0.09;
	
	else if (salario <= 4000.00 ) return salario * 0.12;

	else return salario * 0.14;
	  
}

float calirpf(float salario){
	
	if (salario <= 2259.20) return salario;
	
	else if(salario >= 2259.21) return (salario * 0.075) - 169.44;
	
	else if(salario >= 2826.66) return (salario * 0.15)  - 381.44;
	
	else if(salario >= 3751.06) return (salario * 0.225) - 662.77;
	
	else if (salario >= 4664.68) return (salario * 0.275) - 896.00;
	
	
}


int main(int argc, char *argv[]) {
	
	float valorh, horastrab, salario, desconto;
	
	
	printf("==================================\n RECIBO DE PAGAMENTO DE SALARIO\n ================================== \n");
	
	
	
	printf("Digite o valor por hora trabalhada e a quantidade de horas trabalhadas: ", valorh, horastrab);
	scanf("%f %f", &valorh,&horastrab);
	
	salario = (horastrab * valorh);
	printf("%.2f", salario);
	
	
	return 0;
}