#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Tarea //!) Definimos la estructura TAREA
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
} Tarea;

typedef struct Nodo // 2)Definimos el NODO
{
    Tarea T;                // AQUI SE ALMACENAN LAS TAREAS
    struct Nodo *Siguiente; // LUEGO SE APUNTA AL NODO SIGUIENTE
} Nodo;

Nodo *CrearTarea(char *descripcion, int duracion, int id)
{                                               // 3) DEFINO LA FUNCION PARA CREAR TAREAS
    Nodo *NNodo = (Nodo *)malloc(sizeof(Nodo)); // LA ASIGNACION DE MEMORIA PARA GUARDAR LAS TAREAS.
    NNodo->T.Descripcion = strdup(descripcion); // ASIGNO LA DESCRIPCION A LA TAREA
    NNodo->T.Duracion = duracion;               //...
    NNodo->T.TareaID = id;                      //.....
    NNodo->Siguiente = NULL;                    // INICIALIZO EL NUEVO NODO VACIO.
    return NNodo;                               // 4) LA FUNCION "CREAR TAREAS" ME DEVUELVE UN NODO CON LA TAREA.
}
// Nodo *TareasRealizadas(){
//     // Nodo* NNodo = (Nodo*)malloc(sizeof(Nodo));
//     // NNodo->Siguiente = NULL;
//     return NULL;
// }

Nodo *BuscarTarea(Nodo *Star, int IdBuscado)
{                                                      // BUSCO LA TAREA A REALIZAR
    Nodo *Aux = Star;                                  // APUNTO AL PRIMER NODO DE LA LISTA
    while (Aux != NULL && Aux->T.TareaID != IdBuscado) // SI ID ES DISTINTO AL DEL NODO SIGUE
    {
        Aux = Aux->Siguiente;
    }
    return Aux; // DEVUELVE EL NODO ENCONTRADO.
}

void InsertarTarea(Nodo **Star, Nodo *NuevoNodo)
{ // INTRODUSCO LAS TAREAS AL INICIO DE LA LISTA.
    NuevoNodo->Siguiente = *Star;
    *Star = NuevoNodo;
}
void InsertarTareasRealizadas(Nodo **Star, Nodo *NuevoNodo)
{ // INSERTAMOS AL NODO DE TAREAS REALIZADAS
    NuevoNodo->Siguiente = *Star;
    *Star = NuevoNodo;
}

int Id()
{ // Funcion para tener un id
    static int id = 1000;
    return id++;
}

void MostrarTareas(Nodo *Inicio)
{                       // A Mostrar Tarea se le pasa el primer nodo.
    Nodo *Aux = Inicio; // Crea un Auxiliar que se le pasa el valor del inicio del nodo.
    while (Aux != NULL)
    { // Siempre que el nodo sea distinto de NULL sigue en el bucle
        printf("ID de Tarea: %d\n", Aux->T.TareaID);
        printf("Descripción: %s\n", Aux->T.Descripcion);
        printf("Duración: %d minutos\n\n", Aux->T.Duracion);
        Aux = Aux->Siguiente; // Una vez mostrado el contenido del nodo pasa al siguiente.
    }
}
void MostrarTareasRealizadas(Nodo *Inicio)
{                       // A Mostrar Tarea se le pasa el primer nodo.
    Nodo *Aux = Inicio; // Crea un Auxiliar que se le pasa el valor del inicio del nodo.
    while (Aux != NULL)
    { // Siempre que el nodo sea distinto de NULL sigue en el bucle
        printf("ID de Tarea: %d\n", Aux->T.TareaID);
        printf("Descripción: %s\n", Aux->T.Descripcion);
        printf("Duración: %d minutos\n\n", Aux->T.Duracion);
        Aux = Aux->Siguiente; // Una vez mostrado el contenido del nodo pasa al siguiente.
    }
}

void InicioTareas(Nodo *Star)
{ // A InicioTarea se le pasa el NULL del primer nodo.
    printf("¡Bienvenido!\n");
    do
    {
        char descripcion[100];
        int duracion = 0;
        printf("Ingrese la tarea pendiente:");
        scanf("%s", descripcion);
        printf("\nIngresa la duracion: \n");
        scanf("%d", &duracion);
        InsertarTarea(&Star, CrearTarea(descripcion, duracion, Id()));
        char continuar;
        printf("¿Desea agregar otra tarea? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's' && continuar != 'S')
        {
            break;
        }

    } while (1);
    MostrarTareas(Star);
}
void TareasRealizadas(Nodo *Inicio)
{
    int id = 0;
    printf("\n Porfavor ingrese el ID de la tarea que desea pasar a \"Realizada\" \n");
    scanf("%d", &id);
    InsertarTareasRealizadas(&Inicio, BuscarTarea(Inicio, id));
    MostrarTareasRealizadas(Inicio);
}

int main()
{
    char bandera;
    Nodo *Star = NULL; // DECLARO STAR QUE APUNTARA AL INICIO DE LA LISTA
    InicioTareas(Star);
    printf("\n¿Desea transferir tareas pendientes a realizadas?(s/n)\n");
    scanf("%c", &bandera);
    if (bandera != 's' && bandera != 'S')
    {
        TareasRealizadas(Star);
    }

    return 0;
}
