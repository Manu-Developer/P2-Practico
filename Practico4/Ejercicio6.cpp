#include <stdio.h>

struct nodo {
    int elem;
    nodo* sig;
};

struct cabezal {
    nodo* primero;
    nodo* actual;
};

typedef cabezal* lista;

lista listaVacia() {
    cabezal* nuevoCabezal = new cabezal;
    nuevoCabezal->primero = NULL;
    nuevoCabezal->actual = NULL;
    return nuevoCabezal;
}

void inicio(lista& l) {
    if (l != NULL) {
        l->actual = l->primero;
    }
}

void siguiente(lista& l) {
    if (l->actual->sig == NULL) {  // Estoy en el ultimo nodo.
        l->actual = l->primero;
    } else {
        l->actual = l->actual->sig;
    }
}

void insertar(lista& l, int elemento) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->elem = elemento;

    if (l == NULL) {
        l = new cabezal;
        l->primero = nuevoNodo;
        nuevoNodo->sig = NULL;
    } else {
        nuevoNodo->sig = l->actual->sig;
        l->actual->sig = nuevoNodo;
    }
    l->actual = nuevoNodo;
}

int elemento(lista l) {
    return l->actual->elem;
}

int main() {
}