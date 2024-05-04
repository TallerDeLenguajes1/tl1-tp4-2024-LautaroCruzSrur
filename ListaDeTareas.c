#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int id()
{
    static int id = 1000;
    return id++;
}

typedef struct Tarea
{
    int TareaID;
    char *Descripcion;
    int Duracion;
} Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

Nodo *CrearListaVacia()
{
    return NULL;
}

Nodo *CrearNodo(char *descripcion, int duracion, int id)
{
    Nodo *NNodo = (Nodo *)malloc(sizeof(Nodo));
    NNodo->T.Descripcion = strdup(descripcion);
    NNodo->T.Duracion = duracion;
    NNodo->T.TareaID = id;
    NNodo->Siguiente = NULL;
    return NNodo;
}

// INSERTAR , CREA y MOSTRAR TAREA.
void InsertarTarea(Nodo **Star, Nodo *NuevoNodo)// Función para insertar un nuevo nodo al principio de una lista enlazada
{
    NuevoNodo->Siguiente = *Star;// El puntero Siguiente del nuevo nodo se establece para apuntar al nodo que actualmente es el primero en la lista
    *Star = NuevoNodo; //El puntero Star (que es un puntero a puntero) se actualiza para apuntar al nuevo nodo, lo que lo coloca la incio de la lista.
    printf("\n-----------------------\n");
    printf("Creado Tarea ID: %d \n", NuevoNodo->T.TareaID);
    printf("\n-----------------------\n");
}
void MostrarTareas(Nodo **Inicio)
{
    Nodo *Aux = *Inicio;
    while (Aux != NULL)
    {
        printf("\n");
        printf("ID de Tarea: %d \n", Aux->T.TareaID);
        printf("Descripcion: %s",Aux->T.Descripcion);
        printf("Duracion: %d \n", Aux->T.Duracion);
        Aux = Aux->Siguiente;
    }
}
void MostrarTarea(Nodo **Inicio)
{
    Nodo *Aux = *Inicio;
        printf("\n");
        printf("ID de Tarea: %d \n", Aux->T.TareaID);
        printf("Descripcion: ");
        puts(Aux->T.Descripcion);
        printf("Duracion: %d \n", Aux->T.Duracion);
}
void CrearTarea(Nodo **Star)
{

    char continuar;
    char descripcion[100];
    int duracion = 0;
    do
    {
        printf("Ingresa los datos de la tarea\n");
        printf("Descripcion: ");
        scanf("%s",&descripcion);
        fflush(stdin);
        printf("Ingresa una duracion entre 10 y 100: ");
        scanf("%d", &duracion);
        fflush(stdin);
        if (duracion < 10 || duracion > 100)
        {
            printf("Por favor ingresa un valor entre 10 y 100\n");
            scanf("%d", &duracion);
            fflush(stdin);
        }
        InsertarTarea(Star, CrearNodo(descripcion, duracion, id()));
        
        printf("\n-----------------------\n");
        printf("¿Deseas agregar otra tarea? (s/n): ");
        printf("\n-----------------------\n");
        scanf(" %c", &continuar);
        fflush(stdin);
    } while (continuar == 's' || continuar == 'S');
}
//*****
// BUSCAR Y ELIMINAR TAREA.
Nodo *QuitarNodoPorId(Nodo **Star, int id){
    Nodo * Aux = *Star;
    while (Aux != NULL && Aux->T.TareaID != id)
    {
        Aux= Aux->Siguiente;
    }
    return NULL;
}
Nodo *buscarNodo(Nodo *Star, int idBuscar)
{
    Nodo *Aux = Star;
    while (Aux && Aux->T.TareaID != idBuscar)
    {
        Aux = Aux->Siguiente;
    }
    if(Aux != NULL){
    printf("\n-----------------------\n");
    printf("Nodo Encontrado: %d \n", Aux->T.TareaID);
    printf("\n-----------------------\n");
    }
    return Aux;
}
//Poner un nodo para eliminar tarea 
Nodo *QuitarNodo(Nodo **Inicio, int id){ 
  Nodo ** aux = Inicio;
  Nodo * anterior = *Inicio;
  While(*aux && (*aux)->producto-> != id){
        anterior = aux;
       aux = &(*aux)->siguiente;
    }
   if(aux != NULL){
      anterior->siguiente = (*aux)->siguiente;
      Nodo * nuevoaux = *aux;
      nuevoaux->siguiente = NULL
    }
}
void EliminarTarea(Nodo **Star,Nodo **StarRealizado, int id)
{
    Nodo *aux = *Star;
    Nodo * anterior = NULL;
    while (aux != NULL && aux->T.TareaID != id)
    {
        anterior = aux;
        aux = aux->Siguiente;
    }
    if (aux != NULL)
    {
        if (anterior != NULL)
        {
        anterior->Siguiente = aux->Siguiente;
        }else{
            *Star = aux->Siguiente;
        }
        aux->Siguiente= NULL;
        InsertarTarea(StarRealizado , aux);
        printf("\n-----------------------\n");
        printf("Tarea eliminada %d", id);
        printf("\n-----------------------\n");
    }else{
        printf("Tarea no encontrada");
    }
}
Nodo *buscarPalabra(Nodo *Star, const char *palabra) {
    Nodo *Aux = Star;
    while (Aux != NULL && strstr(Aux->T.Descripcion, palabra) == NULL) {
        Aux = Aux->Siguiente;
    }
    if (Aux != NULL) {
        printf("\n-----------------------\n");
        printf("Nodo Encontrado: %d \n", Aux->T.TareaID);
        printf("\n-----------------------\n");
    } else {
        printf("La palabra no se encontró en ninguna tarea.\n");
    }
    return Aux;
}

