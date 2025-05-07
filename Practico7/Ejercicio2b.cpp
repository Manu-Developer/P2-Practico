#include <stdio.h>

#include "../Practico7/Ejercicio2a.h"

struct nodoQ {
    int elemento;
    nodoQ *sig;
};

struct cabezal {
    nodoQ *inicio;
    nodoQ *final;
};

Cola colaVacia() {
    Cola colaVacia = new cabezal;
    colaVacia->inicio = NULL;
    colaVacia->final = NULL;
    return colaVacia;
}

bool esVaciaCola(Cola c) {
    return c->inicio == NULL;
}

int frente(Cola c) {
    if (!esVaciaCola(c)) {
        return c->inicio->elemento;
    }
}

void encolar(int t, Cola &c) {
    nodoQ *nuevoNodo = new nodoQ;
    nuevoNodo->elemento = t;
    nuevoNodo->sig = NULL;

    if (c->inicio == NULL) {
        c->inicio = nuevoNodo;
    } else {
        c->final->sig = nuevoNodo;
    }

    c->final = nuevoNodo;
}

void desencolar(Cola &c) {
    if (!esVaciaCola(c)) {
        nodoQ *aBorrar = c->inicio;
        c->inicio = c->inicio->sig;
        if (c->inicio == NULL) {
            c->final == NULL;
        }
        delete aBorrar;
    }
}

// Existe una forma de destruir una cola en O(1)?
void destruirCola(Cola &c) {
    while (!esVaciaCola(c)) {
        desencolar(c);
    }
    delete c;
}