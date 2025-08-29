#include <stdio.h>

int main() {

    int numero, repeticoes;
    scanf("%d %d", &numero, &repeticoes);

    if((numero % 2) == 0) {
        printf("%d ", numero);
        
        for(repeticoes; repeticoes > 1; repeticoes--) {
            numero += 2;
            printf("%d ", numero);
        }
        printf("\n");
    } else {
        printf("O PRIMEIRO NUMERO NAO E PAR\n");
    }
    return 0;
}
