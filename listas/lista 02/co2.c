#include <stdio.h>
#define N 100

int main() {
    int ta, tb, i, j, aconj[N], bconj[N], temp, tan = 1, tbn = 1, anovo[N], bnovo[N];
    scanf("%d %d", &ta, &tb);

    if(ta <= 0 || ta > 100) {
        while(ta <= 0 || ta > 100) {
            scanf("%d", &ta);
        }
    }

    if(tb <= 0 || tb > 100) {
        while(tb <= 0 || tb > 100) {
            scanf("%d", &tb);
        }
    }
    
    // para a
    for(i = 0; i < ta; i++) {
        scanf("%d", &aconj[i]);
    }

    anovo[0] = aconj[0];

    for(i = 1; i < ta; i++) {
        if(aconj[i] != aconj[i-1]) {
            anovo[tan] = aconj[i];
            tan++;
        }
    }

    // para b
    for(i = 0; i < tb; i++) {
        scanf("%d", &bconj[i]);
    }

    bnovo[0] = bconj[0];

    for(i = 1; i < tb; i++) {
        if(bconj[i] != bconj[i-1]) {
            bnovo[tbn] = bconj[i];
            tbn++;
        }
    }

    int tc = 0, conj[N];

    for(i = 0; i < tan; i++) {
        int achou = 0;
        // <<< CORREÇÃO: usar tbn (número de elementos válidos em bnovo), não tb
        for(j = 0; j < tbn; j++) {
            if(bnovo[j] == anovo[i]) {
                achou = 1;
                break;
            }
        }

        if(achou == 0) {
            conj[tc] = anovo[i];
            tc++;
        }
    }

    for(i = 0; i < tan; i++) {
        if(i == 0) {
            printf("(%d", anovo[i]);
        } else {
            printf(",%d", anovo[i]);
        }
    }
    printf(")\n");

    for(i = 0; i < tbn; i++) {
        if(i == 0) {
            printf("(%d", bnovo[i]);
        } else {
            printf(",%d", bnovo[i]);
        }
    }
    printf(")\n");

    printf("(");
    for(i = 0; i < tc; i++) {
        if(i == 0) {
            printf("%d", conj[i]);
        } else {
            printf(",%d", conj[i]);
        }
    }
    printf(")\n");

    printf("(");
    for(i = 0; i < tan; i++) {
        for(j = 0; j < tbn; j++) {
            if(j == 0) {
                printf("(%dx%d)", anovo[i], bnovo[j]);
            } else {
                printf(",(%dx%d)", anovo[i], bnovo[j]);
            }

        }
        if(i != (tan-1)) {
            printf(",");
        }
        
    }
    printf(")\n");

    return 0;
}
