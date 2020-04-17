/* Comprova la posició relativa de dues circumferències */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct circ {
    float radi;
    float x[2];
};

int main(void) {

    struct circ c1, c2;
    float dist;

    /* Dades de c1 */
    printf("Dona'm les coordenades del centre de la primera circumferència:\n");
    scanf("%f %f", &c1.x[0], &c1.x[1]);

    printf("Dona'm el radi de la circumferència 1:\n");
    scanf("%f", &c1.radi);
    while(c1.radi <= 0) {
        printf("El radi no pot ser nul ni negatiu. Dona'm un radi bo\n");
        scanf("%f", &c1.radi);
    }


    /* Dades de c2 */
    printf("Dona'm les coordenades del centre de la segona circumferència:\n");
    scanf("%f %f", &c2.x[0], &c2.x[1]);

    printf("Dona'm el radi de la circumferència 1:\n");
    scanf("%f", &c2.radi);
    while(c2.radi <= 0) {
        printf("El radi no pot ser nul ni negatiu. Dona'm un radi bo\n");
        scanf("%f", &c2.radi);
    }

    /* Calculem la distància entre els dos centres de la circumferència */
    dist = sqrt((c2.x[0]-c1.x[0])*(c2.x[0]-c1.x[0]) + (c2.x[1]-c1.x[1])*(c2.x[1]-c1.x[1]));
    printf("La distància entre les dues circumferències és %f\n", dist);

    /* Mirem la posició relativa de les dues circumferències */
    if(dist > c1.radi+c2.radi) {
        printf("Exteriors\n");
    } else if (dist == c1.radi+c2.radi) {
        printf("Tangents exteriors\n");
    }

    return 0;
}