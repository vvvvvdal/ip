#include <stdio.h>

int main() {

    int popA, popB;
    scanf("%d %d", &popA, &popB);

    int anos = 0;

    while (popA <= popB) {      // pop = pop ano 1 + pop ano 2 + ... pop ano n
        popA += popA * 0.03;
        popB += popB * 0.015;
        anos++;
    }
    
    printf("ANOS = %d\n", anos);

    return 0;
}