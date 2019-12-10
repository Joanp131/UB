/* Funció que suprimeix les vocals d'una tira de caràcters */
#include <stdio.h>
#define DIM 100

int esDeLaTira(char);

int main(void) {
    char frase[DIM];
    int i;

    for(i = 0; i < DIM; i++) {
        scanf("%1c", &frase[i]);
        if(frase[i] == '\n')
            break;
    }

    for(i = 0; i < DIM; i++) {
        if(!esDeLaTira(frase[i])) {
            printf("%1c\n", frase[i]);
        }
        if(frase[i+1] == '\n')
            break;
    }

    for(i = 0; i < DIM; i++) {
        printf("%1c", frase[i]);
        if(frase[i] == '\n')
            break;
    }

    return 0;
}

int esDeLaTira(char a) {
    char chara[12] = ".:,;()[]-{} ";
    int i;

    for(i = 0; i < 12; i++) {
        if(a == chara[i])
            return 1;
    }

    return 0;
}