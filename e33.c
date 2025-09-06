#include <stdio.h>
 
int main () {
    int nSequencial, unidadeFed, dVerificador, dVer1, dVer2;
    scanf("%d %d", &nSequencial, &unidadeFed);
 
    int algSequencial[6], algUF[2];
    int n10 = 10;
    int somaPondSeq = 0;
    int somaPondUF = 0;
    int ns = nSequencial;
    int uf = unidadeFed;
 
    int i = 0;
    for(i; i < 6; i++) {
        algSequencial[i] = nSequencial % 10;
        nSequencial /= n10;
 
        int j = 9 - i;
        somaPondSeq += algSequencial[i] * j;
    }
 
    dVer1 = somaPondSeq % 11;
    
    if(dVer1 == 10 || dVer1 == 0) {
        dVer1 = 0;
    }
 
    somaPondUF = dVer1 * 9;
    
    int k = 0;
    for(k; k < 2; k++) {
        algUF[k] = unidadeFed % 10;
        unidadeFed /= n10;
 
        int l = 8 - k;
        somaPondUF += algUF[k] * l;
    }
 
    dVer2 = somaPondUF % 11;
 
    dVerificador = (dVer1 * 10) + dVer2;
 
    if(1 < uf && uf < 28) {
            printf("%d%02d/%02d", ns, uf, dVerificador); // se o numero for menor que 10, imprime o 0 na frente.
    } else {
        printf("CODIGO DA UF INVALIDO!\n");
    }
 
    return 0;
}
