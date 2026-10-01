#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // para pow() no IMC e nas conversões

//AdsisNA 
void adsis_q0() {
    /* Recebe 5 números inteiros e mostra os que formam sequência consecutiva */
    int n[5];
    int i, j;
    int tem_consecutivo = 0;

    printf("Digite 5 numeros inteiros:\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &n[i]);
    }

    printf("Numeros consecutivos encontrados:\n");
    for(i = 0; i < 4; i++) {
        // Verifica se o próximo é consecutivo (n[i]+1 == n[i+1])
        if(n[i] + 1 == n[i+1]) {
            printf("%d %d ", n[i], n[i+1]);
            tem_consecutivo = 1;
            // Continua enquanto a sequência for crescente consecutiva
            for(j = i+1; j < 4; j++) {
                if(n[j] + 1 == n[j+1]) {
                    printf("%d ", n[j+1]);
                } else {
                    break;
                }
            }
            printf("\n");
            i = j; // pula para depois da sequência
        }
    }

    if(!tem_consecutivo) {
        printf("Nenhum numero consecutivo encontrado.\n");
    }
}

void adsis_q1() {
    /* Calcula o IMC e classifica conforme tabela do Ministério da Saúde */
    float peso, altura, imc;

    printf("Digite o peso (kg): ");
    scanf("%f", &peso);
    printf("Digite a altura (m): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);   // IMC = peso / altura²

    printf("IMC = %.2f - ", imc);

    if(imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if(imc >= 18.5 && imc <= 24.9) {
        printf("Normal\n");
    } else if(imc >= 25.0 && imc <= 29.9) {
        printf("Acima do peso\n");
    } else { // imc >= 30.0
        printf("Obeso\n");
    }
}

void adsis_q2() {
    /* Torre de Hanoi com 3 discos (valores 1,2,3)
       Pino A começa com 6 (1+2+3), B=0, C=0
       Movimento: somar/subtrair o valor do disco no pino */
    int A = 6, B = 0, C = 0;   // estado inicial
    int disco;

    printf("Estado inicial: A=%d  B=%d  C=%d\n\n", A, B, C);

    // Solução clássica da Torre de Hanoi com 3 discos (A -> C usando B)
    // Passo 1: move disco 1 de A para C
    disco = 1;
    A -= disco; C += disco;
    printf("Move disco %d: A -> C\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    // Passo 2: move disco 2 de A para B
    disco = 2;
    A -= disco; B += disco;
    printf("Move disco %d: A -> B\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    // Passo 3: move disco 1 de C para B
    disco = 1;
    C -= disco; B += disco;
    printf("Move disco %d: C -> B\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    // Passo 4: move disco 3 de A para C
    disco = 3;
    A -= disco; C += disco;
    printf("Move disco %d: A -> C\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    // Passo 5: move disco 1 de B para A
    disco = 1;
    B -= disco; A += disco;
    printf("Move disco %d: B -> A\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    // Passo 6: move disco 2 de B para C
    disco = 2;
    B -= disco; C += disco;
    printf("Move disco %d: B -> C\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    // Passo 7: move disco 1 de A para C
    disco = 1;
    A -= disco; C += disco;
    printf("Move disco %d: A -> C\n", disco);
    printf("A=%d  B=%d  C=%d\n\n", A, B, C);

    printf("Torre resolvida! Todos os discos em C.\n");
}

//prova EsoftMA
void esoftA_q0() {
    /* Recebe 4 números, verifica quais são ímpares e mostra os múltiplos de 5 */
    int n[4];
    int i;
    int encontrou = 0;

    printf("Digite 4 numeros inteiros:\n");
    for(i = 0; i < 4; i++) {
        scanf("%d", &n[i]);
    }

    printf("Numeros impares que sao multiplos de 5:\n");
    for(i = 0; i < 4; i++) {
        // Ímpar: n % 2 != 0   e   múltiplo de 5: n % 5 == 0
        if(n[i] % 2 != 0 && n[i] % 5 == 0) {
            printf("%d ", n[i]);
            encontrou = 1;
        }
    }

    if(!encontrou) {
        printf("Nenhum numero encontrado.\n");
    } else {
        printf("\n");
    }
}

void esoftA_q1() {
    /* Quantidade de mochilas totalmente preenchidas */
    int total_itens, capacidade;
    int mochilas_cheias;

    printf("Digite a quantidade total de itens: ");
    scanf("%d", &total_itens);
    printf("Digite a capacidade maxima de cada mochila: ");
    scanf("%d", &capacidade);

    mochilas_cheias = total_itens / capacidade;   // divisão inteira

    printf("Numero de mochilas totalmente preenchidas: %d\n", mochilas_cheias);
}

void esoftA_q2() {
    /* Conversão de unidades conforme tabela de códigos */
    float valor, resultado;
    int cod_entrada, cod_saida;
    int valido = 1;

    printf("Digite o valor a ser convertido: ");
    scanf("%f", &valor);
    printf("Digite o codigo da unidade de entrada: ");
    scanf("%d", &cod_entrada);
    printf("Digite o codigo da unidade de saida: ");
    scanf("%d", &cod_saida);

    // Temperatura
    if(cod_entrada == 1 && cod_saida == 2) {          // C -> F
        resultado = valor * 1.8 + 32;
    } else if(cod_entrada == 2 && cod_saida == 1) {   // F -> C
        resultado = (valor - 32) / 1.8;
    } else if(cod_entrada == 1 && cod_saida == 3) {   // C -> K
        resultado = valor + 273.15;
    } else if(cod_entrada == 3 && cod_saida == 1) {   // K -> C
        resultado = valor - 273.15;
    }
    // Comprimento
    else if(cod_entrada == 4 && cod_saida == 5) {     // m -> mi
        resultado = valor / 1609.34;
    } else if(cod_entrada == 5 && cod_saida == 4) {   // mi -> m
        resultado = valor * 1609.34;
    }
    // Massa
    else if(cod_entrada == 8 && cod_saida == 9) {     // kg -> lb
        resultado = valor * 2.205;
    } else if(cod_entrada == 9 && cod_saida == 8) {   // lb -> kg
        resultado = valor / 2.205;
    }
    // Velocidade
    else if(cod_entrada == 10 && cod_saida == 11) {   // km/h -> mph
        resultado = valor / 1.609;
    } else if(cod_entrada == 11 && cod_saida == 10) { // mph -> km/h
        resultado = valor * 1.609;
    }
    else {
        printf("Unidade nao existe no sistema ou conversao invalida.\n");
        valido = 0;
    }

    if(valido) {
        printf("Valor convertido: %.4f\n", resultado);
    }
}

//EsoftMB

void esoftB_q0() {
    /* Mochilas cheias + quantidade de itens que sobraram */
    int total_itens, capacidade;
    int mochilas_cheias, sobra;

    printf("Digite a quantidade total de itens: ");
    scanf("%d", &total_itens);
    printf("Digite a capacidade maxima de cada mochila: ");
    scanf("%d", &capacidade);

    mochilas_cheias = total_itens / capacidade;
    sobra = total_itens % capacidade;   // resto da divisão

    printf("%d\n", mochilas_cheias);   // linha 1: mochilas cheias
    printf("%d\n", sobra);             // linha 2: itens que sobraram
}

void esoftB_q1() {
    /* Três números distintos em ordem crescente */
    int a, b, c;
    int temp;

    printf("Digite tres numeros inteiros (a b c): ");
    scanf("%d %d %d", &a, &b, &c);

    // Verifica se algum é igual a outro
    if(a == b || a == c || b == c) {
        printf("os numeros tem que ser distintos\n");
        return;
    }

    // Ordena em ordem crescente (bubble sort simples)
    if(a > b) { temp = a; a = b; b = temp; }
    if(a > c) { temp = a; a = c; c = temp; }
    if(b > c) { temp = b; b = c; c = temp; }

    printf("%d %d %d\n", a, b, c);
}

void esoftB_q2() {
    /* Operações relacionais com código */
    float v1, v2;
    int codigo;

    printf("Digite o 1o valor: ");
    scanf("%f", &v1);
    printf("Digite o 2o valor: ");
    scanf("%f", &v2);
    printf("Digite o codigo da operacao (1-4): ");
    scanf("%d", &codigo);

    switch(codigo) {
        case 1: // maior que
            if(v1 > v2) printf("Verdadeiro\n");
            else        printf("Falso\n");
            break;
        case 2: // menor que
            if(v1 < v2) printf("Verdadeiro\n");
            else        printf("Falso\n");
            break;
        case 3: // igual a
            if(v1 == v2) printf("Verdadeiro\n");
            else         printf("Falso\n");
            break;
        case 4: // diferente de
            if(v1 != v2) printf("Verdadeiro\n");
            else         printf("Falso\n");
            break;
        default:
            printf("operador invalido\n");
    }
}


int main() {
    int prova, questao;
    char continuar;

    do {
        printf("\n========== MENU DE PROVAS ==========\n");
        printf("1 - ADSIS N A\n");
        printf("2 - ESOFT M A\n");
        printf("3 - ESOFT M B\n");
        printf("0 - Sair\n");
        printf("Escolha a prova: ");
        scanf("%d", &prova);

        if(prova == 0) break;

        if(prova < 1 || prova > 3) {
            printf("Prova invalida!\n");
            continue;
        }

        printf("\n--- Questoes da Prova %d ---\n", prova);
        printf("0 - Questao 0\n");
        printf("1 - Questao 1\n");
        printf("2 - Questao 2\n");
        printf("Escolha a questao: ");
        scanf("%d", &questao);

        printf("\n========== EXECUTANDO ==========\n");

        if(prova == 1) {          // ADSIS N A
            if(questao == 0) adsis_q0();
            else if(questao == 1) adsis_q1();
            else if(questao == 2) adsis_q2();
            else printf("Questao invalida!\n");
        }
        else if(prova == 2) {     // ESOFT M A
            if(questao == 0) esoftA_q0();
            else if(questao == 1) esoftA_q1();
            else if(questao == 2) esoftA_q2();
            else printf("Questao invalida!\n");
        }
        else if(prova == 3) {     // ESOFT M B
            if(questao == 0) esoftB_q0();
            else if(questao == 1) esoftB_q1();
            else if(questao == 2) esoftB_q2();
            else printf("Questao invalida!\n");
        }

        printf("\nDeseja executar outra questao? (s/n): ");
        scanf(" %c", &continuar);

    } while(continuar == 's' || continuar == 'S');

    printf("Programa finalizado.\n");
    return 0;
}
