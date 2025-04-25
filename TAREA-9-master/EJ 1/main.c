#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
struct Nodo
{
    int dato;
    struct Nodo* siguiente;
};

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza)
{
    struct Nodo* actual = cabeza;
    while (actual != NULL)
    {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main()
{
    // Crear nodos
    struct Nodo* cabeza = malloc(sizeof(struct Nodo));
    struct Nodo* segundo = malloc(sizeof(struct Nodo));
    struct Nodo* tercero = malloc(sizeof(struct Nodo));

    // Asignar valores y enlazar nodos
    cabeza->dato = 1;
    cabeza->siguiente = segundo;

    segundo->dato = 2;
    segundo->siguiente = tercero;

    tercero->dato = 3;
    tercero->siguiente = NULL;

    // Imprimir la lista
    imprimirLista(cabeza);

    // Liberar memoria
    free(cabeza);
    free(segundo);
    free(tercero);
    return 0;
}
