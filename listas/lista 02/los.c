#include <stdio.h>

int modulo(int a, int b) {
    int c = a-b;
    if(c < 0) {
        c *= -1;
    }
    
    return c;
}

int main() {
    char m[99][99], borda, meio;
    int n, i, j;

    scanf("%d %c %c", &n, &borda, &meio);

    if(n%2 == 0 || n < 1 || n > 99) {
        printf("Dimensao invalida!\n");
        return 0;
    }
    int centro = n/2, distancia;

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            distancia = modulo(i, centro) + modulo(j, centro);

            if(distancia == centro) printf("%c ", borda);
            else if(distancia < centro) printf("%c ", meio);
            else if(distancia > centro) printf("  ");
        }
        printf("\n");
    }

    return 0;
}