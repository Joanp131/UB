/* Edat.c */

#include<stdio.h>

int main(void) {
	int edat, any;
	printf("Quina és la teva edat?\n");
	scanf("%d", &edat);
	any = 2019 - edat;
	printf("Vas néixer l'any %d\n", any);
	any = 2019 + edat;
	printf("L'any %d tindràs el doble de la teva edat\n", any);
		
	return 0;
}
