#include <stdio.h>

int main() {
    int n, m, matriz[100][100], i, j, k, l, ctg;
    double frequencia[100][100];

    scanf("%d %d", &n, &m);
    if((n < 1 || n > 100) || (m < 1 || m > 100)) return 0;

    double total = (n * m); 

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            ctg = 0;
            for(k = 0; k < n; k++) {
                for(l = 0; l < m; l++) {
                    if(matriz[i][j] == matriz[k][l]) ctg++;
                }
            }
            frequencia[i][j] = ctg;
        }
    }


    int maior_m = matriz[0][0];
    int menor_m = matriz[0][0];
    double ctg_maior = frequencia[0][0];
    double ctg_menor = frequencia[0][0];

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            
            if(matriz[i][j] > maior_m) {
                maior_m = matriz[i][j];
                ctg_maior = frequencia[i][j];
            }
            
            if(matriz[i][j] < menor_m) {
                menor_m = matriz[i][j];
                ctg_menor = frequencia[i][j];
            }
        }
    }

    double perc_menor = (ctg_menor / total) * 100.0;
    double perc_maior = (ctg_maior / total) * 100.0;

    printf("%d %.2f%%\n", menor_m, perc_menor);
    printf("%d %.2f%%\n", maior_m, perc_maior);

    return 0;
}