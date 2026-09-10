#include <stdio.h>
#include <stdlib.h>

int multidigito(int dig, int valor) {
    return dig * valor;
}

int main(int argc, char *argv[]) {

    int dig1, dig2, dig3, dig4, dig5, dig6, dig7, dig8, dig9, dgv1, dgv2, soma, resto, restoII;

    printf("Digite seu CPF: ");
    scanf("%d %d %d . %d %d %d . %d %d %d - %d %d",
          &dig1, &dig2, &dig3,
          &dig4, &dig5, &dig6,
          &dig7, &dig8, &dig9,
          &dgv1, &dgv2);

    printf("CPF digitado: %d%d%d.%d%d%d.%d%d%d-%d%d",
           dig1, dig2, dig3,
           dig4, dig5, dig6,
           dig7, dig8, dig9,
           dgv1, dgv2);

    
    // CALCULO DO 1º DIGITO VERIFICADOR
    

    soma = multidigito(dig1, 10)+multidigito(dig2, 9)+multidigito(dig3, 8)+multidigito(dig4, 7)+multidigito(dig5, 6)+multidigito(dig6, 5)+multidigito(dig7, 4)+multidigito(dig8, 3)+multidigito(dig9, 2);
    soma *= 10;
    resto = soma % 11;

    // Se o resto for 10, o digito sera 0
    if (resto == 10) {
        resto = 0;
    }

   
    // CALCULO DO 2º DIGITO VERIFICADOR
    

    soma = multidigito(dig1, 11)+multidigito(dig2, 10)+multidigito(dig3, 9)+multidigito(dig4, 8)+multidigito(dig5, 7)+multidigito(dig6, 6)+multidigito(dig7, 5)+multidigito(dig8, 4)+multidigito(dig9, 3)+multidigito(dgv1, 2);
    soma *= 10;
    restoII = soma % 11;

    // Se o resto for 10, o digito sera 0
    if (restoII == 10) {
        restoII = 0;
    }

    
    // VALIDACAO
    

    if (resto == dgv1 && restoII == dgv2) {
        printf("\n\nCPF Valido!");
    } else {
        printf("\n\nCPF Invalido!");
    }

    return 0;
}
