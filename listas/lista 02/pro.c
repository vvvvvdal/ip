#include <stdio.h>
#include <math.h>

int modulo(int dist) {
    if(dist < 0) {
        dist *= -1;
    }

    return dist;
}

/**
* Função que calcula a potencia de p mais próximo a n.
* @param n valor inteiro
* @param p valor da potencia
* @return retorna o valor da potencia mais proxima.
*/
int next_power( int n, int p ) {
    int i, dist_nova = 0, dist_inicial, j;

    for(i = 1; i < 10; i++) {
        if(i == 1) {
            j = pow(1, p);
            dist_nova = j - n;
            dist_inicial = modulo(dist_nova);
        } else {
            j = pow(i, p);
            dist_nova = j - n;
            dist_nova = modulo(dist_nova);

            if(dist_nova >= dist_inicial) {
                i--;
                j = pow(i, p);
                break;
            } else {
                continue;
            }
        }
    }

    printf("%d -> %d^%d = %d\n", n, i, p, j);

    return j;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    next_power(n, p);

    return 0;
}