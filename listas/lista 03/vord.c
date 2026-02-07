#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct Vetor{
    double u;
    double x;
    double y;
    double z;
    double norma;
};

int main() {
    int n,i, j;
    scanf("%d", &n);

    struct Vetor *v;
    v = (struct Vetor*)malloc(n*sizeof(struct Vetor));


    for(i=0;i<n;i++){
        scanf("%lf %lf %lf %lf", &(v[i].u), &(v[i].x), &(v[i].y), &(v[i].z));
    }

    for(i=0;i<n;i++){
        v[i].norma = sqrt((v[i].u * v[i].u) + (v[i].x * v[i].x) + (v[i].y * v[i].y) + (v[i].z * v[i].z));
    }


    struct Vetor temp;
    for(i=0;i<n;i++){
        for(j=0;j<n-1-i;j++){
            if(v[j].norma > v[j+1].norma) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }

    for(i=0;i<n;i++){
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", v[i].u, v[i].x, v[i].y, v[i].z, v[i].norma);
    }

    free(v);

    return 0;
}