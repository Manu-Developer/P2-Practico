#include <stdio.h>

#include "../Practico7/Ejercicio3a.h"

struct nodoQ {
    int elemento;
    nodoQ *sig;
};

struct cabezal {
    nodoQ *inicio;
    nodoQ *final;
};

Deque dequeVacia() {
    Deque dequeVacia = new cabezal;
    dequeVacia->inicio = NULL;
    dequeVacia->final = NULL;
    return dequeVacia;
}

bool esVaciaDeque(Deque c) {
    return c->inicio == NULL;
}

int inicio(Deque c) {
    if (!esVaciaDeque(c)) {
        return c->inicio->elemento;
    }
}

int final(Deque c) {
    if (!esVaciaDeque(c)) {
        return c->final->elemento;
    }
}

void insertar_inicio(int t, Deque &c) {
    nodoQ *nuevoNodo = new nodoQ;
    nuevoNodo->elemento = t;
    nuevoNodo->sig = c->inicio;

    if (c->inicio == NULL) {
        c->final = nuevoNodo;
    }

    c->inicio = nuevoNodo;
}

void insertar_final(int t, Deque &c) {
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

void eliminar_inicio(Deque &c) {
    if (!esVaciaDeque(c)) {
        nodoQ *aBorrar = c->inicio;
        c->inicio = c->inicio->sig;
        if (c->inicio == NULL) {
            c->final = NULL;
        }
        delete aBorrar;
    }
}

void eliminar_final(Deque &c) {
    if (!esVaciaDeque(c)) {
        if (c->inicio == c->final) {
            // Solo un elemento
            delete c->inicio;
            c->inicio = NULL;
            c->final = NULL;
        } else {
            nodoQ *actual = c->inicio;
            while (actual->sig != c->final) {
                actual = actual->sig;
            }
            delete c->final;
            c->final = actual;
            c->final->sig = NULL;
        }
    }
}