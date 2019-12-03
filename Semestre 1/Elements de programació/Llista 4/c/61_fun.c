/* Retorna el valor de la funció al punt x */

#include <math.h>

/* x³ - 10*sin(x) 

double fun(double x) {
    double y = x*x*x - 10*sin(x);
    return y;
}
*/

double fun(double x) {
    double y = pow(x, 6) - x - 1;
    return y;
}