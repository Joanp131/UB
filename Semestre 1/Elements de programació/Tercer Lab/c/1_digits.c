/* Llegiu un nombre enter no nul i compteu el nombre de dígits que te */
#include <stdio.h>

int main(void){
    int num;
    do {
        printf("Dona'm un nombre no nul:\n");
        scanf("%d", &num);
    } while (num == 0);
    
}