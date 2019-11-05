/* Càlcul de l'Àrea i el Volum d'una esfera respecte el seu radi */
/* A = 4 * pi * r² */
/* V = 4/3 * pi * r³ */
#include <stdio.h>

int main(void) {
    double PI = 3.14159265358979323846;
    float a, v, r;

    printf("Quin és el radi de la teva esfera?\n");
    scanf("%f", &r);

    if(r > 0) {
        v = 4/3.f * PI * r * r * r;
        a = 4 * PI * r * r;

        printf("El volum de l'esfera és %f i l'àrea és %f\n", v, a);
    } else {
        printf("El radi no pot ser negatiu o 0\n");
        main();
    }
    return 0;
}