#include <stdio.h>

int main() {
    int n, x, y;
    scanf("%d", &n);


    for(x = 1; x < n; x++) {
        for(y = x; y < n; y++ ) {
            if(x * y == 1 || (x * y) % n == 1) {
                if(x <= y) {
                    printf("(%d,%d)\n", x, y);
                }
            }
        }

    }
    


    // 15 no Z9 = 6. pq 15 % 9 = 6.


    // invertivel em Zn se: a*b = 1 || (a*b) % n = 1

    return 0;
}