int main()
{
    int id = 0 , opcion = 0, bandera = 0;
    Nodo *Star = CrearListaVacia();
    Nodo *StarRealizado = CrearListaVacia();

    char continuar;
    do
    {
        printf("\nElija una opcion: \n");
        printf("----------------------");
        printf("\n 1) Agregar una Tarea \n");
        printf("----------------------");
        printf("\n2)Mover una Tarea a Realizada\n");
        printf("----------------------");
        printf("\n3)Ver tanto las tareas pendientes como las Tareas Realizadas");
        printf("----------------------");
        printf("\n4)Buscar la tarea por id o por palabra clave.\n");
        printf("----------------------");
        printf("\n 5)Salir \n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch (opcion)
        {
        case 1:
            CrearTarea(&Star);
            break;
        case 2:
            printf("Ingrese el id de la tarea realizada:(s/n):\n");
            scanf("%d", &id);
            fflush(stdin);
            EliminarTarea(&Star ,&StarRealizado, id);
            break;
        case 3:
            printf("\n Tareas Pendientes: \n");
            if(Star != NULL){
             MostrarTareas(&Star);
            }else{
             printf("No hay Tareas Pendientes\n");
            }
            printf("\n Tareas Realizadadas: \n");
            if(StarRealizado != NULL){
                MostrarTareas(&StarRealizado);
            }else{
             printf("No hay Tareas Realizadas\n");
            }
            
            break;
        case 4:
           
            printf("Porfavor ingrese 1 si quiere buscar por id\n");
            printf("De lo contrario ingrese 2 para buscar por palabra clave\n");
<<<<<<< HEAD
            scanf("%d",&bandera);
            fflush(stdin);
            if(bandera == 1){
                printf("Ingrese el id\n");
                scanf("%d",&id);
=======
            scanf("%d",&opcion);
            if(opcion == 1){
>>>>>>> b759b2e053d60be98ca02fcd7ee991a0820b9af2
                Nodo *TareaBuscadaPorId = buscarNodo(Star , id);
                if (TareaBuscadaPorId == NULL)
                {
                
                Nodo *TareaBuscadaPorId = buscarNodo(StarRealizado , id);
                if (TareaBuscadaPorId != NULL)
                {
                    printf("Tarea Realizada: ");
                    MostrarTarea(&TareaBuscadaPorId);
                }else{
                    printf("NO existe la tarea \n");
                }
                }else if(TareaBuscadaPorId){
                    printf("Tarea Pendiente: ");
                    MostrarTarea(&TareaBuscadaPorId);
                    printf("\n");
                }else{
                    printf("NO existe la tarea \n");
                }
                
            }else{
                char palabra[10];
                printf("Ingrese la palabra a buscar \n");
                scanf("%s", palabra);
                Nodo *TareaBuscadaPorPalabra = buscarPalabra(Star, palabra);
                if (TareaBuscadaPorPalabra == NULL)
                {
                Nodo *TareaBuscadaPorPalabra = buscarPalabra(StarRealizado , palabra);
                printf("Tarea Realizada: ");
                MostrarTarea(&TareaBuscadaPorPalabra);
                printf("\n");
                }else if(TareaBuscadaPorPalabra){
                    printf("Tarea Pendiente: ");
                    MostrarTarea(&TareaBuscadaPorPalabra);
                    printf("\n");
                }else{
                    printf("NO existe la tarea \n");
                }
            }
            break;
        case 5:
            return 1;
            break;
        default:
            printf("\n Funcion no disponible.");
            break;
        }   
    } while (1);
    printf("\n-----------------------\n");
    printf("Adios!\n");
    printf("\n-----------------------\n");

    return 0;
}
