/* Pinta les caselles en que la fila i la columna son imparells o parells */
#include <stdio.h>

int main(void) {
    int i, j, num;

    printf("Dona'm un nombre enter positiu: \n");
    scanf("%d", &num);

    for(i = 0; i < num; i++) {
        for(j = 0; j < num; j++) {
            if((i + j)%2 == 0) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 1;
}