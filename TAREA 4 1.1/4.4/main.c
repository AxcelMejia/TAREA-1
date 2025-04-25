#include <stdio.h>

/* Prueba de variables globales, locales y estáticas.
El programa utiliza funciones en las que se usan diferentes tipos de variables. */

int f1(void);
int f2(void);                    /* Prototipos de funciones. */
int f3(void);
int f4(void);

int G = 3;                       /* Variable global. */

void main(void)
{
    int I;
    for (I = 1; I <= 3; I++)
    {
        printf("\nEl resultado de la funcion f1 es: %d", f1());
        printf("\nEl resultado de la funcion f2 es: %d", f2());
        printf("\nEl resultado de la funcion f3 es: %d", f3());
        printf("\nEl resultado de la funcion f4 es: %d", f4());
    }
}

int f1(void)
/*La función ff11 utiliza la variable global. */
{
    G += G;
    return(G);
}
 int f2(void)
 /* La función ff22 utiliza la variable local. */
 {
     int K =1;
     K++;
     return(K);
 }
 int f3(void)
 /* La función ff33 utiliza la variable estática. */
 {
     static int K = 8;
     K += 2;
     return (K);
 }
 int f4(void)
 /* La función f4 utiliza dos variables con el mismo nombre: local y global. */
 {
     int K = 5;
     K = K + G;        /* Uso de la variable local (KK) y global (G) */
     return(K);
 }
