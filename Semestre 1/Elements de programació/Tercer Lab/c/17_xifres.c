/* Indica si dos nombres enters positius tenen xifres iguals i a quina posició */
#include <stdio.h>

long count(long n) {
    long x = 0;
    do {
        n = n/10;
        x++;
    } while (n > 0);

    return x;
}

int main(void) {
    long n1, n2, x1 = 0, i, j;

    printf("Dona'm el primer nombre\n");
    scanf("%ld", &n1);

    printf("Dona'm el segon nombre\n");
    scanf("%ld", &n2);

    if (count(n1) != count(n2)) {
        printf("Els nombres han de tenir el mateix nombre de xifres\n");
        main();
    }

    x1 = count(n1);

    long nums[2][x1];

    for (i = 0; i < 2; i++) {
        for (j = 0; j < x1; j++) {
            nums[i][j] =
        }
    }

    printf("%ld té %ld xifres, %ld té %ld xifres\n",n1, x1, n2, x2);

    return 0;
}