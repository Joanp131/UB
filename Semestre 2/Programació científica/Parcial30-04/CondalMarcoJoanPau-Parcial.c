/* Joan Pau Condal Marco - 20334366 */
#include <stdio.h>
#include <stdlib.h>

float* derivacio(int m, float* p);

float* producte(int m, float* p, int n, float* q);

float* suma(int m, float* p, float* q);

int main(void) {

    int i;
    int m, n; /* m = dim p, n = dim q */
    float *q, *p, *dp, *dq, *pq, *dpq, *pdq, *pqd, *res;
    FILE *fp, *fq, *out;

    /* Obrim els fitxers i llegim les dades */
    fp = fopen("p.dad", "r");
    if(fp == NULL) {
        printf("Problemes obrint el fitxer p.dad\n");
        exit(1);
    }

    fq = fopen("q.dad", "r");
    if(fq == NULL) {
        printf("Problemes llegint el fitxer q.dad\n");
        exit(1);
    }

    fscanf(fp, "%d", &m);
    fscanf(fq, "%d", &n);
    
    /* Creem els vectors dels polinomis */
    p = (float *) malloc((m+1) * sizeof(float));
    if(p == NULL) {
        printf("Problemes al crear el vector p\n");
    }
    q = (float *) malloc((n+1) * sizeof(float));
    if(q == NULL) {
        printf("Problemes al crear el vector q\n");
        exit(1);
    }

    /* Omplim els vectors amb les dades */
    for(i = 0; i <= m; i++) {
        fscanf(fp, "%f", &p[i]);
    }

    for(i = 0; i <= n; i++) {
        fscanf(fq, "%f", &q[i]);
    }

    /* Fem els càlculs necessaris */
    pq = producte(m, p, n, q);
    pqd = derivacio((n+m), pq);

    dp = derivacio(m, p);
    dq = derivacio(n,q);

    pdq = producte(m, p, (n-1), dq);
    dpq = producte((m-1), dp, n, q);

    res = suma((n+m-1), pdq, dpq);

    /* Guardem el resultat al fitxer de sortida */
    out = fopen("pqder.res", "w");
    if(out == NULL) {
        printf("Error a l'obrir el fitxer de sortida\n");
        exit(1);
    }

    /* Escrivim el resultat al fitxer */
    fprintf(out, "   coef. (pq)'    coef. qp'+pq'   coef. difer.\n");
    for(i = 0; i < n+m; i++) {
        fprintf(out, "%+.8e %+.8e %+.8e\n", pqd[i], res[i], pqd[i]-res[i]);
    }

    /* Alliberem memòria */
    free(p);
    free(q);
    free(dp);
    free(dq);
    free(pq);
    free(pqd);
    free(pdq);
    free(dpq);
    free(res);

    fclose(fp);
    fclose(fq);
    fclose(out);

    return 0;
}

float* derivacio(int m, float* p) {

    int i;
    float* dp;

    dp = (float *) malloc(m * sizeof(float));
    if(dp == NULL) {
        printf("Error al crear el polinomi dp\n");
        exit(1);
    }

    for(i = 0; i < m; i++) {
        dp[i] = p[i+1]*(i+1);
    }

    return dp;
}

float* producte(int m, float* p, int n, float* q) {

    int i, j;
    float* pq;

    pq = (float *) malloc((n+m+1) * sizeof(float));
    if(pq == NULL) {
        printf("Error al crear el vector pq\n");
        exit(1);
    }

    for(i = 0; i <= m+n; i++) {
        pq[i] = 0;
    }

    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            pq[i+j] += p[i]*q[j];
        }
    }
    
    return pq;

}

float* suma(int m, float* p, float* q) {

    int i;
    float *pq;

    pq = (float *) malloc((m+1) * sizeof(float));
    if(pq == NULL) {
        printf("Error al crear el polinomi pq\n");
        exit(1);
    }

    for(i = 0; i <= m; i++) {
        pq[i] = p[i] + q[i];
    }

    return pq;

}
