#clude <stdio.h>

 /* Suma matrices.
 El programa, al recibir como datos dos arreglos bidimensionales del mismo tamaño, calcula la suma de ambos y la almacena en un tercer arreglo bidimensional. */

 const int MAX = 50;
  /* Prototipo de funciones. */
 void Lectura(int [][MAX], int, int);
 void Suma(int [][MAX], int [][MAX], int[][MAX], int, int);
 void Imprime(int [][MAX], int, int);

void main(void)
{
    int MA[MAX][MAX], MB[MAX][MAX], MC[MAX][MAX];
    /* Declaración de los tres arreglos */
    int FIL, COL;
    do
    {
        printf("Imprese el numero de filas de los arreglas: ");
        scanf("%d", &FIL);
    }
    while (FIL>MAX || FIL< 1);
    /* Se verifica que el número de filas sea correcto. */
    do
    {
        printf("Ingrese el numero de columnas de los arreglos: ");
        scanf("%d", &COL);
    }
    while (COL > MAX || COL < 1);
    /* Se verifica que el número de columnas sea correcto. */
    printf("\nLectura del Arreglo ")
}
