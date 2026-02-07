#include <stdio.h>
#include <stdlib.h>

typedef struct fracao {
    int x;
    int y;
}Fracao;

int main() {
    int n, m, i, j, ctg, k, x_temp, y_temp;
    char sep;
    scanf("%d%*c", &n);

    for(i=0;i<n;i++){
        ctg = 0, m = 0, sep = 'z';
        printf("Caso de teste %d\n", i+1);

        Fracao *fracao = NULL;

        while(sep != '\n') {
            scanf("%d/%d%c", &x_temp, &y_temp, &sep);
            m++;
            fracao = (Fracao*)realloc(fracao, m*sizeof(Fracao));

            fracao[m-1].x = x_temp;
            fracao[m-1].y = y_temp;
        }

        for(j=0;j<m;j++) {
            for(k=j+1;k<m;k++){
                if(fracao[j].x * fracao[k].y == fracao[j].y * fracao[k].x){
                    printf("%d/%d equivalente a %d/%d\n", fracao[j].x, fracao[j].y, fracao[k].x, fracao[k].y);
                    ctg++;
                }
            }
        }

        if(ctg == 0) {
            printf("Nao ha fracoes equivalentes na sequencia\n");
        }

        free(fracao);
    }

    return 0;
}