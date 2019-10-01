/* Té un dígit o no? */
#include <stdio.h>

int main(void) {
    int a;

    printf("Dona'm un nombre enter: \n");
    scanf("%d", &a);

    if(a < 10 && a > -10) {
        printf("El nombre %d conté 1 dígit\n", a);
    } else {
        printf("El nombre %d conté més d'un dígit\n", a);
    }

    return 0;
}