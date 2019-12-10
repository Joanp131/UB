/* Funció que suprimeix les vocals d'una tira de caràcters */
#include <stdio.h>
#define DIM 100

int esVocal(char);

int main(void) {
    char frase[DIM];
    int i, j;

    for(i = 0; i < DIM; i++) {
        scanf("%1c", &frase[i]);
        if(frase[i] == '\n')
            break;
    }

    for(i = 0; i < DIM; i++) {
        if(esVocal(frase[i])) {
            for(j = i; j < DIM; j++) {
                frase[j] = frase[j+1];
                if(frase[j+1] == '\n')
                    break;
            }
            i--;
        }

    }

    for(i = 0; i < DIM; i++) {
        printf("%1c", frase[i]);
        if(frase[i] == '\n')
            break;
    }

    return 0;
}

int esVocal(char a) {
    char vocal[11] = "aeiouAEIOU";
    int i;

    for(i = 0; i < 11; i++) {
        if(a == vocal[i])
            return 1;
    }

    return 0;
}