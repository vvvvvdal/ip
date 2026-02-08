#include <stdio.h>
#include <math.h>

int classifica_iris(double pt, double pl, double sp, double sl, double *d1, double *d2, double *d3);

int main() {
    double pt, pl, st, sl;

    while(scanf("%lf %lf %lf %lf", &pt, &pl, &st, &sl) == 4) {
        double d1, d2, d3;
        int n;
        
        n = classifica_iris(pt, pl, st, sl, &d1, &d2, &d3);

        if(n == 1) {
            printf("setosa\n");
        } else if (n == 2) {
            printf("virginica\n");
        } else if (n == 3) {
            printf("versicolor\n");
        }
    }

    return 0;
}

int classifica_iris(double pt, double pl, double st, double sl, double *d1, double *d2, double *d3) {
    int n = 1, dist;
    *d1 = sqrt(((6.85 - pt)*(6.85 - pt)) + ((3.07 - pl)*(3.07 - pl)) + ((5.74-st)*(5.74-st)) + ((2.07-sl)*(2.07-sl)));
    *d2 = sqrt(((5.00 - pt)*(5.00 - pt)) + ((3.41 - pl)*(3.41 - pl)) + ((1.46-st)*(1.46-st)) + ((0.24-sl)*(0.24-sl)));
    *d3 = sqrt(((5.90 - pt)*(5.90 - pt)) + ((2.74 - pl)*(2.74 - pl)) + ((4.39-st)*(4.39-st)) + ((1.43-sl)*(1.43-sl)));

    dist = *d1;
    printf("(%.2lf %.2lf %.2lf) ", *d1, *d2, *d3);
    
    if(dist > *d2) {
        dist = *d2;
        n = 2;
    }
    
    if(dist > *d3) {
        dist = *d3;
        n = 3;
    }

    return n;
}