#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo* anterior;
    struct Nodo* siguiente;
};

// Función para insertar al final
void insertarFinal(struct Nodo** cabeza, int nuevoDato)
{
    struct Nodo* nuevoNodo = malloc(sizeof(struct Nodo));
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;

    if (*cabeza == NULL)
    {
        nuevoNodo->anterior = NULL;
        *cabeza = nuevoNodo;
        return;
    }

    struct Nodo* temp = *cabeza;
    while (temp->siguiente != NULL)
    {
        temp = temp->siguiente;
    }

    temp->siguiente = nuevoNodo;
    nuevoNodo->anterior = temp;
}

// Función para imprimir la lista
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
    struct Nodo* cabeza = NULL;

    insertarFinal(&cabeza, 1);
    insertarFinal(&cabeza, 2);
    insertarFinal(&cabeza, 3);

    imprimirLista(cabeza);

    return 0;
}
