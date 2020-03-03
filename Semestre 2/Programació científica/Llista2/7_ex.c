/* g composicio de f n vegades */
#include <stdio.h>

double f1(double);
double f2(double);
double df( double (*f)(double), double, double, int);
double g( double (*f)(double), double, int);

int main(void) {
    int n;
    double pasx, i, h;

    printf("#Quantes vegades vols fer f(x)?\n");
    scanf("%d", &n);

    printf("#Quin vols que sigui el pas?\n");
    scanf("%le", &pasx);

    printf("#quin vols que sigui h?\n");
    scanf("%le", &h);

    for(i = 0; i <= 1; i += pasx) {
        printf("%le %le %le %le %le\n", i, g(f1, i, n), df(f1, i, h, n), g(f2, i, n), df(f2, i, h, n));
    }
    return 0;
}

double f1(double x) {
    double y;

    y = 3.99*x*(1-x);

    return y;
}

double f2(double x) {
    double y;

    y = x*(6.3+x*(-16+10.7*x));

    return y;
}

double df( double (*f)(double), double x, double h, int n) {
    double y;

    y = g(f, x+h, n) - g(f, x-h, n);

    y /= 2*h;

    return y;
}

double g(double (*f)(double), double x, int n) {
    int i;
    double x0;
    for(i = 0; i < n; i++) {
        x0 = f(x);
        x = x0;
    }

    return x0;
}