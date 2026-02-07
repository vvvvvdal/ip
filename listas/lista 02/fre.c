#include <stdio.h>
#define N 100000

int main() {
    int n, lista[N], mais = -1;
 
    scanf("%d", &n);
 
    if(n < 0 || n > 100000) {
        return 0;
    }
 
    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &lista[i]);
    }
 
    int m = n, ctg = 0;
    i = 0;
    while(m >= 0) {
        int freq = 0;
        
        int j;
        for(j = 0; j < n; j++) {
            if(lista[i] == lista[j]) {
                freq++;
            }
        }

        if(freq > ctg) {
            ctg = freq;
            mais = lista[i];
        } else if(freq == ctg) {
            if(lista[i] < mais) {
                mais = lista[i];
            }
        }
        
        i++;
        m--;
    }
 
    printf("%d\n%d\n", mais, ctg);
 
    return 0;
}