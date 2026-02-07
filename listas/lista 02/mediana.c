#include <stdio.h>
#define N 1000000

int main() {
    int n, num[10002];
    double mediana;
    scanf("%d%*c", &n);

    if(n < 0 || n > N) {
        return 0;
    }

    int i, j;
    for(i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for(i = 0; i < (n-1); i++) {
        for(j = 0; j < (n-1-i); j++) {
            if(num[j] > num[j+1]) {
                int temp;
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }

    }

    if(n%2 == 0) {
        int a = n/2;
        mediana = (num[a-1] + num[a]) / 2.00;
    } else {
        int b = n/2;
        mediana = num[b] * 1.00;
    }

    printf("%.2lf\n", mediana);

    return 0;
}