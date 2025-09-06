#include <stdio.h>
 
int main() {
    int n;
    scanf("%d", &n);
 
    int paresEncontrados = 0;
    int a = 1;
 
    while (paresEncontrados < n) {
 
        int b = 0; 
 
        int i;
        for (i = 1; i <= (a / 2); i++) {  // soma dos divisores de a
            if (a % i == 0) {
                b += i;
            }
        }
 
        if (a < b) {
            int verificar = 0;
            
            for (i = 1; i <= (b / 2); i++) {  // soma dos divisores de b
                if (b % i == 0) {
                    verificar += i;
                }
            }
            
            if (verificar == a) {  // verifica se são amigos
                printf("(%d,%d)\n", a, b);
                paresEncontrados++;
            }
        }
        
        a++;
    }
 
    return 0;
}
