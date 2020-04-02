/* Tasca 3 - Joan Pau Condal Marco - 20334366 */
#include <stdio.h>
#include <math.h>

#define k 2
#define c 1
#define a 1

void calcRec(int n, double h0, double p0, double *hn, double *pn);
void calcIter(int n, double h0, double p0, double *hn, double *pn);

int main(void) {

    int n;
    
    double h0, p0, hn, pn;

    printf("Quin vols que sigui H0: ");
    scanf("%le", &h0);

    printf("Quin vols que sigui P0: ");
    scanf("%le", &p0);

    printf("Quin vols que sigui n final? -> ");
    scanf("%d", &n);

    calcRec(n, h0, p0, &hn, &pn);

    printf("\n Rec: Hn = %.4le, Pn = %.4le\n", hn, pn);

    calcIter(n, h0, p0, &hn, &pn);

    printf("Iter: Hn = %.4le, Pn = %.4le\n", hn, pn);

    return 0;
}

void calcRec(int n, double h0, double p0, double *hn, double *pn) {

    if(n == 0) return;

    *hn = k*h0*exp(-a*p0);
    *pn = c*h0*(1-exp(-a*p0));

    calcRec(n-1, *hn, *pn, hn, pn);

    return;
}

void calcIter(int n, double h0, double p0, double *hn, double *pn) {

    int i = 0;

    for(i = 0; i < n; i++) {
        *hn = k*h0*exp(-a*p0);
        *pn = c*h0*(1-exp(-a*p0));

        p0 = *pn;
        h0 = *hn;
    }

    return;
}