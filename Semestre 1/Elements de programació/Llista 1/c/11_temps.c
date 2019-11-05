/* Donat un temps en h m s, sumar-li un segon i retornar el resultat */
#include <stdio.h>

int main(void) {
    
    int h, m, s;

    printf("Dona'm un temps en forma de Hores, Minuts i Segons:\n");
    scanf("%d %d %d", &h, &m, &s);

    s++;
    m += (s/60);
    h += (m/60);
    m -= 60*(m/60);
    s -= 60*(s/60);

    printf("La teva hora amb un segon més és: %2d:%2d:%2d\n", h, m, s);
    
    return 0;
}