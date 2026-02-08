#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, *v, ehPar = 0, meio, ctgpri = 0, ctgseg = 0;
    double media = 0.0;
    scanf("%d", &n);
    if(n < 5) {
        printf("QUANTIDADE DE ELEMENTOS INVALIDOS!");
        return 0;
    }

    if(n%2 == 0) {
        ehPar = 1;
    }

    v = (int*)malloc(n*sizeof(int));

    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++) {
        media += v[i];
    }
    media /= n;

    for(i = 0; i < n/2; i++) {
        if(v[i] > media) {
            ctgpri++;
        }
    }

    for(i = n/2; i < n; i++) {
        if(v[i] > media) {
            if(ehPar == 0 && i == n/2+1) {
                ctgseg--;
            }
            ctgseg++;
        }
    }

    printf("%.2lf ", media);
    printf("%d %d ", ctgpri, ctgseg);
    if(ctgpri > ctgseg) printf("PRIMEIRA METADE\n");
    else if(ctgpri < ctgseg) printf("SEGUNDA METADE\n");
    else if(ctgpri == ctgseg) printf("EMPATE\n");

    free(v);
    return 0;
}