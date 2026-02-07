#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);

    while(t--) {
        int i, j, a[9], temp, certos[7], somaTotal = 0, errados[2];
        for(i = 0; i < 9; i++) {
            scanf("%d", &a[i]);
            somaTotal += a[i];
        }

        for(i = 0; i < 8; i++) {
            for(j = 0; j < 8-i; j++) {
                if(a[j] > a[j+1]) {
                    temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }

        int somaImp = somaTotal - 100;

        for(i = 0; i < 9; i++) {
            for(j = (i+1); j < 9; j++) {
                if(a[i] + a[j] == somaImp) {
                    errados[0] = a[i];
                    errados[1] = a[j];
                }
            }
        }

        for(i = 0; i < 9; i++) {
            if(a[i] != errados[0] && a[i] != errados[1]) {
                printf("%d\n", a[i]);
            }
        }
    }

    return 0;
}