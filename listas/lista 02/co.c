#include <stdio.h>
#define N 100

int main() {
    int ta, tb, i, j, anovo[N], bnovo[N];

    do {
        scanf("%d", &ta);
    } while (ta < 1 || ta > 100);

    do {
        scanf("%d", &tb);
    } while (tb < 1 || tb > 100);

    for (i = 0; i < ta; i++) {
        int temp_val;
        scanf("%d", &temp_val);
        
        int ehRepetido = 0;
        for (j = 0; j < i; j++) {
            if (anovo[j] == temp_val) {
                ehRepetido = 1;
                break;
            }
        }
        
        if (ehRepetido) {
            i--;
        } else {
            anovo[i] = temp_val;
        }
    }

    for (i = 0; i < tb; i++) {
        int temp_val;
        scanf("%d", &temp_val);
        
        int ehRepetido = 0;
        for (j = 0; j < i; j++) {
            if (bnovo[j] == temp_val) {
                ehRepetido = 1;
                break;
            }
        }

        if (ehRepetido) {
            i--;
        } else {
            bnovo[i] = temp_val;
        }
    }
    
    int tc = 0, conj_diff[N];
    for (i = 0; i < ta; i++) {
        int achou = 0;
        for (j = 0; j < tb; j++) {
            if (bnovo[j] == anovo[i]) {
                achou = 1;
                break;
            }
        }

        if (achou == 0) {
            conj_diff[tc] = anovo[i];
            tc++;
        }
    }

    printf("(");
    for (i = 0; i < ta; i++) {
        printf("%d", anovo[i]);
        if (i < ta - 1) {
            printf(",");
        }
    }
    printf(")\n");

    printf("(");
    for (i = 0; i < tb; i++) {
        printf("%d", bnovo[i]);
        if (i < tb - 1) {
            printf(",");
        }
    }
    printf(")\n");

    printf("(");
    for (i = 0; i < tc; i++) {
        printf("%d", conj_diff[i]);
        if (i < tc - 1) {
            printf(",");
        }
    }
    printf(")\n");

    printf("(");
    for (i = 0; i < ta; i++) {
        for (j = 0; j < tb; j++) {
            printf("(%dx%d)", anovo[i], bnovo[j]);
            if (i < ta - 1 || j < tb - 1) {
                printf(",");
            }
        }
    }
    printf(")\n");

    return 0;
}