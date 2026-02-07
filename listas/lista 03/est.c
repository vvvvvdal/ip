#include <stdio.h>
#include <stdlib.h>

typedef struct imovel{
    int moradores;
    int consumo_total;
    int consumo_pessoa;
}Imovel;

void ordena_imovel(Imovel *imo, int n) {
    int i, j;
    Imovel temp;
    for(i=0;i<n;i++) {
        for(j=0;j<n-1-i;j++) {
            if(imo[j].consumo_pessoa > imo[j+1].consumo_pessoa ) {
                temp = imo[j];
                imo[j] = imo[j+1];
                imo[j+1] = temp;
            }
        }
    }
}


int main() {
    int n, ctg = 1, i;

    while(1){
        scanf("%d", &n);

        if(n == 0) return 0;

        Imovel *imo = (struct imovel*)malloc(n*sizeof(struct imovel));
        double consumo_medio = 0.0;
        int div = 0;
        printf("Cidade# %d:\n", ctg++);

        for(i=0;i<n;i++){
            scanf("%d %d", &(imo[i].moradores), &(imo[i].consumo_total));
            imo[i].consumo_pessoa = imo[i].consumo_total/imo[i].moradores;
        }

        for(i=0;i<n;i++){
            consumo_medio += imo[i].consumo_total;
            div += imo[i].moradores;
        }

        consumo_medio /= div;

        ordena_imovel(imo, n);

        for(i=0;i<n;i++){
            if(i==0) printf("%d-%d", imo[i].moradores, imo[i].consumo_pessoa);
            else printf(" %d-%d", imo[i].moradores, imo[i].consumo_pessoa);
        }
        printf("\n");
        printf("Consumo medio: %.2lf m3.\n\n", consumo_medio);

        free(imo);
    }

    return 0;
}