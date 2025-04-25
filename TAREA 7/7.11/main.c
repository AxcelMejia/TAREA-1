#include <stdio.h>
#include <ctype.h>

 /* Verifica.
 El programa, al recibir como datos una cadena de caracteres y una posición es
pecífica en la cadena, determina si el caracter correspondiente es una letra minúscula. */

void main(void)
{
    char P, cad[50];
    int n;
    printf("\nIngrese la cadena de caracteres (máximo 50): ");
    gets(cad);
    printf("\nIngrese la posición en la cadena que desea verificar: ");
    scanf("%d", &n);
    if  ((n >= 0) && (n < 50))
    {
         P = cad[n-1];
         if (islower(P))
            printf("\n%c es una letra minúscula", P);
         else
            printf("\n%c no es una letra minúscula", P);
    }
     else
         printf("\nEl valor ingresado de n es incorrecto");
}
