/* Llegiu un nombre enter no nul i compteu el nombre de dígits que te */
#include <stdio.h>

int main(void){
    int num, i=0, p=0;
    do {
        printf("Dona'm un nombre no nul:\n");
        scanf("%d", &num);
    } while (num == 0);

    while (num > 0) {
        if((num%10)%2==0) {
            p++;
        }

        num = num/10;
        i++;
    }

    return 0;
}
