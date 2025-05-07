#include "../Practico7/Ejercicio1b.h"

#include <stdio.h>

struct nodo {
    int elemento;
    nodo* sig;
};

struct cabezal {
    nodo* inicial;
    nodo* final;
};

LEnt crearL() {
    LEnt listaVacia = NULL;
    return listaVacia;
}

void insertar(int x, LEnt& l) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->elemento = x;
    nuevoNodo->sig = l->inicial;
    l->inicial = nuevoNodo;

    if (l->final == NULL) {
        l->final = l->inicial;
    }
}

LEnt listaVacia() {
    LEnt l = new cabezal;
    l->inicial = NULL;
    l->final = NULL;
    return l;
}

bool esVacia(LEnt l) {
    return l->inicial == NULL && l->final == NULL;
}

int primero(LEnt l) {
    if (!esVacia(l)) {
        return l->inicial->elemento;
    }
}

void resto(LEnt& l) {
    if (!esVacia(l)) {
        nodo* aBorrar = l->inicial;
        l->inicial = l->inicial->sig;
        delete aBorrar;
    }
}

/* Inserta el elemento x al final de la lista . */
void insFinal(int x, LEnt& l) {
    nodo* nuevo = new nodo;
    nuevo->elemento = x;
    nuevo->sig = NULL;

    if (l->final != NULL) {
        l->final->sig = nuevo;
    } else {
        l->inicial = nuevo;
    }

    l->final = nuevo;
}