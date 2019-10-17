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
    long x1 = 0, i, j;
    long n[2];

    printf("Dona'm el primer nombre\n");
    scanf("%ld", &n[0]);

    printf("Dona'm el segon nombre\n");
    scanf("%ld", &n[1]);

    if (count(n[0]) != count(n[1])) {
        printf("Els nombres han de tenir el mateix nombre de xifres\n");
    } else {
        x1 = count(n[0]);
        long nums[2][x1];

        for (i = 0; i < 2; i++) {
            for (j = 0; j < x1; j++) {
                nums[i][j] = n[i] % 10;
                n[i] /= 10;
            }
        }

        for (j = 0; j < x1; j++) {
            if (nums[0][j] == nums[1][j]) {
                printf("A la posició %2ld es repeteix la xifra %ld\n", j+1, nums[0][j]);
            }
        }
    }

    return 0;
}