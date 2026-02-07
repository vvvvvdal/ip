#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * vect_new(int n) {
    return (int*)malloc(n*sizeof(int));
}

void vect_rand_init(int *A, int n, int min, int max) {
    srand(time(0));
    int i;
    for(i = 0; i < n; i++) {
        A[i] = rand()%((max-min+1)+min);
    }
}

void vect_print(int *A, int n, char * pos) {
    int i;
    printf("[");
    for(i = 0; i < n; i++) {
        if(i == 0) printf("%d", A[i]);
        printf(", %d", A[i]);
    }
    printf("]");

    if(pos != NULL) printf("%s", pos);
}

void vect_free(int *A) {
    free(A);
}

int main (int argc, char **argv) {
    int *A, n, *B;
    scanf("%d", &n);
    
    A = vect_new(n);
    B = vect_new(2*n);

    vect_rand_init(A, n, 0, 10);
    vect_rand_init(B, 2*n, 10, 20);

    vect_print(A,n, ",");
    vect_print(B,2*n, "\n");

    vect_free(A);
    vect_free(B);

    return 0;
}