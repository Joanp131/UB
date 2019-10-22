/* Hi ha una fitxa de domino sobre la taula i el jugador en te 5, pot tirar com a minim dues vegades? */
#include <stdio.h>

int main(void) {
    int f, fs[5], sum = 0, i;

    printf("Dona'm les fitxes que hi ha sobre la taula\n");
    scanf("%d", &f);

    printf("Dona'm les fitxes del jugador\n");
    for(i = 0; i < 5; i++) {
        scanf("%d", &fs[i]);
        if(fs[i]/10 == f/10 || fs[i]/10 == f%10 || fs[i]%10 == f/10 || fs[i]%10 == f%10) {
            sum++;
        }
    }

    if(sum >= 2) {
        printf("El jugador  pot tirar dos fitxes o més\n");
    } else {
        printf("El jugador no pot tirar dues fitxes\n");
    }

    return sum;
}