#include <stdio.h>

int main() {
    int qtd, primeiro, segundo, terceiro;
    
    while(scanf("%d", &qtd) == 1 && qtd != 0) {
        scanf("%d %d", &primeiro, &segundo);

        int i, ctg = 0;
        for(i = 0; i < (qtd-2); i++) {
            scanf("%d", &terceiro);

            int cresce = (primeiro < segundo && segundo > terceiro); // 1 < 9 > 3
            int decresce = (primeiro > segundo && segundo < terceiro); // 9 >3< 8

            primeiro = segundo;
            segundo = terceiro;

            if(cresce || decresce) {
                ctg++;
            }
        }

        if(ctg == (qtd-2)) {
            printf("Intercalada\n");
        } else {
            printf("Nao intercalada\n");
        }
    }
    
    return 0;
}