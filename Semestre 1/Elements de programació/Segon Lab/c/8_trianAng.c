/* Donats tres nombres reals, vegeu si poden formar triangle i de quin tipus és */
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int main(void) {
    float a, b, c, A, B, C, eps = .001;

    printf("Dona'm la longitud dels tres costats del triangle: \n");
    scanf("%f %f %f", &a, &b, &c);

    A = acos((a*a - c*c - b*b)/-2.*b*c);
    B = acos((b*b - a*a - c*c)/-2.*a*c);
    C = acos((c*c - a*a - b*b)/-2.*a*b);

    if(fabs(a + b + c) - PI < eps) {
        
    }

}