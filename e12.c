#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int listaNumeros[n];

    int i = 0;
    for(i; i < n; i++) {
        scanf("%d", &listaNumeros[i]);
    }

    int j = 1;
    int comprimentoAtual = 1;
    int comprimentoMaximo = 1;

    for(j; j < n; j++) {
        if(listaNumeros[j] > listaNumeros[j-1]) {  
            comprimentoAtual++;       // se for crescente, aumenta o comprimento
        } else {
            if(comprimentoAtual > comprimentoMaximo) {           // atualiza o comprimento maximo
                comprimentoMaximo = comprimentoAtual;
            }
            comprimentoAtual = 1;      // reinicia o comprimento
        }
    }

    if(comprimentoAtual > comprimentoMaximo) {
        comprimentoMaximo = comprimentoAtual;     // ultima contagem fora do loop
    }

    printf("O comprimento do segmento crescente maximo e: %d\n", comprimentoMaximo);

    return 0;
}