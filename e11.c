#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int fatorial = 1;
    
    int i = 0;
    for(i; i < n; i++) { // x = n * (n-1) * (n-2)
        fatorial *= (n-i);
    }

    printf("%d! = %d\n", n, fatorial);

    return 0;
}