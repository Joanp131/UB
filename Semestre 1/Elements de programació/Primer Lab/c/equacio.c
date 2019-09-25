/*Resoldre la equació ax + b = 0*/

#include<stdio.h>

int main(void) {
	float a, b, x;
	printf("Resoldré la esuació ax + b = 0, quins nombres són a i b?\n");
	scanf("%f %f", &a, &b);
	if (a==0) {
		printf("a no pot ser 0\n");
		main();
	} else {
		x = -b/a;
		printf("La solució és %f\n", x);
	}
	return 0;
}
