#include <stdio.h>
#include <string.h>
#define N 150

long int string2int(const char * str) {
    int i, tam = strlen(str), ehPositivo = 1;
    long int n = 0, num[N];

    for(i = 0; i < tam; i++) {
        if(str[0] == '-') {
            ehPositivo = 0;
        }
    }

    if(ehPositivo == 0) {
        for(i = 1; i < tam; i++) {
            num[i] = str[i] - '0';
        }
    } else {
        for(i = 0; i < tam; i++) {
            num[i] = str[i] - '0';
        }
    }
    
    if(ehPositivo == 0) {
        int a = 1;
        for(i = (tam-1); i >= 1; i--) {
            n += (a * num[i]);
            a *= 10;
        }
    } else {
        int b = 1;
        for(i = (tam-1); i >= 0; i--) {
            n += (b * num[i]);
            b *= 10;
        }
    }

    if(ehPositivo == 1) {
        printf("%ld %ld\n", n, n*2);
    } else {
        printf("-%ld -%ld\n", n, n*2);
    }

}

int main() {
    char str[N];

    while(scanf("%s", str) != EOF) {
        string2int(str);
    }

    return 0;
}