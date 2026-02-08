#include <stdio.h>

int main() {
    int qtd;
    
    while(scanf("%d", &qtd) == 1 && qtd != 0) {
        int numerosMeio = qtd - 2;
        int ctg = 0;
        
        int anterior, atual, proximo;
        
        scanf("%d %d", &anterior, &atual);

        int i;
        for(i = 0; i < numerosMeio; i++) {
            
            scanf("%d", &proximo);
            
            int crescente = (anterior < atual && atual > proximo);
            int decrescente = (anterior > atual && atual < proximo);

            if(crescente || decrescente) {
                ctg++;
            }
            
            anterior = atual;
            atual = proximo;
        }
        
        if(ctg == numerosMeio) {
            printf("Intercalada\n");
        } else {
            printf("Nao intercalada\n");
        }
    }

    return 0;
}