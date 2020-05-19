/* Joan Pau Condal Marco - 20334366 Tasca 8 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* n (long del vector) mínima i màxima */
#define MIN 1000000
#define MAX 10000000

int ordre(const void *, const void*);

int main(void) {

    int i, j, n = MIN, times, *nums;
    double dur, r = 0, mitj = 0;
    clock_t inici, final;

    srand((unsigned) time(NULL));

    printf("Quantes ordenacions vols fer?\n");
    scanf("%d", &times);

    nums = (int *) malloc(n * sizeof(int));
    if(nums == NULL) {
        printf("Error al crear el vector\n");
        exit(1);
    }

    for(i = 0; i < times; i++) {
        printf("(%d / %d)\n", i+1, times);

        if(i != 0) {
            n = rand() % (MAX+1 - MIN) + MIN;
            nums = (int *) realloc(nums, n * sizeof(int));
            if(nums == NULL) {
                printf("Error al crear el vector\n");
                exit(1);
            }
        }
        printf("n: %d\n", n);

        for(j = 0; j < n; j++) {
            nums[j] = rand()*2 - RAND_MAX;
        }

        inici = clock();
        qsort(nums, n, sizeof(int), ordre);
        final = clock();

        dur = (double)(final - inici) / CLOCKS_PER_SEC;

        printf("Time = %.5lg\n", dur);

        r = log(dur)/log(n);

        printf("r = %.4lg\n\n", r);

        mitj += r/times;

    }
    printf("Mitjana de les r = %.3lfn\n", mitj);

    free(nums);

    return 0;
}

int ordre(const void* a, const void* b) {

    int aVal = *(int *)a, bVal = *(int *)b;

    if(aVal % 2 == bVal % 2) {
        if(aVal % 2 == 0) {
            return aVal - bVal;
        } else {
            return bVal - aVal;
        }

    }
    
    return (aVal%2 == 0 ? 1 : -1);
}
