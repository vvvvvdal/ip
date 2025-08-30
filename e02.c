#include <stdio.h>

int main() {

    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);

    int cent = (n1*100);  // valor deve ser <= 1000
    int dez = (n2*10);    // valor deve ser <= 100
    int uni = (n3*1);     // valor deve ser <= 10

    int numero = cent + dez + uni;
    int numeroq = numero*numero;

    if(n1 >= 10 || n2 >= 10 || n3 >= 10) {
        printf("DIGITO INVALIDO\n");
    } else {
        printf("%d, %d\n", numero, numeroq);
    }

    return 0;
}
