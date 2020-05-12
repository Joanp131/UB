/* operacions-llistes.c
S'implementen diferents operacions est�ndard amb llistes

L'important �s adonar-se que per a treballar amb llistes cal usar:
   punters, alloc's i free's

No �s important la informaci� que hi ha en cada node
Per aix� s'usa un tipus d'estructura molt simple, amb 3 camps:
   clau:   int    (diferent per a cada node, permet identificar-lo)
   info:   float  (aix� es pot canviar per qualsevol altra cosa)
   seg:    punter al seg�ent element de la llista

S'implementen 3 operacions:
   escriure la llista
   inserir un node ordenadament per la clau
   eliminar un node determinat per la clau
cada operaci� s'implementa en una funci� separada
en el main, hi ha un "men�" que permet triat l'operaci�

Com a comprovaci�, despr�s de cada operaci� s'escriu la llista tal com ha quedat
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
void eliminar(node **);
void alliberar_llista(node *);

int main(void)
{
   node *inici = NULL;     /* punter al primer node, la llista �s buida */
   int oper;
   
   do {
      printf("\n");
      printf("      0. ESCRIURE LA LLISTA FINAL i ACABAR \n");
      printf("      1. INSERIR UN NODE, ordenadament per la clau \n");
      printf("      2. ELIMINAR UN NODE, determinat per la clau \n");
      printf("\n");
      
      scanf("%d", &oper);
      if (oper<0 || oper >2) return 1;
      
      switch (oper) {
         case 0:
            escriure(inici);
            break;
         case 1:
            inici = inserir(inici);
            escriure(inici);            /* com a comprovaci� */
            break;
         case 2:
            eliminar(&inici);
            escriure(inici);            /* com a comprovaci� */
            break;
         default:
            printf("operacio no permesa: cal entrar 0, 1 o 2 \n");
      }
   
   } while (oper != 0);

   /* abans d'acabar, s'allibera tota la mem�ria reservada per a la llista */   
   alliberar_llista(inici);  
   
   return 0;
}

/* escriptura de la llista sencera, enumerant els nodes */
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

/* inserci� d'un node nou al lloc que li toca, ordenadament per la "clau" 
   si la "clau" ja la t� algun altre node, no es fa la inserci� 
en aquesta funci�, el valor final de "inici" es retorna pel "return" 
*/
node * inserir(node *inici)
{
   node *p, *q, *r;
   int xclau;

   printf("clau (int) del node nou ? \n");
   scanf("%d", &xclau);

   /* cas especial: cal inserir al comen�ament */
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

   /* cas general: la llista no �s buida i no s'ha d'inserir al comen�ament */
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

/* eliminaci� d'un node identificat pel seu camp "clau" 
   si no es troba el valor de "clau" buscat no e spot fer l'eliminaci�
en aquesta funci�, el valor final de "inici" torna al main per la llista de par�metres
(per aix� el doble **)
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

   /* cas que no hi �s */
   if (p == NULL || (p->clau) > xclau) {
      printf("la clau no correspon a cap node, no es pot fer l'eliminacio \n");
      return;
   } 

   /* aqu� ja se sap que el node �s a la llista i que l'apunta p */

   /*cas que el node a eliminar �s el primer */
   if ((*inici) == p) {
      *inici = (*inici)->seg;
      free(p);
      return;
   }

   /* cas que falta: el node a eliminar no �s el primer */
   q = *inici;
   while (q->seg != p) 
      q = q->seg;
   /* ara, q apunta al node anterior del que volem eliminar */
   q->seg = p->seg;
   free(p);
   return;
}


/* alliberament de la mem�ria: node a node, del primer a l'�ltim */
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
