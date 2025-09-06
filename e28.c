#include <stdio.h>
 
int main() {
    int a, b, c;
    char x, y, z;
 
    scanf("%d %d %d\n", &a, &b, &c);
    scanf(" %c %c %c", &x, &y, &z);
 
    // a < b < c   ou   c > b > a
 
    int menor, meio, maior;
 
    if(a < b && a < c) {
        menor = a;
    } else if(b < a && b < c) {
        menor = b;
    } else {
        menor = c;
    }
 
    if(a > b && a > c) {
        maior = a;
    } else if(b > a && b > c) {
        maior = b;
    } else {
        maior = c;
    }
 
    meio = (a+b+c) - (maior+menor);
 
    if(x == 'A') {
        if(y == 'B') {
            printf("%d %d %d\n", menor, meio, maior);
        } else if(y == 'C') {
            printf("%d %d %d\n", menor, maior, meio);
        }
    } else if(x == 'B') {
        if(y == 'A') {
            printf("%d %d %d\n", meio, menor, maior);
        } else if(y == 'C') {
            printf("%d %d %d\n", meio, maior, menor);
        }
    } else if(x == 'C') {
        if(y == 'A') {
            printf("%d %d %d\n", maior, menor, meio);
        } else if(y == 'B') {
            printf("%d %d %d\n", maior, meio, menor);
        }
    }
    
    return 0;
}
