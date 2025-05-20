#include "../Practico7/Ejercicio1a.h"

#include <stdio.h>

#include <cassert>

struct nodo {
    int elemento;
    nodo* sig;
};

LEnt crearL() {
    LEnt listaVacia = NULL;
    return listaVacia;
}

void insertar(int x, LEnt& l) {
    LEnt nuevoNodo = new nodo;
    nuevoNodo->elemento = x;
    nuevoNodo->sig = l;
    l = nuevoNodo;
}

bool esVacia(LEnt l) {
    return l == NULL;
}

int primero(LEnt l) {
    return l->elemento;
}

void resto(LEnt& l) {
    assert(!esVacia(l));
    LEnt aBorrar = l;
    l = l->sig;
    delete aBorrar;
}

int main() {
    LEnt listaNueva = crearL();
    insertar(10, listaNueva);
    insertar(20, listaNueva);
    insertar(30, listaNueva);
    printf("%d", primero(listaNueva));
}