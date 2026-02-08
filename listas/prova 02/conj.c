#include <stdio.h>
#include <stdlib.h>

#define N 100
int main() {
    int ta, tb, *a, *b, i, temp, ehRepetido = 0, j;
    scanf("%d", &ta);
    scanf("%d", &tb);

    while (ta < 1 || ta > 100) {
        scanf("%d", &ta);
    }

    while (tb < 1 || tb > 100) {
        scanf("%d", &tb);
    }

    a = (int*)malloc(ta*sizeof(int));
    b = (int*)malloc(tb*sizeof(int));

    for(i = 0; i < ta; i++) {
        scanf("%d", &temp);
        ehRepetido = 0;

        for(j = 0; j < i; j++) {
            if(a[j] == temp) {
                ehRepetido = 1;
                break;
            }
        }
        if(ehRepetido == 1) {
            i--;
        } else {
            a[i] = temp;
        }
    }

    for(i = 0; i < tb; i++) {
        scanf("%d", &temp);
        ehRepetido = 0;
        
        for(j = 0; j < i; j++) {
            if(b[j] == temp) {
                ehRepetido = 1;
                break;
            }
        }
        if(ehRepetido == 1) {
            i--;
        } else {
            b[i] = temp;
        }
    }

    int amenosb[N], tamb = 0;

    for(i = 0; i < ta; i++) {
        ehRepetido = 0;
        
        for(j = 0; j < tb; j++) {
            if(a[i] == b[j]) {
                ehRepetido = 1;
            }
        }
        if(ehRepetido == 0) {
            amenosb[tamb] = a[i];
            tamb++;
        }
    }

    printf("(");
    for(i = 0; i < ta; i++) {
        if(i == 0) {
            printf("%d", a[i]);
        } else {
            printf(",%d", a[i]);
        }
    }
    printf(")\n");

    printf("(");
    for(i = 0; i < tb; i++) {
        if(i == 0) {
            printf("%d", b[i]);
        } else {
            printf(",%d", b[i]);
        }
    }
    printf(")\n");

    printf("(");
    for(i = 0; i < tamb; i++) {
        if(i == 0) {
            printf("%d", amenosb[i]);
        } else {
            printf(",%d", amenosb[i]);
        }
    }
    printf(")\n");

    printf("(");
    for(i = 0; i < ta; i++) {
        for(j = 0; j < tb; j++) {
            if(i == 0 && j == 0) {
                printf("(%dx%d)", a[i],b[j]);
            } else {
                printf(",(%dx%d)", a[i],b[j]);
            }
        }
    }

    printf(")\n");


    free(a);
    free(b);

    return 0;
}