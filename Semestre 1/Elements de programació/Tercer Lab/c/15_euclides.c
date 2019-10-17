/* Mesura el MCD de dos nombres amb l'algoritme d'Euclides */
#include <stdio.h>

int main(void) {
    int a, b, res = 1;

    printf("Dona'm els dos nombres dels quals vols trobar el MCD: \n");
    scanf("%d %d", &a, &b);

    if (a < b) {
        res = a;
        a = b;
        b = res;
    }

    do {
        while (a >= b && res  > 0) {
            res = a - b;
            a = res;
            /* printf("While 2, a = %3d, b = %3d, res = %3d\n", a, b, res); */
        }
        if (res > 0) {
            a = b;
            b = res;
        } else {
            break;
        }
    } while (res != 0);

    printf("El MCD és: %d\n", b);

    return 0;
}
