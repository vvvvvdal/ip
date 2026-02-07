#include <stdio.h>

typedef struct casa {
    int np;
    int consumo;
    int cmedio;
} Casa;

void ordena( Casa vc[], int n ) {
    int i, j, im;
    Casa tmp;
    for(i=0;i<n-1;i++) {
        im = i;
        for(j=i+1;j<n;j++) {
            if( vc[j].cmedio < vc[im].cmedio ) {
                im = j;
            }
        }
        tmp = vc[i];
        vc[i] = vc[im];
        vc[im] = tmp;
    }
}

void casa_print(Casa vc[], int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d-%d, ", vc[i].np, vc[i].cmedio);
    }
    printf("\n");
}

void agrega(Casa vc[], int n) {
    int cref = -1;
    int sp = 0;
    int i = 0;
    int ct = 0;
    int npt = 0;
    
    while(i<n) {
        if(vc[i].cmedio != cref) {
            if(i>0) printf("%d-%d ", sp, cref);
            sp = vc[i].np;
            cref = vc[i].cmedio;
        } else {
            sp += vc[i].np;
        }
        ct += vc[i].consumo;
        npt += vc[i].np;
        i++;
    }
    printf("%d-%d ", sp, cref);
    printf("\nConsumo medio: %.2lf m3.\n", (double)ct/npt);

}


int main() {
    Casa vcasa[100];
    int n, i, cc = 0;

    while(1) {
        scanf("%d", &n);
        if(n==0) break;

        // leitura das casas
        for(i=0;i<n;i++) {
            scanf("%d %d", &(vcasa[i].np), &(vcasa[i].consumo) );
            vcasa[i].cmedio = vcasa[i].consumo / vcasa[i].np;
        }

        // casa_print(vcasa, n);
        ordena(vcasa,n);
        // casa_print(vcasa, n);

        if(cc>0) printf("\n");
        printf("Cidade# %d:\n", cc+1);
        agrega(vcasa, n);
        cc++;
    }

    return 0;
}