#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define RESTA 2
#define SUMA 1
#define MULTIPLICACION 3
#define DIVICION 4
#define EXPONECIACION 5
#define RAIZCUADRADA 6

void Entradanumeros(float *n1, float *n2, float *nZ);
float suma (float n1, float n2);
float resta(float n1, float n2);
float multiplicacion(float n1, float n2);
float division(float n1, float n2);
float exponenciacion(float n1, float n2);
float raizcuadrada(float nZ);
float gResultado = 0.0;
int main()
{
    float numero1 = 0.0;
    float numero2 = 0.0;
    float numeroderaiz = 0.0;
    float resultado = 0.0;
    int menu = 0.0;

    do
    {
        printf("\n0-Salir\n1-Suma\n2-Resta\n3-Multiplicacion\n4-Division\n5-Exponenciacion\n6-Raiz cuadrada\n");
        scanf("%i", &menu);

        if (menu == SUMA)
        {
            Entradanumeros(&numero1, &numero2, NULL);
            resultado = suma(numero1,numero2);
            printf("\nLa suma de %f mas %f: %f", numero1, numero2, resultado);
            printf("\nLa suma de %f mas %f: %f", numero1, numero2, gResultado);
        }
        if (menu == RESTA)
        {
            Entradanumeros(&numero1, &numero2, NULL);
            resultado = resta(numero1, numero2);
            printf("\nLa resta de %f menos %f: %f", numero1, numero2, resultado);
            printf("\nLa resta de %f menos %f: %f", numero1, numero2, gResultado);
        }
        if (menu == MULTIPLICACION)
        {
            Entradanumeros(&numero1, &numero2, NULL);
            resultado = multiplicacion(numero1, numero2);
            printf("\nLa multiplicacion de %f por %f: %f", numero1, numero2, resultado);
            printf("\nLa multiplicacion de %f por %f: %f", numero1, numero2, gResultado);
        }
        if (menu == DIVICION)
        {
            Entradanumeros(&numero1, &numero2, NULL);
            resultado = division(numero1, numero2);
            printf("\nLa divicion de %f entre %f: %f", numero1, numero2, resultado);
            printf("\nLa divicion de %f entre %f: %f", numero1, numero2, gResultado);
        }
        if (menu == EXPONECIACION)
        {
            Entradanumeros(&numero1, &numero2, NULL);
            resultado = exponenciacion(numero1, numero2);
            printf("\nLa Exponenciacion de %f elevado %f: %f", numero1, numero2, resultado);
            printf("\nLa Exponenciacion de %f elevado %f: %f", numero1, numero2, gResultado);
        }
        if (menu == RAIZCUADRADA)
        {
            Entradanumeros(NULL, NULL , &numeroderaiz);
            resultado = raizcuadrada(numeroderaiz);
            printf("\nLa raiz cuadrada de %f es: %f", numeroderaiz, resultado);
            printf("\nLa raiz cuadrada de %f es: %f", numeroderaiz, gResultado);
        }
    }
    while(menu != 0);
    printf("\nFin de programa");
    return 0;
}
//vamos a pasr por referencia
void Entradanumeros(float *n1, float *n2, float *nZ)
{
    if (nZ == NULL)
    {
    printf("\nIngrese numero1:");
    scanf("%f",n1);
    printf("\nIngrese numero2:");
    scanf("%f",n2);
    }
   else
   {
       do
       {
       {
       printf("\nIngrese numero:");
       scanf("%f",nZ);
       }
   if (*nZ < 0)
   {
       printf("\nNumero no valido\n ");
   }
   }while (*nZ < 0);
   }
   }
// por valor
float suma(float n1, float n2)
{
    float resultado = 0.0;
    resultado = n1 + n2;
    gResultado = resultado;
    return resultado;
}
float resta(float n1, float n2)
{
    float resultado = 0.0;
    resultado = n1 - n2;
    gResultado = resultado;
    return resultado;
}
float multiplicacion(float n1, float n2)
{
    float resultado = 0.0;
    resultado = n1 * n2;
    gResultado = resultado;
    return resultado;
}
float division(float n1, float n2)
{
    float resultado = 0.0;
    resultado = n1 / n2;
    gResultado = resultado;
    return resultado;
}
float exponenciacion(float n1, float n2)
{
    float resultado = 0.0;
    resultado = pow(n1, n2);
    gResultado = resultado;
    return resultado;
}
float raizcuadrada(float nZ)
{
    float resultado = 0.0;
    resultado = sqrt(nZ);
    gResultado = resultado;
    return resultado;
}

