#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura Tarea
typedef struct Tarea {
    int TareaID;
    char Descripcion[100];
    int Duracion;
} Tarea;

// Definición de la estructura Nodo
typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

// Función para generar automáticamente el ID de la tarea
int GenerarID() {
    static int id = 1000;
    return id++;
}

// Función para solicitar una tarea pendiente al usuario
Tarea SolicitarTareaPendiente() {
    Tarea nuevaTarea;
    nuevaTarea.TareaID = GenerarID();
    printf("Ingrese la descripción de la tarea: ");
    scanf(" %[^\n]", nuevaTarea.Descripcion);
    printf("Ingrese la duración de la tarea (en minutos): ");
    scanf("%d", &nuevaTarea.Duracion);
    return nuevaTarea;
}

// Función para insertar una nueva tarea al final de la lista de pendientes
void InsertarTareaPendiente(Nodo **inicio, Tarea tarea) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        fprintf(stderr, "Error: No se pudo asignar memoria para el nodo\n");
        exit(EXIT_FAILURE);
    }
    nuevoNodo->T = tarea;
    nuevoNodo->Siguiente = NULL;

    if (*inicio == NULL) {
        *inicio = nuevoNodo;
    } else {
        Nodo *temp = *inicio;
        while (temp->Siguiente != NULL) {
            temp = temp->Siguiente;
        }
        temp->Siguiente = nuevoNodo;
    }
}

// Función para transferir una tarea de la lista de pendientes a la lista de realizadas
void TransferirTarea(Nodo **pendientes, Nodo **realizadas, int tareaID) {
    Nodo *anterior = NULL;
    Nodo *actual = *pendientes;

    // Buscar la tarea en la lista de pendientes
    while (actual != NULL && actual->T.TareaID != tareaID) {
        anterior = actual;
        actual = actual->Siguiente;
    }

    if (actual != NULL) {
        // Remover la tarea de la lista de pendientes
        if (anterior == NULL) {
            *pendientes = actual->Siguiente;
        } else {
            anterior->Siguiente = actual->Siguiente;
        }

        // Insertar la tarea en la lista de realizadas
        actual->Siguiente = *realizadas;
        *realizadas = actual;
    } else {
        printf("No se encontró la tarea con el ID especificado.\n");
    }
}

// Función para imprimir la lista de tareas
void ImprimirLista(Nodo *inicio, const char *titulo) {
    printf("%s:\n", titulo);
    Nodo *actual = inicio;
    while (actual != NULL) {
        printf("ID: %d, Descripción: %s, Duración: %d minutos\n", actual->T.TareaID, actual->T.Descripcion, actual->T.Duracion);
        actual = actual->Siguiente;
    }
    printf("\n");
}

int main() {
    Nodo *pendientes = NULL;
    Nodo *realizadas = NULL;
    char opcion;

    do {
        Tarea nuevaTarea = SolicitarTareaPendiente();
        InsertarTareaPendiente(&pendientes, nuevaTarea);

        printf("¿Desea ingresar otra tarea? (s/n): ");
        scanf(" %c", &opcion);
    } while (opcion == 's' || opcion == 'S');

    printf("\n");

    ImprimirLista(pendientes, "Tareas Pendientes");

    printf("Ingrese el ID de la tarea a transferir a realizadas: ");
    int tareaID;
    scanf("%d", &tareaID);
    TransferirTarea(&pendientes, &realizadas, tareaID);

    printf("\n");

    ImprimirLista(pendientes, "Tareas Pendientes");
    ImprimirLista(realizadas, "Tareas Realizadas");

    // Liberar memoria
    Nodo *temp;
    while (pendientes != NULL) {
        temp = pendientes;
        pendientes = pendientes->Siguiente;
        free(temp);
    }
    while (realizadas != NULL) {
        temp = realizadas;
        realizadas = realizadas->Siguiente;
        free(temp);
    }

    return 0;
}
