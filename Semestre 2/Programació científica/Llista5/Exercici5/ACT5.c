/*Udane Viñas Templado. NIUB:20294665*/
/*LLISTA5, ACT5*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
	int fil;
	int col;
	double val;
} ele;

int main (void) {
	int i, j, k, n, qu, iter;
	double r=10, t, aux;
	char fitxer[30];
	FILE *obrir;
	double *x, *y, *b;
	ele *A;

	/*Demanem el nom del fitxer on tenim guardades les dades i les guardem*/
	/*A més, també  reservem memòria dinamica per tots els vectors que necesitem*/

		printf("Diga'm el nom del fitxer on tens les dades:\n");
		scanf("%s", fitxer);

		printf ("Diga'm el numero de iteracions qu voldràs fer\n");
		scanf("%d", &iter);

		obrir = fopen (fitxer, "r");

		fscanf(obrir, "%d", &n);
		fscanf(obrir, "%d", &qu);

		A = (ele*) malloc (qu * sizeof (ele));	
		if (A == NULL) {
			printf("Error en reservar memòria\n");
			exit (1);
		}
	
		x = (double*) malloc (n *sizeof (double));
		if (x == NULL) {
			printf ("Error en reservar memòria\n");
			exit(1);
		}

		y = (double*) malloc (n*sizeof (double));
		if (y == NULL) {
			printf("Error en reservar memòria\n");
			exit(1);
		}

		b = (double*) malloc (n*sizeof (double));
		if (b == NULL) {
			printf ("Error en reservar memòria\n");
			exit (1);
		}


		for (i=0; i<qu; i++) {
			fscanf(obrir, "%d %d %le", &A[i].fil, &A[i].col, &A[i].val);
		}

		for (i=0; i<n; i++) {
			fscanf(obrir, "%le", &b[i]);
		}


		fclose (obrir);

		for (i=0; i<n; i++) {
			x[i] = 0.;
		}

	/*Ara com ja tenim totes les dades farem els càlculs necesaris*/
		while (r > (pow(10,-6))) {

			r = 0;
			for (k=0; k<n; k++) {
				t = 0;

				for (j=0; j<qu; j++) {
					if (A[j].fil != k) {
						continue;
					}
					
					if (A[j].col == k) {
						aux = A[j].val;
						continue;
					}

					t += A[j].val * x[A[j].col];
				}

				y[k]= (1./aux) * (b[k] - t);
			}

			for (i=0; i<n; i++) {
				r += ((y[i] - x[i]) * (y[i] - x[i]));
			}

			r = sqrt (r);
			iter--;

			if (iter == 0) {
				printf ("No hi ha hagut convergència\n");
				exit (1);
			}

			for (i=0; i<n; i++) {
				x[i] = y[i];
			}
		}

	/*Imprimirem en plantalla el vector que voliem trobar i el nombre d'iteracions que hem fet fins que a convergit*/

		printf ("solució x = (");

		for (i=0; i<n; i++) {
			printf ("%le, ", x[i]);
		}

		printf (")\n");
		
		iter = 50 - iter;

		printf ("Iteració final = %d", iter);
	
		free (A);
		free (y);
		free (x);
		free (b);

return 0;
}
