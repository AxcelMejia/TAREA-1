#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona
{
    char nombre[50];
    int edad;
};

int main()
{
    struct Persona *personas = NULL;
    int cantidad = 0;
    FILE *archivo;

    printf("¿Cuántas personas deseas ingresar?: ");
    scanf("%d", &cantidad);
    getchar(); // limpiar buffer

    personas = (struct Persona*) malloc(cantidad * sizeof(struct Persona));
    if (personas == NULL)
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    for (int i = 0; i < cantidad; i++)
    {
        printf("Persona %d\n", i + 1);
        printf("Nombre: ");
        fgets(personas[i].nombre, 50, stdin);
        strtok(personas[i].nombre, "\n"); // quitar salto de línea
        printf("Edad: ");
        scanf("%d", &personas[i].edad);
        getchar(); // limpiar buffer
    }

    archivo = fopen("datos.bin", "wb");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo.\n");
        free(personas);
        return 1;
    }

    fwrite(personas, sizeof(struct Persona), cantidad, archivo);
    fclose(archivo);
    free(personas);
    personas = NULL;

    // Leer desde el archivo
    archivo = fopen("datos.bin", "rb");
    if (archivo == NULL)
    {
        printf("No se pudo abrir el archivo para lectura.\n");
        return 1;
    }

    // Obtener cantidad de estructuras en el archivo
    fseek(archivo, 0, SEEK_END);
    long tamano = ftell(archivo);
    rewind(archivo);
    cantidad = tamano / sizeof(struct Persona);

    personas = (struct Persona*) realloc(personas, cantidad * sizeof(struct Persona));
    if (personas == NULL)
    {
        printf("Error al reasignar memoria.\n");
        fclose(archivo);
        return 1;
    }

    fread(personas, sizeof(struct Persona), cantidad, archivo);
    fclose(archivo);

    printf("\nListado de personas desde memoria:\n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("Nombre: %s, Edad: %d\n", personas[i].nombre, personas[i].edad);
    }

    free(personas);
    return 0;
}
