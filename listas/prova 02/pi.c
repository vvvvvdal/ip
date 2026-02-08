#include <stdio.h>
#define N 100000

int main() {
    int n, v[N], i, j, par[N], impar[N], pa = 0, im = 0, temp;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    for(i = 0; i < n; i++) {
        if(v[i]%2 == 0) {
            par[pa] = v[i];
            pa++;
        } else {
            impar[im] = v[i];
            im++;
        }
    }

    for(i = 0; i < pa; i++) {
        for(j = 0; j < pa-1-i; j++) {
            if(par[j] > par[j+1]) {
                temp = par[j+1];
                par[j+1] = par[j];
                par[j] = temp;
            }
        }
    }

    for(i = 0; i < im; i++) {
        for(j = 0; j < im-1-i; j++) {
            if(impar[j+1] > impar[j]) {
                temp = impar[j+1];
                impar[j+1] = impar[j];
                impar[j] = temp;
            }
        }
    }

    for(i = 0; i < pa; i++) {
        printf("%d\n", par[i]);
    }

    for(i = 0; i < im; i++) {
        printf("%d\n", impar[i]);
    }

    return 0;
}