
/* Llegeix una nota i diu si hem aprovat o no */

#include <stdio.h>

int main(void) {
   float nota;
   printf("Quina nota tens?\n");
   scanf("%f", &nota);    /* llegeix la nota */
   if (nota < 5) {
      printf("Has suspès l'examen.\n");
   } else {
      printf("Has aprovat l'examen.\n");
   }
   return 0;
}
