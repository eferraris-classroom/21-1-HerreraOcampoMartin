#ifndef INC_21_1_HERRERAOCAMPOMARTIN_COLACIRCULAR_H
#define INC_21_1_HERRERAOCAMPOMARTIN_COLACIRCULAR_H

typedef struct nodo{
    int valor;
    struct nodo *siguiente;
} Nodo;

typedef struct colaCircular{
    int tam;
    Nodo *primero;
    Nodo *ultimo; // Este lo pongo para hacer la vida más fácil
} ColaCircular;

ColaCircular *crearColaCircular();
Nodo *crearNodo(int valor);
void agregarNodo(ColaCircular *cola, Nodo *nuevo);
void eliminarNodo(ColaCircular *cola, int valorAEliminar);
void imprimirCola(ColaCircular *cola);
void liberarCola(ColaCircular *cola);

#endif
