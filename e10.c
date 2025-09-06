#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    int i;
    int possibilidades = 0;
 
    for(i = 1; i < 7; i++) {
        int j = n - i;
 
        if(1 <= j && j <= 6 && j != i) {
            printf("D1: %d, D2: %d\n", i, j);
            possibilidades++;
        }
    }
 
    if(possibilidades == 0) {
        printf("Combinacao impossivel\n");
    } else {
        printf("Ha %d possibilidades\n", possibilidades);
    }
 
    return 0;
}
