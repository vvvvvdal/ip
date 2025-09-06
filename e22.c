#include <stdio.h>
#include <math.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
    int h, c1;   // h²=c1²+c2² // c2 = sqrt(h²-c1²)
    float c2;
    
    for(h = 1; h <= n; h++) {
        for(c1 = 1; c1 < h; c1++) {
            c2 = sqrt((h*h)-(c1*c1));
        
            if(c2 == (int)c2) {
                c2 = (int)c2;
 
                if(c1 <= c2) {
                    printf("hipotenusa = %d, catetos %d e %.0f\n", h, c1, c2);
                }
            }
 
        }
 
    }
 
    return 0;
}
