/* Joan Pau Condal Marco - 20334366 */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char sign;
    unsigned int num;
    unsigned int den;
} fraccio;

/** 
 * Retorna el màxim comú divisor de dos enters no negatius.
 * Se sap que el segon no és zero
*/
unsigned int mcd(unsigned int a, unsigned int b);

/** 
 * Transforma una fracció a forma irreductible
*/
void reduir(fraccio* a);

/** 
 * Suma dues fraccions i redueix el resultat
*/
void suma(fraccio a, fraccio b, fraccio* c);

/** 
 * Retorna la resta, en forma reduïda, de dues fraccions
*/
fraccio resta(fraccio a, fraccio b);

/** 
 * Retorna el producte reduït de dues fraccions
*/
fraccio producte(fraccio a, fraccio b);

/** 
 * Fa el quocient de dues fraccions (si es pot) i redueix el resultat.
 * 
 * Retorna:
 *      0 si es pot fer la divisió
 *      1 si no es pot fer la divisió
*/
unsigned int quocient(fraccio a, fraccio b, fraccio* c);

/** 
 * Escriu una operació sencera en el format de l'exemple
*/
void escriure(fraccio a, char op, fraccio b, fraccio c);

int main(void) {

    fraccio a, b, c;

    /* Llegim les dues fraccions inicials i comprovem que són correctes */
    printf("Escriu les dues fraccions inicials:\n");
    
    scanf("%c %u %u %c %u %u", &a.sign, &a.num, &a.den, &b.sign, &b.num, &b.den);

    while ((a.sign != '+' && a.sign != '-') || (b.sign != '+' && b.sign != '-') || a.den == 0 || b.den == 0) {
        printf("%c %u %u %c %u %u\n", a.sign, a.num, a.den, b.sign, b.num, b.den);
        printf("Les dades són incorrectes.\n");
        printf("Torna a escriure les dues fraccions inicials:\n");
        scanf("%c %u %u %c %u %u", &a.sign, &a.num, &a.den, &b.sign, &b.num, &b.den);
    }

    /* Fem les operacions */
    suma(a, b, &c);

    return 0;
}

unsigned int mcd(unsigned int a, unsigned int b) {
    
    int aux;

    while (a % b != 0) {
        aux = a;
        a = b;
        b = aux % b;
    }

    return b;
}

void reduir(fraccio* a) {
    unsigned int d;

    d = mcd(a->num, a->den);

    a->num /= d;
    a->num /= d;

    return;
}

void suma(fraccio a, fraccio b, fraccio* c) {

    c->num = a.num * b.den + b.num * a.den;
    c->den = a.den * b.den;

    reduir(c);
    escriure(a, '+', b, *c);

    return;
}

fraccio resta(fraccio a, fraccio b) {

    fraccio c;

    if(a.sign == '+' && b.sign == '-') {
        
    }
    c.num = a.num * b.den - b.num * a.den;
    c.den = a.den * b.den;

    reduir(&c);

    return c;

}

void escriure(fraccio a, char op, fraccio b, fraccio c) {
    printf("( %c %u / %u ) %c ( %c %u / %u ) = ( %c %u / %u )\n", a.sign, a.num, a.den, op, b.sign, b.num, b.den, c.sign, c.num, c.den);

    return;
}