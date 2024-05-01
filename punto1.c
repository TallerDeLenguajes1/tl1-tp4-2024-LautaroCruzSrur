#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Tarea //!) Definimos la estructura TAREA
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
}Tarea;

typedef struct Nodo //2)Definimos el NODO
{
    Tarea T; //AQUI SE ALMACENA LA TAREA
     struct Nodo *Siguiente; // LUEGO SE APUNTA AL NODO SIGUIENTE
}Nodo;


Nodo *CrearTarea(char *descripcion , int duracion , int id){ //3) DEFINO LA FUNCION PARA CREAR TAREAS
    Nodo* NNodo = (Nodo*)malloc(sizeof(Nodo)); //LA ASIGNACION DE MEMORAI DE LA TAREA
    NNodo->T.Descripcion = strdup(descripcion); //ASIGNO LA DESCRIPCION A LA TAREA
    NNodo->T.Duracion = duracion;//...
    NNodo->T.TareaID = id;//.....
    NNodo->Siguiente = NULL;  //INICIALIZO EL NUEVO NODO VACIO.
    return NNodo; // 4) LA FUNCION "CREAR TAREAS" ME DEVUELVE UN NODO CON LA TAREA.
}
Nodo *TareaRealizada(Nodo *Star, int IdBuscado){ //BUSCO LA TAREA A REALIZAR
    Nodo* Aux= Star; // APUNTO AL PRIMER NODO DE LA LISTA
    while (Aux != NULL && Aux->T.TareaID != IdBuscado) // SI ID ES DISTINTO AL DEL NODO SIGUE
    {
        Aux = Aux->Siguiente;
    }
    return Aux; // DEVUELVE EL NODO ENCONTRADO.
}

void InsertarTarea(Nodo **Star, Nodo *NuevoNodo){ //INTRODUSCO LAS TAREAS AL INICIO DE LA LISTA.
    NuevoNodo->Siguiente = *Star;
    *Star = NuevoNodo;
}

int Id(){
    static int id = 1000;
    return id++;
}
void MostrarTareas(Nodo *Inicio) {
    Nodo *Actual = Inicio;
    while (Actual != NULL) {
        printf("ID de Tarea: %d\n", Actual->T.TareaID);
        printf("Descripción: %s\n", Actual->T.Descripcion);
        printf("Duración: %d minutos\n\n", Actual->T.Duracion);
        Actual = Actual->Siguiente;
    }
}
void InicioTareas(Nodo *Star){
    printf("¡Bienvenido!\n");
    do
    {
        char descripcion[100];
        int duracion = 0;
        printf("Ingrese la tarea pendiente:");
        scanf("%s",descripcion);
        printf("\nIngresa la duracion: \n");
        scanf("%d", &duracion);
        InsertarTarea(&Star, CrearTarea(descripcion, duracion , Id()));
        char continuar;
        printf("¿Desea agregar otra tarea? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's' && continuar != 'S') {
            break;
        }
        
    } while(1);
    MostrarTareas(Star);
}
int main()
{
    Nodo * Star = NULL; //DECLARO STAR QUE APUNTARA AL INICIO DE LA LISTA
    InicioTareas(Star);
    return 0;
}

