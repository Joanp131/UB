/* Programa que llegeix nombres i diu si són multiples de tres parells */
#include <stdio.h>
#define N 10000

int main(void) {

    long nums[N], i = 0;
    
    printf("Dona'm nombres enters positius o -1 per parar:\n");
    do {
        scanf("%ld", &nums[i]);
        i++;
    } while (nums[i] != -1);

    printf("De tots els nombres que m'has donat, els següents són multiples de 3 i parells:\n");
    for (i = 0; i < N; i++) {
        if(nums[i] % 6 == 0) {
            printf("%ld, ", nums[i]);
        } else if(nums[i] == -1) {
            break;
        }
    }
    printf("\n");

    return 0;
}
