#include <stdio.h>
#include <string.h>
 
int main() {
    int n, lot[6], i;
    for(i = 0; i < 6; i++) {
        scanf("%d", &lot[i]);
    }
 
    scanf("%d%*c", &n);
    if(n < 0 || n > 50000) {
        return 0;
    }
    
    int sena = 0, quina = 0, quadra = 0;
    while(n--) {
        int aposta[6];

        for(i = 0; i < 6; i++) {
            scanf("%d", &aposta[i]);
        }
 
        int i, j, ctg = 0;
        for(i = 0; i < 6; i++) {
            for(j = 0; j < 6; j++) {
                if(aposta[j] == lot[i]) {
                    ctg++;
                    break;
                }
            }
        }

        if(ctg == 6) {
            sena++;
        } else if(ctg == 5) {
            quina++;
        } else if(ctg == 4) {
            quadra++;
        }
    }

    if(sena == 0) {
        printf("Nao houve acertador para sena\n");
    } else {
        printf("Houve %d acertador(es) da sena\n", sena);
    }

    if(quina == 0) {
        printf("Nao houve acertador para quina\n");
    } else {
        printf("Houve %d acertador(es) da quina\n", quina);
    }

    if(quadra == 0) {
        printf("Nao houve acertador para quadra\n");
    } else {
        printf("Houve %d acertador(es) da quadra\n", quadra);
    }
 
    return 0;
}