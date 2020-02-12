/* Exercici 1 llista 1 */
#include <stdio.h>
#include <math.h>

double f(double x);

int main(void) {
    
    FILE* file = fopen("data.res", "w+");
    double a, b, h, i, area = 0;
    int n;

    printf("#Dona'm a i b de l'interval [a, b]\n");
    scanf("%le %le", &a, &b);

    printf("#Dona'm n\n");
    scanf("%d", &n);

    h = (double) (b - a) / n;
    printf("#h = %lg\n", h);

    fprintf(file, "%.8lf %.8lf\n", a, f(a));
    for(i = a+h; i < b; i += h) {
        area += 2*f(i);
        fprintf(file, "%.8lf %.8lf\n", i, f(i));
    }
    fprintf(file, "%.8lf %.8lf\n", b, f(b));

    area = (h/2) * (f(a) + area + f(b));

    printf("#L'àrea és: %.10le\n", area);
    fclose(file);

    return 0;
}

double f(double x) {
    double res = 0;

    /* f(x) = log(x)*log(1-x) */
    if(x == 0) return 0;
    if(x == 1) return 0;
    res = log(x)*log(1-x);

    /* f(x) = x³ + 2x² +1 
    res = x*x*x + 2*x*x + 1;
    */
    return res;
}