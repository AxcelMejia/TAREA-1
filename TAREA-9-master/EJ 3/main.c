#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo* siguiente;
};

// Función para eliminar un nodo por valor
void eliminarNodo(struct Nodo** cabeza, int valor)
{
    struct Nodo* temp = *cabeza, *prev = NULL;

    if (temp != NULL && temp->dato == valor)
    {
        *cabeza = temp->siguiente;
        free(temp);
        return;
    }

    while (temp != NULL && temp->dato != valor)
    {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == NULL) return;

    prev->siguiente = temp->siguiente;
    free(temp);
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

    printf("Lista antes de eliminar:\n");
    imprimirLista(cabeza);

    eliminarNodo(&cabeza, 2);

    printf("Lista después de eliminar 2:\n");
    imprimirLista(cabeza);

    return 0;
}
