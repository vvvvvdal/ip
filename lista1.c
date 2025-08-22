#include <stdio.h>

void questao1() {
        int a, b;

    // digite o a
    scanf("%d", &a);

    // digite o b
    scanf("%d", &b);

    double m = (a+b)/2.0;

    // a média é: 
    printf("%.3lf", m);
}

int main() {

    questao1();

    return 0;
}
