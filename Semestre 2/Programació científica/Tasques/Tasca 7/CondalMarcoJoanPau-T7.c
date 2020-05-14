/* operacions-llistes.c
S'implementen diferents operacions estàndard amb llistes

L'important és adonar-se que per a treballar amb llistes cal usar:
   punters, alloc's i free's

No és important la informació que hi ha en cada node
Per això s'usa un tipus d'estructura molt simple, amb 3 camps:
   clau:   int    (diferent per a cada node, permet identificar-lo)
   info:   float  (això es pot canviar per qualsevol altra cosa)
   seg:    punter al següent element de la llista

S'implementen 3 operacions:
   escriure la llista
   inserir un node ordenadament per la clau
   eliminar un node determinat per la clau
cada operació s'implementa en una funció separada
en el main, hi ha un "menú" que permet triat l'operació

Com a comprovació, després de cada operació s'escriu la llista tal com ha quedat
-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>

/* tipus i nom de l'estructura que s'usa */
typedef struct elem {
   int clau;
   float info;
   struct elem *seg;
} node;

void escriure(node *);       
node * inserir(node *);
node *eliminarPrimer(node*);
node *inserirFinal(node *);
void eliminar(node **);
void alliberar_llista(node *);

int main(void)
{
   node *inici = NULL;     /* punter al primer node, la llista és buida */
   int oper;
   
   do {
      printf("\n");
      printf("      0. ESCRIURE LA LLISTA FINAL \n");
      printf("      1. INSERIR UN NODE, ordenadament per la clau \n");
      printf("      2. ELIMINAR UN NODE, determinat per la clau \n");
      printf("      3. ELIMINAR EL PRIMER NODE\n");
      printf("      4. INSERIR UN NODE AL FINAL\n");
      printf("\n");
      
      scanf("%d", &oper);
      if (oper<0 || oper > 4) return 1;
      
      switch (oper) {
         case 0:
            escriure(inici);
            break;
         case 1:
            inici = inserir(inici);
            escriure(inici);            /* com a comprovació */
            break;
         case 2:
            eliminar(&inici);
            escriure(inici);            /* com a comprovació */
            break;
         case 3:
            inici = eliminarPrimer(inici);
            escriure(inici);
            break;
         case 4:
            inici = inserirFinal(inici);
            escriure(inici);
            break;
         default:
            printf("operacio no permesa: cal entrar 0, 1 o 2 (o -1 per sortir) \n");
      }
   
   } while (oper != 0);

   /* abans d'acabar, s'allibera tota la memòria reservada per a la llista */   
   alliberar_llista(inici);  
   
   return 0;
}

/*
 * Escriu la llista sencera a partir del primer node
 * 
 * Variables:
 *    node *inici : Primer node de la llista, es comença a escriure a partir d'ell
 * 
 * Procediment:
 *    1. Si el primer node és NULL (la llista és buida), es fa saber i es para
 *    2. Si la llista no és buida, escriu
 */
void escriure(node *inici)
{
   node *p;
   int k;
   
   if (inici == NULL)
      printf("llista buida \n");
   else {
      printf("llista: \n");
      p = inici;
      k = 0;
      while (p != NULL) {
         k = k+1;
         printf(" node %2d: clau = %3d info = %15.2f \n", k, p->clau, p->info);
         p = p->seg;
      }
   }

   return;
}

/*
 * Demana una clau i insereix el node en el lloc corresponent, ordenat per clau
 * 
 * Variables:
 *    node *inici : Primer node de la llista
 * 
 * Procediment:
 *    1. Demana la clau del node que es vol afegir
 *    2. Si la clau donada és menor que la clau del node de inici (o si el node de inici no existeix)
 *       es col·loca p davant de la llista i es retorna el mateix p
 *    3. En cas contrari, es comprova que la clau no existeixi. En cas afirmatiu, es fa saber i es para
 *    4. Si la clau donada no existeix, es posa el node on cal
 * 
 * Retorna:
 *    inici si p no s'ha posat a davant
 *    p si s'ha col·locat davant de inici
 */
