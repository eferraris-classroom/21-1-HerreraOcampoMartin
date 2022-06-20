#include "ColaCircular.h"

int main(){

    ColaCircular *cola = crearColaCircular();

    agregarNodo(cola, crearNodo(12));
    agregarNodo(cola, crearNodo(54));
    agregarNodo(cola, crearNodo(43));
    agregarNodo(cola, crearNodo(65));
    agregarNodo(cola, crearNodo(87));

    imprimirCola(cola);

    eliminarNodo(cola, 43);

    imprimirCola(cola);

    liberarCola(cola);

    return 0;
}