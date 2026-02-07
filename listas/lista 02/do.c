#include <stdio.h>
#include <string.h>
#define N 128

double string2double(const char *str) {
    int tam = strlen(str), i, ehNegat = 0;
    double n = 0, a = 1;
    
    if(str[0] == '-') {
        ehNegat = 1;
    }

    int ctg = 0;

    if(ehNegat == 0) {
        for(i = 0; i < tam; i++) {
            if(str[i] != '.') {
                ctg++;
            } else {
                break;
            }
        }

        for(i = 1; i < ctg; i++) {
            a *= 10.0; 
        }

        for(i = 0; i < tam; i++) {
            if(str[i] == '.') {
                continue;
            }

            n += (str[i] - '0') * a;
            a /= 10.0;
        }

        printf("%.3lf %.3lf\n", n, n+n);

    } else {
        for(i = 0; i < tam; i++) {
            if(str[i] != '.') {
                ctg++;
            } else {
                break;
            }
        }

        for(i = 1; i < ctg; i++) {
            a *= 10.0; 
        }

        for(i = 1; i < tam; i++) {
            if(str[i] == '.') {
                continue;
            }

            n += (str[i] - '0') * a;
            a /= 10.0;
        }
        
        n /= 10;

        printf("-%.3lf -%.3lf\n", n, n+n);
    }


}

int main() {
    char str[N];
    while(scanf("%s", str) != EOF) {
        string2double(str);
    }

    return 0;
}