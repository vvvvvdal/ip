#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int numJogo;
    int numero[6];
} CARTELA;

int main() {
    int n,i, j, qtd = 0, k;
    scanf("%d", &n);

    CARTELA *car = (CARTELA*)malloc(n*sizeof(CARTELA));

    for(i=0;i<n;i++){
        scanf("%d", &(car[i].numJogo));
        for(j=0;j<6;j++){
            scanf("%d", &(car[i].numero[j]));
        }
    }

    CARTELA sor;

    scanf("%d", &(sor.numJogo));
    for(i=0;i<6;i++){
        scanf("%d", &(sor.numero[i]));
    }

    int teve_ganhador = 0;

    for(i = 0; i < n; i++){
        qtd = 0;

        for(j = 0; j < 6; j++){
            for(k = 0; k < 6; k++){
                if(car[i].numero[j] == sor.numero[k]) {
                    qtd++;
                }
            }
        }

        if(qtd >= 4) {
            teve_ganhador = 1;

            if(qtd == 4) printf("QUADRA %d:", car[i].numJogo);
            else if(qtd == 5) printf("QUINA %d:", car[i].numJogo);
            else if(qtd == 6) printf("SENA %d:", car[i].numJogo);

            for(j = 0; j < 6; j++){
                for(k = 0; k < 6; k++){
                    if(car[i].numero[j] == sor.numero[k]) {
                        printf(" %d", car[i].numero[j]);
                    }
                }
            }
            printf("\n");
        }
    }

    if(teve_ganhador == 0) {
        printf("NENHUMA CARTELA PREMIADA PARA O CONCURSO %d\n", sor.numJogo);
    }

    free(car);

    return 0;
}