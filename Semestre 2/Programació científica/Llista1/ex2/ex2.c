/* Exercici 2 Llista 1 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int a, b, m, dies[365], sum = 0, i, j, k, aux;
    double prob;

    srand( (unsigned) time(NULL));

    do{
        printf("De quan a quan la població?\n");
        scanf("%d %d", &a, &b);
    } while (a > b);

    printf("Quantes vegades vols fer-ho (M)?\n");
    scanf("%d", &m);

    for(k = a; k < b; k++) {
        for (i = 0; i < m; i++) {

            aux = 0;

            for(j = 0; j < 365; j++) {
                dies[j] = 0;
            }

            for(j = 0; j < k; j++) {
                dies[rand() % 365]++;
            }

            for(j = 0; j < 365; j++) {
                if(dies[j] > 1) aux++;
            }

            if(aux) sum++;

        }
    
        prob = (double) sum / m; 
        
        printf("%d, %.6lg\n", k, prob);
    }

    
    printf("La probabilitat és: %lg\n", prob);

    return 0;
}