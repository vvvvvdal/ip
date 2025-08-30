#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);

    int conta3 = n % 3;
    int conta5 = n % 5;
    
    if(conta3 == 0 && conta5 == 0) {
        printf("O NUMERO E DIVISIVEL\n");
    } else {
        printf("O NUMERO NAO E DIVISIVEL\n");
    }

    return 0;
}
