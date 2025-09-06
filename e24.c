#include <stdio.h>
 
int main() {
 
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    int mmc = 1;
    int div = 2;
 
    while(a != 1 || b != 1 || c != 1) {
        if(a%div == 0 || b%div == 0 || c%div == 0) {
            printf("%d %d %d :%d\n", a, b, c, div);
            
            mmc *= div;
 
            if(a%div == 0) a /= div;
            if(b%div == 0) b /= div;
            if(c%div == 0) c /= div;
 
        } else {
            div++;
        }
    }
 
    printf("MMC: %d\n", mmc);
 
    return 0;
}
