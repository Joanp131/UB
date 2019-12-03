/* Retorna el valor de la derivada al punt x */

#include <math.h>

/* x³ - 10*sin(x) 
double dfun(double x) {
    double y = 3*x*x - 10*cos(x);
    return y;
}
*/

double dfun(double x) {
    double y = 6*pow(x, 5) - 1;
    return y;
}