#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Nmax 100
#define Nclient 100
#define FILENAME "Raleatorios.txt"

typedef struct {
    int id;
    int Cnumeros;
} Client;

Client *clients[Nclient];
int clientcount = 0;
int hist[Nmax] = {0};
int count[Nmax] = {0};
time_t seed;

// Generar números aleatorios
void Naleat(int *oro, int *plata, int *bronce) {
    *oro = rand() % 100 + 1;
    *plata = rand() % 100 + 1;
    *bronce = rand() % 100 + 1;
}

// Guardar números en un archivo
void Gresult(int oro, int plata, int bronce) {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Error al abrir el archivo\n");
        return;
    }
    fprintf(file, "%d %d %d\n", oro, plata, bronce);
    fclose(file);
}

// Registrar un cliente
void Tclient(int Cnumero) {
    if (clientcount >= Nclient) {
        printf("Máximo de clientes alcanzado\n");
        return;
    }
    clients[clientcount] = (Client *)malloc(sizeof(Client));
    clients[clientcount]->id = clientcount + 1;
    clients[clientcount]->Cnumeros = Cnumero;
    clientcount++;
}

// Mostrar historial
void showhist() {
    printf("Numeros sorteados:\n");
    for (int i = 0; i < Nmax; i++) {
        if (hist[i] != 0) {
            printf("Numero: %d - Veces salido: %d\n", hist[i], count[i]);
        }
    }
}

// Mostrar ganadores
void Lganadores(int oro, int plata, int bronce) {
    printf("\nResultados del sorteo: ORO: %d, PLATA: %d, BRONCE: %d\n", oro, plata, bronce);
    for (int i = 0; i < clientcount; i++) {
        if (clients[i]->Cnumeros == oro || clients[i]->Cnumeros == plata || clients[i]->Cnumeros == bronce) {
            printf("Jugador %d ganó con el número %d!\n", clients[i]->id, clients[i]->Cnumeros);
        }
    }
}

// Menú principal
void menu() {
    int option, Cnombre, jugadores, oro, plata, bronce;
    do {
        printf("\n1. Agregar jugadores\n");
        printf("2. Listar historial de numeros\n");
        printf("3. Tirar numeros y determinar ganadores\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);

        switch (option) {
        case 1:
            printf("Ingrese la cantidad de jugadores: ");
            scanf("%d", &jugadores);
            for (int i = 0; i < jugadores; i++) {
                printf("Jugador %d, ingrese su numero (1-100): ", i + 1);
                scanf("%d", &Cnombre);
                Tclient(Cnombre);
            }
            break;
        case 2:
            showhist();
            break;
        case 3:
            Naleat(&oro, &plata, &bronce);
            Gresult(oro, plata, bronce);
            hist[clientcount] = oro;
            count[clientcount]++;
            hist[clientcount + 1] = plata;
            count[clientcount + 1]++;
            hist[clientcount + 2] = bronce;
            count[clientcount + 2]++;
            Lganadores(oro, plata, bronce);
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida\n");
        }
    } while (option != 4);
}

int main() {
    seed = time(NULL);
    srand(seed);
    menu();
    return 0;
}
