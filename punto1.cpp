#include <stdio.h>
#include <stdlib.h>

typedef struct Tarea //ESTURCTURA DE TAREA
{
    int TareaID;       // Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion;      // entre 10 – 100
}Tarea;

typedef struct Nodo //ESTRUCUTRA DEL NODO
{
    Tarea T; //AQUI SE ALMACENA LA TAREA
     Nodo *Siguiente; // LUEGO SE APUNTA AL NODO SIGUIENTE
}Nodo;

Nodo *CrearTarea(Tarea){ //FUNCION PARA CREAR UNA TAREA
    Nodo* NNodo = (Nodo*)malloc(sizeof(Nodo)); //LA ASIGNACION DE MEMORAI DE LA TAREA
    NNodo->T.Descripcion; //ASIGNO LA DESCRIPCION A LA TAREA
    NNodo->T.Duracion;//...
    NNodo->T.TareaID;//.....
    NNodo->Siguiente = NULL;  //INICIALIZO EL NUEVO NODO VACIO.
    return NNodo; // DEVUELVO EL NODO CREADO
}
Nodo *ListaDeTareas(){ //ESTA FUNCION ES PARA CREAR Y ENLAZAR LOS NODOS
    Nodo *nuevoNodo;
    return NULL;
}
Nodo *ListaDeRealizadas(){ //ESTA FUNCION ES PARA CREAR Y ENLAZAR LOS NODOS
    Nodo *nuevoNodo;
    return NULL;
}
void InsertarTarea(Nodo **Star, Nodo *NuevoNodo){ //INTRODUSCO LAS TAREAS AL INICIO DE LA LISTA.
    NuevoNodo->Siguiente = *Star;
    *Star = NuevoNodo;
}
// void InsertarTarea2(Nodo *Star, Nodo *NuevoNodo){ //FUNCION PARA INTRODUCIR AL FINAL DE LA LISTA
//     Nodo *Aux= Star;
//     while(Aux->Siguiente){
//         Aux = Aux->Siguiente;
//     }
//     Aux-> Siguiente = NuevoNodo;
// }

int main()
{
    Nodo * Star; //DECLARO STAR QUE APUNTARA AL INICIO DE LA LISTA
    Star = ListaDeTareas();


    return 0;
}