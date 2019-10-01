/* Convertir segons en setmanes, dies, hores, minuts i segons */
#include <stdio.h>

int main(void) {

    int sec, set, dies, hores, minuts, segons;
    printf("Quants segons vols convertir?\n");
    scanf("%d", &sec);

    set = sec/604800;
    dies = (sec-(set*604800))/86400;
    hores = (sec-(set*604800)-(dies*86400))/3600;
    minuts = (sec-(set*604800)-(dies*86400)-(hores*3600))/60;
    segons = (sec-(set*604800)-(dies*86400)-(hores*3600)-(minuts*60));

    printf("%d segons són %d setmanes, %d dies, %d hores, %d minuts i %d segons\n", sec, set, dies, hores, minuts, segons);

    return 0;
}