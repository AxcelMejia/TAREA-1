#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo* siguiente;
};

// Función para insertar al inicio
void insertarInicio(struct Nodo** cabeza, int nuevoDato)
{
    struct Nodo* nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = *cabeza;
    *cabeza = nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza)
{
    while (cabeza != NULL)
    {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

int main()
{
    struct Nodo* cabeza = NULL;

    insertarInicio(&cabeza, 3);
    insertarInicio(&cabeza, 2);
    insertarInicio(&cabeza, 1);

    imprimirLista(cabeza);

    return 0;
}
