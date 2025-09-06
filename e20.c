#include <stdio.h>
 
int main() {
 
    int n;
    scanf("%d", &n);
 
    int a = n + (n*32)+ (2*n*31);
 
    printf("%d\n", a);
 
    return 0;
}
