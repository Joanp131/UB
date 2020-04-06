/* Joan Pau Condal Marco - 20334366 */
#include <stdio.h>
#include <stdlib.h>

double residu(int n, double **M, double *b, double x0);

int main(void) {

    int n, i, j, c, d, m;
    double *b, **M, h, x0;
    FILE *fp;
    char nom[31];

    printf("Nom del fitxer d'entrada (max 30 car.)?\n");
    scanf("%s", nom);

    /* Obrim el fitxer de dades */
    fp = fopen(nom, "r");
    if(fp == NULL) {
        printf("Error a l'obrir el fitxer\n");
        exit(1);
    }

    /* Llegim la dimensió i comprovem que és correcta */
    fscanf(fp, "%d", &n);
    if(n < 3) {
        printf("Valor incorrecte de n!\n");
        exit(1);
    }

    /* Reservem memòria pel vector b */
    b = (double *)malloc (n * sizeof(double));
    if(b == NULL) {
        printf("Error al reservar memòria per b\n");
        exit(1);
    }

    /* Reservem memòria per la matriu, només pels llocs necessaris */
    M = (double **)malloc (n * sizeof(double *));
    if(M == NULL) {
        printf("Error en la memòria de M\n");
        exit(1);
    }
    for(i = 0; i < n; i++) {
        M[i] = (double *)malloc ((i+2) * sizeof(double));
        if(M[i] == NULL) {
            printf("Error en la memòria de M[%d]", i);
            exit(1);
        }
    }

    /* Llegim les dades, comprovem que no són zero i omplim la matriu */
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i+1 && j < n; j++) {
            fsf(fp, "%le", &M[i][j]);
            if(M[i][j] == 0) {
                printf("Les dades de la matriu no pooden ser 0\n");
                exit(1);
            }
        }
    }

    /* Llegim les dades del vector */
    for(i = 0; i < n; i++) {
        fscanf(fp, "%le", &b[i]);
    }

    /* Llegim l'interval [c, d] i m */
    fsacnf(fp, "%d", &c);
    fscanf(fp, "%d", &d);
    fscanf(fp, "%d", &m);
    h = (double) (d-c)/m;
    
    /* Tanquem el fitxer que ja no el necessitem */
    fclose(fp);

    /* Demanem nom i obrim el fitxer de sortida */
    printf("Nom del fitxer de sortida? (max 30 char)\n");
    scanf("%s", nom);

    fp = fopen(nom, "w");
    if(fp == NULL) {
        printf("Error al obrir el fitxer de sortida\n");
        exit(1);
    }

    /* Calculem f(x0) per cada x0 en l'intèrval [c, d] i ho escrivim al fitxer*/
    for(i = 0, i <= m; i++) {
        x0 = c + i*h;
        fprintf(fp, "%le %le\n", x0, residu(n, M, b, x0));
    }

    /* Alliberem memòria */
    fclose(fp);
    for(i = 0; i < n; i++) {
        free(M[i]);
    }
    free(M);
    free(b);

    return 0;
}

double residu(int n, double **M, double *b, double x0) {
    int i, j;
    double *x, y;

    /* Reservem espai pel vector de solucions */
    x = (double *)malloc (n * sizeof(double));
    if(x == NULL) {
        printf("Error en la memòria del vector solució\n");
        exit(1);
    }

    /* Omplim el vector de solucions en funció de x0 */
    x[0] = x0;
    for(i = 0; i < n-1; i++) {
        x[i+1] = b[i]/M[i][i+1];
        for(j = 0; j <= i; j++) {
            x[i+1] -= (M[i][j]*x[j])/M[i][i+1];
        }
    }

    /* Calculem f(x0) */
    y = b[n-1];
    for(i = 0; i < n; i++) {
        y -= M[n-1][i]*x[i];
    }

    /* Alliberem memòria */
    free(x);

    /* Retornem f(x0) */
    return y;
}