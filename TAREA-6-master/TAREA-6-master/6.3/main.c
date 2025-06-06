#include <stdio.h>

 /* Universidad.
 El programa, al recibir informaci�n sobre el n�mero de alumnos que han ingresado a sus ocho diferentes carreras en los dos semestres lectivos de los �ltimos cinco a�os, obtiene informaci�n �til para el departamento de escolar. */

const int F = 8, C = 2, P = 5;
/* Se declaran constantes para la fila, la columna y la profundidad. */
void Lectura(int [][C][P], int, int, int);
void Funcion1(int [][C][P], int, int, int);
void Funcion2(int [][C][P], int, int, int);
void Funcion3(int [][C][P], int, int, int);
 /* Prototipo de funciones. Cada prototipo de funci�n corresponde a uno de los incisos. */
void main (void)
{
    int UNI[F][C][P];
    Lectura (UNI, F, C, P);
    Funcion1 (UNI, F, C, P);
    Funcion2 (UNI, F, C, P);
    Funcion3 (UNI, 6, C, P);
    /* Se coloca el 6como par�metro ya que es la clave de la Ingenier�a en Computaci�n. */
}

void Lectura(int A[][C][P], int FI, int C0, int PR)
 /* La funci�n Lecturase utiliza para leer un arreglo tridimensional de tipo entero de FIfilas, COcolumnas y PRprofundidad. Observa que al ser tridimensional se necesitan tres ciclos para recorrer el arreglo. */
{
    int K, I, J;
    for (K=0; K<PR; K++)
        for (I=0; I<FI; I++)
        for (J=0; J<C0; J++)
    {
        printf("Ano: %d\tCarrera: %d\tSamestre: %d ", K+1, I+1, J+1);
        scanf("%d", &A[I][J][K]);
    }
}

void Funcion1(int A[][C][P], int F1, int C0, int PR)
 /* Esta funci�n se utiliza para determinar el a�o en el que ingres� el mayor n�mero de alumnos a la universidad. Observa que el primer ciclo externo corresponde a los a�os. */
 {
     int K, I, J, MAY = 0, A0 = -1, SUM;
     for (K=0; K<PR; K++)
        /* Por cada a�o se suma el ingreso de los dos semestres de las ocho carreras. */
     {
         SUM = 0;
         for (J=0; J<C0; J++)
            SUM += A[I][J][K];
         if (SUM > MAY)
         {
             MAY = SUM;
             A0 = K;
         }
         printf("\n\nAno con mayor ingreso de alumno: %d  alumnos: %d",  A0+1, MAY);
     }
 }

 void Funcion2(int A[][C][P], int FI, int C0, int PR)
  /* Esta funci�n se utiliza para determinar la carrera que recibi� el mayor n�mero de alumnos el �ltimo a�o. Observa que no se utiliza un ciclo para los planos de la profundidad, ya que es un dato (PR). */
 {
     int I, J, MAY = 0, CAR = -1, SUM;
     for (I=0; I<FI; I++)

     {
         SUM = 0;
         for (J=0; J<C0; J++)
            SUM += A[I][J][PR-1];
         if (SUM > MAY)
         {
             MAY = SUM;
             CAR = I;
         }
         printf("\n\nCarrera con mayor numero de alumno: %d  alumnos: %d",  CAR+1, MAY);
     }
 }

 void Funcion3(int A[][C][P], int FI, int C0, int PR)
 /* Esta funci�n se utiliza para determinar el a�o en el que la carrera Ingenier�a en Computaci�n recibi� el mayor n�mero de alumnos. Observa que no se utiliza un ciclo para trabajar con las filas, ya que es un dato (FI). */
 {
     int K, I, J, MAY = 0, A0 = -1, SUM;
     for (K=0; K<PR; K++)
        /* Por cada a�o se suma el ingreso de los dos semestres de las ocho carreras. */
     {
         SUM = 0;
         for (J=0; J<C0; J++)
            SUM += A[F-1][J][K];
         if (SUM > MAY)
         {
             MAY = SUM;
             A0 = K;
         }
         printf("\n\nAno con mayor ingreso de alumno: %d  alumnos: %d",  A0+1, MAY);
     }
 }
