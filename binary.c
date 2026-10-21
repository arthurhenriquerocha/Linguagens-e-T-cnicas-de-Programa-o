#include <stdio.h>
#include <stdlib.h>


int main() {
    int n, aux, multi=1;
    scanf("%d", &n);
    aux=0;
while(n>0){
	aux = aux + (n%2)*multi;
	n = n/2;
	multi = multi*10;
}
printf("%d", aux);

    return 0;
}
