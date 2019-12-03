/* Donats tres punts a l'espai, retorna l'àrea i el perímetre del triangle creat per aquests tres punts */

#include <stdio.h>
#include <math.h>

double longitud(double[2], double[2]);

int main(void) {
    double x[2], y[2], z[2];
    double area, per, s;

    printf("Dona'm les coordenades del primer punt:\n");
    scanf("%lg %lg", &x[0], &x[1]);

    printf("Dona'm les coordenades del segon punt:\n");
    scanf("%lg %lg", &y[0], &y[1]);

    printf("Dona'm les coordenades del tercer punt: \n");
    scanf("%lg %lg", &z[0], &z[1]);

    printf("Long x -> y: %.2lg\n", longitud(x, y));
    printf("Long y -> z: %.2lg\n", longitud(y, z));
    printf("Long z -> x: %.2lg\n", longitud(z, x));

    per = longitud(x, y) + longitud(y, z) + longitud(z, x);

    s = per / 2.;
    area =  sqrt(s * (s-longitud(x,y)) * (s - longitud(y, z)) * (s - longitud(z, x)));   

    printf("L'àrea del triangle format pels punts és: %lg\n", area);
    printf("El perímetre del triangle format pels tres punts és %lg\n", per);

    return 0;
}

double longitud(double x[2], double y[2]) {
    double l = sqrt((y[0] - x[0]) * (y[0] - x[0]) + (y[1] - x[1]) * (y[1] - x[1]));
    return l;
}