node * inserir(node *inici)
{
   node *p, *q, *r;
   int xclau;

   printf("clau (int) del node nou ? \n");
   scanf("%d", &xclau);

   /* cas especial: cal inserir al començament */
   if (inici == NULL || inici-> clau > xclau) {
      p = (node *)malloc(sizeof(node));
      if (p == NULL)
         printf("no ha funcionat el malloc en inserir \n");
      else {
         p->clau = xclau;
         printf("info (float) del node nou ? \n");
         scanf("%f", &(p->info));
         p->seg = inici;
         inici = p;
      }
      return inici;
   }

   /* cas general: la llista no és buida i no s'ha d'inserir al començament */
   p = inici;
   while (p != NULL && (p->clau) < xclau)
      p = p->seg;
   
   if (p != NULL && p->clau == xclau)
      printf("la clau ja existeix! no es fa la insercio \n");
   else {
      r = (node *)malloc(sizeof(node));
      if (r == NULL)
         printf("no ha funcionat el malloc en inserir \n");
      else {
          r->clau = xclau;
         printf("info (float) del node nou ? \n");
         scanf("%f", &(r->info));
         
         q = inici;
         while (q->seg != p)
            q = q->seg;
         q->seg = r;
         r->seg = p;
      }
   }
   return inici;
}

/* 
* Elimina el primer node de la llista
* 
*/
node *eliminarPrimer(node *inici) {

   node *ptr;

   /* Si el primer node és NULL, la llista és buida */
   if(inici == NULL) {
      printf("La llista és buida, no es pot eliminar el primer node");
      ptr = inici;
   } else {
      ptr = inici->seg;
      free(inici);
   }

   return ptr;

}

node *inserirFinal(node *inici) {
   
   node *p, *q;
   int clau;

   /* Si no hi ha llista, el node inserit és el primer */
   if(inici == NULL) {
      printf("Clau de p?\n");
      scanf("%d", &clau);

      p = (node *) malloc(sizeof(node));
      if(p == NULL) {
         printf("Problemes al crear p\n");
         return inici;
      }

      p->clau = clau;

      printf("Valor del node?\n");
      scanf("%f", &(p->info));

      return p;
   } else {
      q = inici;
      while(q->seg != NULL) {
         q = q-> seg;
      }

      printf("Dona'm la clau del node, major que %d\n", q->clau);
      scanf("%d", &clau);
      while(clau <= q->clau) {
         printf("La clau ha de ser major que %d\n", q->clau);
         scanf("%d", &clau);
      }

      p = (node *) malloc(sizeof(node));
      p->clau = clau;

      printf("Valor del node?\n");
      scanf("%f", &(p->info));

      q->seg = p;
      p->seg = NULL;
   }

   return inici;

}

/* eliminació d'un node identificat pel seu camp "clau" 
   si no es troba el valor de "clau" buscat no es pot fer l'eliminació
en aquesta funció, el valor final de "inici" torna al main per la llista de paràmetres
(per això el doble **)
*/
void eliminar(node **inici)
{
   node *p, *q;
   int xclau;

   printf("clau del node que es vol eliminar ? \n");
   scanf("%d", &xclau);

   /* busquem el node a la llista (ordenada), per la "clau" */
   p = *inici;
   while (p != NULL && (p->clau) < xclau) 
      p = p->seg;

   /* cas que no hi és */
   if (p == NULL || (p->clau) > xclau) {
      printf("la clau no correspon a cap node, no es pot fer l'eliminacio \n");
      return;
   } 

   /* aquí ja se sap que el node és a la llista i que l'apunta p */

   /*cas que el node a eliminar és el primer */
   if ((*inici) == p) {
      *inici = (*inici)->seg;
      free(p);
      return;
   }

   /* cas que falta: el node a eliminar no és el primer */
   q = *inici;
   while (q->seg != p) 
      q = q->seg;
   /* ara, q apunta al node anterior del que volem eliminar */
   q->seg = p->seg;
   free(p);
   return;
}


/* alliberament de la memòria: node a node, del primer a l'últim */
void alliberar_llista(node *inici)
{
   node *p;
   
   while (inici != NULL) {
      p = inici;
      inici = inici->seg;
      free(p);
   }
   return;
}
