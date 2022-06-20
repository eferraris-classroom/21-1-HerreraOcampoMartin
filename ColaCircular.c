#include "ColaCircular.h"
#include <stdio.h>
#include <stdlib.h>

ColaCircular *crearColaCircular(){
    ColaCircular *cola = (ColaCircular*) malloc(sizeof (ColaCircular));

    if(cola == NULL){
        printf("No hay memoria libre.");
        exit(-1);
    }

    cola->tam = 0;
    cola->primero = NULL;
    cola->ultimo = NULL;

    return cola;
}

Nodo *crearNodo(int valor){
    Nodo *nuevo = (Nodo*) malloc(sizeof (Nodo));

    if ( nuevo == NULL ){
        printf("No hay memoria libre.");
        exit(-1);
    }

    nuevo->valor = valor;
    nuevo->siguiente = NULL;

    return nuevo;
}

void agregarNodo(ColaCircular *cola, Nodo *nuevo){
    nuevo->siguiente = cola->primero;
    cola->primero = nuevo;

    if(cola->ultimo == NULL){
        cola->ultimo = nuevo;
    } else {
        cola->ultimo->siguiente = nuevo;
    }

    cola->tam++;
}

void eliminarNodo(ColaCircular *cola, int valorAEliminar){
    Nodo *act = cola->primero;
    Nodo *ant = act;

    while(act != NULL && act->valor != valorAEliminar){
        ant = act;
        act = act->siguiente;
    }

    if(act == NULL){
        return;
    }

    if(act == ant){
        if(act == act->siguiente){ // Si la lista tiene un solo elemento
            cola->primero = NULL;
            cola->ultimo = NULL;
            free(act);
        }else { // Si la cola tiene más de un elemento
            cola->primero = act->siguiente;
            cola->ultimo->siguiente = cola->primero;
            free(act);
        }
    }else {
        ant->siguiente = act->siguiente;
        if(act == cola->ultimo){
            cola->ultimo = ant;
        }
        free(act);
    }

    cola->tam--;
}

void imprimirCola(ColaCircular *cola){
    Nodo *aux = cola->primero;

    if(aux == NULL){
        printf("La lista esta vacía.\n");
        return;
    }

    for(; aux != NULL && aux != cola->ultimo; aux = aux->siguiente){
        printf("%d ", aux->valor);
    }

    printf("%d\n", cola->ultimo->valor);

}

void liberarCola(ColaCircular *cola){
    Nodo *aux = cola->primero;

    if(aux != NULL){
        while(aux->siguiente != NULL && aux != cola->ultimo){
            Nodo *temp = aux->siguiente;
            free(aux);
            aux = temp;
        }
        free(aux);
    }

    free(cola);
}
