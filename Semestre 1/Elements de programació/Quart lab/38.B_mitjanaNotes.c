/* Calcular el nombre e notes per sota la nota mitjana */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n, i, sum = 0;
    float mitj;

    srand((unsigned) clock());

    printf("Dona'm la quantitat de notes:\n");
    scanf("%d", &n);

    float notes[n];
    for (i = 0; i < n; i++) {
        notes[i] = 10*((float) rand() / RAND_MAX);
        printf("%5.2f,", notes[i]);
        sum += notes[i];
    }
    printf("\n");

    mitj = (float) sum/n;

    sum = 0;
    for (i = 0; i < n; i++) {
        sum += notes[i] < mitj;
    }

    printf("La mitjana és %f, i %d notes estàn per sota la mitjana", mitj, sum);
    return 0;
}