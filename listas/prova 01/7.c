#include <stdio.h>

int main() {
    double d1, d2, d3, p1, p2, p3;
    scanf("%lf %lf %lf", &d1, &d2, &d3);

    p1 = d1 * 0.866;
    p2 = d2;
    p3 = d3 * 0.866;
    
    if(p1 == p2 && p2 == p3) {
        printf("VOLTAR\n");
    } else if(p1 < p2 && p2 < p3) {
        printf("DIREITA\n");
    } else if(p1 > p2 && p2 > p3) {
        printf("ESQUERDA\n");
    } else {
        printf("PARAR\n");
    }

    return 0;
}