void InsertarTarea2(Nodo *Star, Nodo *NuevoNodo){ //FUNCION PARA INTRODUCIR AL FINAL DE LA LISTA
    Nodo *Aux= Star;
    while(Aux->Siguiente){
        Aux = Aux->Siguiente;
    }
    Aux-> Siguiente = NuevoNodo;
}