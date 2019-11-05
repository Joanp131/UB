/* Agafa dos nombes... llegeix l'enunciat, en serio, és un pal fer el resum */
#include <stdio.h>

int main(void) {
    int n[2], v[2][33], q, i, j;

    /* Demana dos nombres que no siguin iguals i que estiguin entre 2 i 1000 */
    do {
        printf("Dona'm dos n pertanyents a I:\n");
        scanf("%d %d", &n[0], &n[1]);
    } while (n[0] < 2 || n [0] > 1000 || n[1] < 2 || n [1] > 1000 || n[0] == n[1]);

    /* Inicialitza el vector sencer a zero */
    for(i = 0; i < 2; i++) {
        for(j = 0; j < 33; j++) {
            v[i][j] = 0;
        }
    }

    /* Escriu tots els múltiples dins el vector i el nombre de múltiples a la primera posició */
    for(i = 0; i < 2; i++) {
        q = 0;
        for(j = 1; j <= n[i]; j++){
            if(n[i] % j == 0) {
                v[i][++q] = j;
            }
        }
        v[i][0] = q;
    }

    /* Conta quants múltiples tenen en comú */
    q = 0;
    for(i = 1; v[0][i] != 0; i++) {
        for(j = 0; v[1][j] != 0; j++) {
            if(v[0][i] == v[1][j]) {
                q++;
            }
        }
    }

    /* Escriu els vectors */
    for (i = 0; i < 2; i++) {
        printf("vector %d:\n", i);
        for (j = 0; j < 33; j++) {
            printf("%d, ", v[i][j]);
        }
        printf("\b\b");
        printf("\n");
    }

    /* Diu si els vectors són parents o no */
    printf("Els dos nombres ");
    if(q < 4) {
        printf("no ");
    }
    printf("són parents.\n");

    return 420;
}