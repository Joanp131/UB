/* Calcular el nombre e notes per sota la nota mitjana */
#include <stdio.h>
#define DIM 500

int main(void) {
    int n, i, sum = 0;
    float mitj;

    do {
        printf("Dona'm la quantitat de notes:\n");
        scanf("%d", &n);
    } while(n < 1 || n > DIM);

    float notes[n];
    printf("Dona'm %d notes (0 - 10):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%f", &notes[i]);
        sum += notes[i];
    }

    mitj = (float) sum/n;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += notes[i] < mitj;
    }

    printf("La mitjana és %f, i %d notes estàn per sota la mitjana", mitj, sum);
    return 0;
}