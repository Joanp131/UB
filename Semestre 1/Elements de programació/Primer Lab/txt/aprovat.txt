

#include <stdio.h>

int main(void) {
   float qualificacio;
   printf("Quina qualificacio tens?\n");
   scanf("%f", &qualificacio);
   if (qualificacio < 5) {
      printf("Has suspès l'examen.\n");
   } else {
      printf("Has aprovat l'examen.\n");
   }
   return 0;
}
