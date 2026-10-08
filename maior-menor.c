#include <stdio.h>
int compara(int a, int b){ 
    if(a < b )return b;
    else return a;
}
int main(){
int valores [10];
int maior, menor, i;

printf("vamos ler os valores: ");

for(i=0; i<10; i++){
scanf("%d", &valores[i]);

}
for(i=1, maior = valores[0]; i<5; i+=2) {
    int temp = compara(valores[i], valores[i+1]);
    maior = compara(maior, temp);
}
printf("\n maior = %d", maior);
return 0;
}
