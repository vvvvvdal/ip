#include <stdio.h>

int calcBinario(int n) {
    int binario[32];

    if(n == 0) {
        printf("0\n");
    } else if(n == 1) {
        printf("1\n");
    } else {
        int i = 0, nCalc = n;

        while(nCalc > 0) {
            binario[i] = nCalc%2;
            nCalc /= 2;
            i++;
        }

        int j;
        for(j = (i-1); j >= 0; j--){
            printf("%d", binario[j]);
        }

        printf("\n");
    }

}

int main() {
    int n;

    while(scanf("%d", &n) != EOF) {
        calcBinario(n);
    }

    return 0;
}