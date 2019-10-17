/* Resol equacions del tipus ax² + bx + c = 0, tant si les solucions són reals com si són complexes */
#include <stdio.h>
#include <math.h>

int main(void) {
    int a, b, c;
    float x1, x2, c1;

    printf("Resoldré una equació de tipus ax² + bx + c = 0\n");
    printf("Dona'm a, b, c\n");
    scanf("%d %d %d", &a, &b, &c);

    if(b*b - 4*a*c >= 0) {
        x1 = (-b + sqrt(b*b - 4*a*c))/(2.*a);
        x2 = (-b - sqrt(b*b - 4*a*c))/(2.*a);
        printf("Les solucions a la equació %dx² + %dx + %d = 0 són:\n", a, b, c);
        printf("\tx1: %.2f\n", x1);
        printf("\tx2: %.2f\n", x2);
    } else {
        x1 = (-b)/(2.*a);
        c1 = (sqrt(-(b*b - 4*a*c)))/(2.*a);
        printf("Les solucions a la equació %dx² + %dx + %d = 0 són:\n", a, b, c);
        printf("\tx1: %.2f %+.2f *i\n", x1, c1);
        printf("\tx2: %.2f %+.2f *i\n", x1, -c1);
    }

    return 0;
}
