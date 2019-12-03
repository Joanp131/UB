/* Diu quantes vegades un nombre és divisible entre un altre */

#include <stdio.h>

int multi(int, int);

int main(void) {

    int n, p;

    do {
        printf("Quin vols que sigui n?\n");
        scanf("%d", &n);

        printf("Quin vols que sigui p?\n");
        scanf("%d", &p);

    } while (n <= 0 && p <= 1);

    printf("El nombre %d és divisible %d vegades entre %d\n", n, multi(n, p), p);

    return 0;
}

int multi(int n, int p) {
    int count = 0;
    
    while (n % p == 0) {
        n /= p;
        count ++;
    }

    return count;
}