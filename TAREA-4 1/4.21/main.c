#include <stdio.h>

/* Funciones y parámetros. */

int Z, Y;

int F1(float);
void main(void);

void main(void)
{
    int W;
    float X;
    Z = 5;
    Y = 7;
    W = 2;
    X = (float) Y / Z;
    printf("\nPrograma Principal: %d %d %.2f %d", Z, Y, X, W);
    F2 (X, &W);
    printf("\nPrograma Principal: %d %d %.2f %d", Z, Y, X, W);
}

int F1(float X)
{
    int K;
    if (X!= 0)
    {
        K = Z + Y;
        X++;
    }
    else
        K = Z + Y;
    printf("\nF1: %d %d %.2f %d", Z, Y, X, K);
    return(K);
}

void F2(float T, int *R)
{
    int Y;
    Y = 5;
    Z - 0;

    printf("\nF2: %d %d %.2f %d", Z, Y, T, *R);
    if (Z == 0)
    {
        Z = (*R) * 2;
        T = (float) Z / 3;
        printf("\nIngrese el valor: ");
        scanf("%d", R);
        printf("\nF2: %d %d %.2f %d", Z, Y, T, *R);
    }
    else
    {
        Z = (*R) * 2;
        printf("\nF2: %d %d %.2f %d", Z, Y, T, *R);
    }
    *R = F1(T);
}
