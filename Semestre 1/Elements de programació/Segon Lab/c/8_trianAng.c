/* Donats tres nombres reals, vegeu si poden formar triangle i de quin tipus és */
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(void) {
    double a, b, c, A, B, C, eps = .00001;

    printf("Dona'm la longitud dels tres costats del triangle: \n");
    scanf("%lf %lf %lf", &a, &b, &c);

    A = acos((a*a - c*c - b*b)/(-2.*b*c));
    B = acos((b*b - a*a - c*c)/(-2.*a*c));
    C = acos((c*c - a*a - b*b)/(-2.*a*b));

    printf("A: %lf, B: %lf, C: %lf\n", A, B, C);
    if(fabs((A + B + C) - PI) < eps) {
        if (fabs(A - PI/2.) < eps || fabs(B - PI/2.) < eps || fabs(C - PI/2.) < eps) {
            printf("El triangle és rectangle\n");
        } else if (A > PI/2 || B > PI/2 || C > PI/2) {
            printf("El triangle és obtusangle\n");
        } else if (A < PI/2 || B < PI/2 || C < PI/2) {
            printf("El triangle és acutangle\n");
        } else {
            printf("Man, I messed up!\n");
        }
    } else {
        printf("Amb els nombres donats no es pot fer triangle!\n");
    }


    return 7;
}
