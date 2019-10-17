/* Donats dos nombres enters, diu si són amics o no */
#include <stdio.h>

int main(void) {

    long n[2], sum[] = {0, 0}, aux, i, j;

    printf("Dona'm el primer nombre enter: \n");
    scanf("%ld", &n[0]);

    printf("Dona'm el segon nombre enter: \n");
    scanf("%ld", &n[1]);

    if (n[0] < n[1]) {
        aux = n[1];
        n[1] = n[0];
        n[0] = aux;
    }

    for (i = 0; i < 2; i ++) {
        for (j = 0; j < n[i]; j++) {
            if(j != 0 && n[i] % j == 0) {
                sum[i] += j;
            }
        }
    }

    printf("Els nombres %ld i %ld", n[0], n[1]);
    if(!(sum[1] == n[0] && sum[0] == n[1])) {
        printf(" no");
    }
    printf(" són amics, ja que la suma dels múltiples de %ld dona %ld i la suma dels múltiples de %ld dona %ld\n", n[0], sum[0], n[1], sum[1]);

    return 1777;
}
