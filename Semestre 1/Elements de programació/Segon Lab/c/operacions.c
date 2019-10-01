/* Opercions amb enters i floats */
#include <stdio.h>

int main(void) {
    int a, b, c;
    float x, z;

    a = 5/3 + 2;
    b = 2*5/3;
    c = 2/3*5;
    printf("a=%d b=%d c=%d\n", a, b, c);

    z = 10e3;
    x = 1000*(1/3.f + 1/3.f + 1/3.f - 1);
    printf("z=%f x=%f\n", z, x);

    b = b+1/b;
    x = 1/x;
    a = x;
    z = 1./a;
    printf("b=%d x=%f a=%d z=%f\n", b, x, a, z);

    a = 32%b;
    b = 235%10;
    c = 235/10;
    printf("a=%d b=%d c=%d\n", a, b, c);

    return 0;
}