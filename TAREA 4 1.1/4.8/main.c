#include <stdio.h>

/* Combinación de variables globales y locales, y parámetros por valor y por referencia. */
int a, b, c, d;      /* Variables globales. */

void function1(int *, int *);
/* Prototipo de función. Observa que los dos parámetros son por referencia. */
int functio2(int, int *);
/* En este prototipo el primer parámetro es por valor y el segundo por referencia. */

void main(void)
{
    int a;            /* Nota que aa es una variable local. */
    a = 1;            /* Se asigna un valor a la variable local a. */
    b = 2;            /* Se asignan valores a las variables globales b,c y d. */
    c = 3;
    d = 4;
    printf("\n%d %d %d %d", a, b, c, d);
    function1 (&b, &c);
    printf("\n%d %d %d %d", a, b, c, d);
    a = functio2(c, &d);
    printf("\n%d %d %d %d", a, b, c, d);
}

void function1(int *b, int *c)
{
    int d;
    a = 5;
    d = 3;
    (*b)++;
    (*c) += 2;
    printf("\n%d %d %d %d", a, *b, *c, d);
}

int functio2(int c, int *d)
{
    int b;
    a++;
    b = 7;
    c += 3;
    (*d) += 2;
    printf("\n%d %d %d %d", a, b, c, *d);
    return(c);
}
