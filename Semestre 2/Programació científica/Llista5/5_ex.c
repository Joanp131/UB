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
    unsigned int flag;

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
    c = producte(a, b);
    flag = quocient(a, b, &c);


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
    a->den /= d;

    return;
}

void suma(fraccio a, fraccio b, fraccio* c) {

    char aux;

    if(a.sign == b.sign) {
        c->num = a.num * b.dem + a.den * b.num;
        c->den = a.den * b.den;
        c->sign = a.sign;

        reduir(c);
    } else {
        aux = a.sign:
        a.sign = b.sign;
        *c = resta(a, b);

        a.sign = aux;
    }
    
    escriure(a, '+', b, *c);

    return;
}

fraccio resta(fraccio a, fraccio b) {

    fraccio c;
    int aux;

    if(a.sign != b.sign) {
        suma(a, b, &c);
        reduir(&c);
    } else {
        c.num = a.sign == '+' ? 
    }

    return c;

}

fraccio producte(fraccio a, fraccio b) {

    fraccio c;

    c.num = a.num * b.num;
    c.den = a.den * b.den;
    if(a.sign == b.sign) {
        c.sign = '+';
    } else {
        c.sign = '-';
    }
    reduir(&c);

    escriure(a, 'x', b, c);

    return c;
}

unsigned int quocient(fraccio a, fraccio b, fraccio* c) {

    unsigned int flag;

    if(b.num == 0) {
        printf("No es pot fer el quocient ja que el divisor és zero!\n");
        flag = 1;
    } else {
        c->num = a.num * b.den;
        c->den = a.den * b.num;

        reduir(c);

        if(a.sign == b.sign) {
            c->sign = '+';
        } else {
            c->sign = '-';
        }

        escriure(a, ':', b, *c);

        flag = 0;
    }

    return flag;
}

void escriure(fraccio a, char op, fraccio b, fraccio c) {
    printf("( %c %u / %u ) %c ( %c %u / %u ) = ( %c %u / %u )\n", a.sign, a.num, a.den, op, b.sign, b.num, b.den, c.sign, c.num, c.den);

    return;
}