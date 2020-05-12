/* Eloi Baeta Trias. NIUB: 20334462 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
	int fil;
	int col;
	double val;
}ele;
int main (void){
	int i, j, k, iter=0, iterMax=50, n, qu;
	ele *A;
	double *b, *x, *y, d, prec=1e-6, error;
	FILE *fdad;
	char nom[31];
	printf("Escriu el nom del fitxer de dades (màx 31 caràcterss)\n");
	scanf("%s",nom);	
	fdad=fopen(nom,"r");
	if(fdad==NULL){
		printf("Problemes a l'obrir el fitxer de dades\n");
		exit (1);
	}
	fscanf(fdad," %d %d", &n, &qu);
	A=(ele *)malloc(qu*sizeof(ele));
	if(A==NULL){
		printf("Error de memòria en A\n");
		exit (2);
	}
	b=(double *)malloc(n*sizeof(double));
	if(b==NULL){
		printf("Error de memòria en b\n");
		exit (3);
	}
	x=(double *)malloc(n*sizeof(double));
	if(x==NULL){
		printf("Error de memòria en x\n");
		exit (4);
	}
	y=(double *)malloc(n*sizeof(double));
        if(x==NULL){
                printf("Error de memòria en y\n");
                exit (5);
        }
	for(i=0;i<qu;i++){
		fscanf(fdad," %d %d %lf",&A[i].fil, &A[i].col, &A[i].val);
		
	}
	printf("Escriu el vector inicial x0\n");
	for(i=0;i<n;i++){
		fscanf(fdad,"%lf",&b[i]);
		scanf("%lf", &x[i]);
		

	}
	do{
		error=0;
		for(k=0;k<n;k++){
			y[k]=b[k];
			for(j=0;j<n;j++){
				if(j!=k){
					for(i=0;i<qu;i++){
						if(A[i].fil==k&&A[i].col==j){
							d=A[i].val;
						}
					}
					y[k]-=x[j]*d;
				}
			}
			for(i=0;i<qu;i++){
				if(A[i].fil==k&&A[i].col==k){	
					d=A[i].val;
				}	
			}
			y[k]/=d;
		}		
		for(k=0;k<n;k++){
			error+=(y[k]-x[k])*(y[k]-x[k]);
		}
		error=sqrt(error);
		iter++;
	}while(iter<iterMax&&error>prec);
	if(iter==iterMax){
		printf("x = (");
		for(i=0;i<n-1;i++){
			printf("%.2lf,",y[i]);
		}
		printf("%.2lf)\n",y[n-1]);
	}else{
		printf("No ha convergit en 50 iteracions\n");
	}
	fclose(fdad);
	free(b);
	free(x);
	free(y);
	free(A);
	
	return 0;
}	
		
















