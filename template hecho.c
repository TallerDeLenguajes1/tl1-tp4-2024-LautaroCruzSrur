#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

Tnodo *crearNodo(TProducto valor);

void insertarNodo(Tnodo **start, Tnodo *newNodo);

void borrarNodo(Tnodo **start, char *datos);

void CopieProductos(Tnodo **start, Tnodo **prod, float precio);

int contarProdStock(Tnodo **start);

void quitarElementos(Tnodo **start, Tnodo **Prod, int stock);

void liberarLista(Tnodo **Startl1);

/* estas estructuras estan en la libreria funciones.h
typedef struct TProducto
{
    char * Descripcion;
    char * Categoria;
    int Precio;
    int Stock;

}TProducto;

typedef struct Tnodo
{
    TProducto dato;
    struct Tnodo *siguiente;
}Tnodo;
*/
int main()
{
    TProducto *ProductosDeProveedor1 = ProveedorDeLacteosPanaderiaLiquidos();
    MostrarProductosDeArreglo(ProductosDeProveedor1, 17, "Proveedor 1");

    // PUNTO 1. Insertar todos los productos en una única lista
    Tnodo *listaDeProductos = NULL;
    // ingrese su código aquí
    for (int i = 0; i < 17; i++)
    {
        Tnodo *newNodo = crearNodo(ProductosDeProveedor1[i]);
        insertarNodo(&listaDeProductos, newNodo);
    }

    MostrarLista(listaDeProductos, "Todos los productos");
    // FIN PUNTO 1

    // PUNTO 2. Ingrese un precio y filtre los productos que tengan un precio mayor al ingresado
    Tnodo *productosFiltradosPorPrecio = NULL;
    float precio;
    printf("Ingrese precio: \n");
    scanf("%f", &precio);
    printf("Precio ingresado: %f", precio);
    // ingrese su código aquí

    CopieProductos(&productosFiltradosPorPrecio, &listaDeProductos, precio);

    MostrarLista(productosFiltradosPorPrecio, "Productos con precio filtrado");
    // FIN PUNTO 2

    // PUNTO 3. Contar productos sin stock y mostrar la cantidad
    int cantidadSinStock;
    // ingrese su código aquí
    cantidadSinStock = contarProdStock(&listaDeProductos);
    MostrarCantidadSinStock(cantidadSinStock);
    // FIN PUNTO 3

    // PUNTO 4. Desenlazar los productos sin stock y mostrarlos
    Tnodo *productosFiltradoPorStock = NULL;
    int stock;
    printf("Ingrese stock: \n");
    scanf("%d", &stock);
    printf("Stock ingresado: %d", stock);
    // ingrese su código aquí

    quitarElementos(&productosFiltradoPorStock, &listaDeProductos, stock);

    MostrarLista(productosFiltradoPorStock, "Productos con stock mayor al ingresado");
    MostrarLista(listaDeProductos, "Productos con stock menor a al ingresado");
    // FIN PUNTO 4

    // PUNTO 5. Liberar todas las listas
    //  ingrese su código aquí

    liberarLista(&listaDeProductos);
    liberarLista(&productosFiltradosPorPrecio);
    liberarLista(&productosFiltradoPorStock);

    MostrarLista(listaDeProductos, "Lista vacia de listaDeProductos ");
    MostrarLista(productosFiltradosPorPrecio, "Lista vacia de productosFiltradosPorPrecio");
    MostrarLista(productosFiltradoPorStock, "Lista vacia de productosSinStock");
    // FIN PUNTO 5
}

Tnodo *crearNodo(TProducto valor)
{
    Tnodo *newNodo = (Tnodo *)malloc(sizeof(Tnodo));
    newNodo->dato = valor;
    newNodo->siguiente = NULL;
    return newNodo;
}

void insertarNodo(Tnodo **start, Tnodo *newNodo)
{
    newNodo->siguiente = *start;
    *start = newNodo;
}

void CopieProductos(Tnodo **start, Tnodo **prod, float precio)
{
    Tnodo *aux = *prod;

    while (aux != NULL)
    {
        if (aux->dato.Precio > precio)
        {
            Tnodo *newNodo = crearNodo(aux->dato);
            insertarNodo(start, newNodo);
        }
        aux = aux->siguiente;
    }
}

int contarProdStock(Tnodo **start)
{
    int cont = 0;
    Tnodo *aux = *start;

    while (aux != NULL)
    {
        if (aux->dato.Stock == 0)
        {
            cont++;
        }
        aux = aux->siguiente;
    }
    return cont;
}

void borrarNodo(Tnodo **start, char *datos)
{
    Tnodo **aux = start;
    // TProducto auxProd = (*aux)->dato;
    while ((*aux) != NULL && (*aux)->dato.Descripcion != datos)
    {
        aux = &(*aux)->siguiente;
    }
    if (*aux)
    {
        Tnodo *temp = *aux;
        *aux = (*aux)->siguiente;
        free(temp);
    }
}

void quitarElementos(Tnodo **start, Tnodo **Prod, int stock)
{
    Tnodo **auxListaProductos = Prod;
    Tnodo *auxListaProductosStock = *start;
    Tnodo *auxAnterior = *auxListaProductos;

    while ((*auxListaProductos) != NULL)
    {
        if (*auxListaProductos == *Prod && auxAnterior == *Prod)
        {
            if ((*auxListaProductos)->dato.Stock > stock)
            {
                // Tnodo *newNodo = crearNodo((*auxListaProductos)->dato);
                //  borrarNodo(Prod, (*auxListaProductos).dato.Descripcion);
                Tnodo *temp = *auxListaProductos;
                *Prod = (*temp).siguiente;
                temp->siguiente = NULL;
                insertarNodo(start, temp);
                // free(temp); no sirve (por no eliminar)
                auxAnterior = *Prod;
            }
            else
            {
                auxListaProductos = &(*auxListaProductos)->siguiente;
            }
        }
        else
        {
            if ((*auxListaProductos)->dato.Stock > stock)
            {
                // Tnodo *newNodo = crearNodo((*auxListaProductos)->dato);
                //  borrarNodo(Prod, (*auxListaProductos).dato.Descripcion);
                Tnodo *temp = *auxListaProductos;
                // if (temp == NULL)
                // {
                //     auxAnterior->siguiente = NULL;
                // }
                // else
                // {
                (*auxAnterior).siguiente = (*temp).siguiente;
                //}
                temp->siguiente = NULL;
                insertarNodo(start, temp);
                // free(temp); no sirve (por no eliminar)
            }
            else
            {
                auxAnterior = auxAnterior->siguiente;
                auxListaProductos = &(*auxListaProductos)->siguiente;
            }
        }
    }
}

void liberarLista(Tnodo **Startl1)
{
    Tnodo **auxl1 = Startl1;
    while (*auxl1 != NULL)
    {
        Tnodo *temp = *auxl1;
        *auxl1 = (*auxl1)->siguiente;
        free(temp);
    }
}