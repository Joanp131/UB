/* Pinta les caselles en que la fila i la columna son imparells o parells */
#include <stdio.h>

int main(void) {
    int i, j, num;

    printf("Dona'm un nombre enter positiu: \n");
    scanf("%d", &num);

    while (num > 0) {

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
        printf("\n\n");

        printf("Dona'm un nombre enter positiu: \n");
        scanf("%d", &num);
    } 

    return 1.5;
}