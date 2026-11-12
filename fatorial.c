#include <stdio.h>


long long fatorial(int num) {
    long long fat = 1;
    for (int i = 2; i <= num; i++) {
        fat *= i;
    }
    return fat;
}

int main() {
    int n, p;
    
    printf("Digite o valor de n: ");
    scanf("%d", &n);
    
    printf("Digite o valor de p: ");
    scanf("%d", &p);

  //calculo dos três Fat
    long long n_fat  = fatorial(n);
    long long p_fat  = fatorial(p);
    long long np_fat = fatorial(n - p);
    
    long long combinacao = n_fat / (p_fat * np_fat);
    
    printf("\nn!     = %lld\n", n_fat);
    printf("p!     = %lld\n", p_fat);
    printf("(n-p)! = %lld\n", np_fat);
    printf("C(%d, %d) = %lld\n", n, p, combinacao);
    
    return 0;
}
