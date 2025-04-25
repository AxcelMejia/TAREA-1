#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo* anterior;
    struct Nodo* siguiente;
};

// Función para imprimir la lista de inicio a fin
void imprimirLista(struct Nodo* cabeza)
{
    while (cabeza != NULL)
    {
        printf("%d <-> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

int main()
{
    struct Nodo* cabeza = malloc(sizeof(struct Nodo));
    struct Nodo* segundo = malloc(sizeof(struct Nodo));
    struct Nodo* tercero = malloc(sizeof(struct Nodo));

    cabeza->dato = 1;
    cabeza->anterior = NULL;
    cabeza->siguiente = segundo;

    segundo->dato = 2;
    segundo->anterior = cabeza;
    segundo->siguiente = tercero;

    tercero->dato = 3;
    tercero->anterior = segundo;
    tercero->siguiente = NULL;

    imprimirLista(cabeza);

    return 0;
}
