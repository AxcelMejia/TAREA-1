#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "C:\\Users\\Axcel\\Documents\\programacion\\PARCIAL2\\PARCIAL2 archivo"

typedef struct
{
    char nombre[50];
    char **renglones;
    int numrenglones;
}estructura;

void seveinfile(estructura *estructuras, int cantidad)
{
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file)
    {
        perror("Error abriendo archivo");
        return;
    }
    fwrite(&cantidad, sizeof(int), 1, file);
    for (int i = 0; i < cantidad; i++)
    {
        fwrite(&estructuras[i], sizeof(estructura), 1, file);
        for (int j = 0; j < estructuras[i].numrenglones; j++)
        {
            fwrite(estructuras[i].renglones[j], sizeof(char), 50, file);
        }
    }
    fclose(file);
}

void leerdesdearchivo()
{
    FILE * file = fopen(FILE_NAME, "rb");
        if (!file)
        {
            perror("Error abriendo archivo");
            return;
        }
        int cantidad;
        fread(&cantidad, sizeof(int), 1, file);
        estructura estructuras[cantidad];
        for (int i = 0; i < cantidad; i++)
        {
            fread(&estructuras[i], sizeof(estructura), 1, file);
            estructuras[i]. renglones = malloc(estructuras[i].numrenglones * sizeof(char *));
            for (int j = 0; j < estructuras[i]. numrenglones; j++)
            {
                estructuras[i].renglones[j] = malloc(50 * sizeof(char));
                fread(estructuras[i]. renglones[j], sizeof(char), 50, file);
            }
        }
        fclose(file);
        printf("\nDatos leidos del archivo: \n");
        for(int i = 0; i < cantidad; i++)
        {
            printf("estructura: %s\n", estructuras[i]. nombre);
            for (int j = 0; j < estructuras[i]. numrenglones; j++)
            {
                printf("  %s\n", estructuras[i].renglones[j]);
            }
        }

}

   int main()
   {
       int cantidad;
           printf("cuantas estructuras quieres? ");
           scanf("%d", &cantidad);
           getchar();
           estructura *estructuras = malloc(cantidad * sizeof(estructura));
           for (int i = 0; i < cantidad; i++)
           {
               printf("Nombre de la estructura %d: ", i + 1);
               fgets(estructuras[i].nombre, 50, stdin);
               estructuras[i].nombre[strcspn(estructuras[i].nombre, "\n")] = 0;
               estructuras[i].numrenglones = 0;
               estructuras[i].renglones = NULL;

               char entrada[50];
               while(1)
               {
                  printf("Renglon (escribe '0' para terminar): ");
                  fgets(entrada, 50, stdin);
                  entrada[strcspn(entrada, "\n")] = 0;
                  if (strcmp(entrada, "0") == 0) break;

                  estructuras[i].numrenglones++;
                  estructuras[i].renglones = realloc(estructuras[i].renglones, estructuras[i].numrenglones * sizeof(char *));
                  estructuras[i].renglones[estructuras[i].numrenglones - 1] = strdup(entrada);
               }
           }

           int opcion;
           do
           {
               printf("\nMenu:\n");
               printf("1. Guardar en archivo\n");
               printf("2. Leer desde archivo\n");
               printf("3. Salir\n");
               printf("Elige una opcion: ");
               scanf("%d", &opcion);
               getchar();

               switch (opcion)
               {
               case 1:
                seveinfile(estructuras, cantidad);
                break;
               case 2:
                leerdesdearchivo();
                break;
               case 3:
                break;
               default:
                printf("Opcion invalida\n");
               }
           }
           while(opcion != 3);
           for (int i = 0; i < cantidad; i++)
           {
               for (int j = 0; j < estructuras[i].numrenglones; j++)
               {
                  free(estructuras[i].renglones[j]);
               }
           }
   }
