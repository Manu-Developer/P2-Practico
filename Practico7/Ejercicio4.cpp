#include "../Practico7/Ejercicio4.h"

#include <stdio.h>

struct rep_pila {
    int* array;
    int tope;
    int cota;
};

struct nodo {
    int valor;
    nodo* sig;
};

struct rep_cola {
    nodo* primero;
    nodo* ultimo;
    int cota;
    int cantidad;
};

void destruirPila(Pila& p) {
    delete[] p->array;
    delete p;
}

bool esVaciaCola(Cola c) {
    return (c->cantidad == 0);
}

void desencolar(Cola& c) {
    nodo* aBorrar = c->primero;
    c->primero = c->primero->sig;
    if (c->primero == NULL) {
        c->ultimo = NULL;
    }
    delete aBorrar;
    c->cantidad--;
}

void destruirCola(Cola& c) {
    while (!esVaciaCola(c)) {
        desencolar(c);
    }
    delete c;
}

bool mismosElementos(Pila& p, Cola& c) {
    if (p->tope + 1 != c->cantidad) {  // tope empieza en 0, así que +1 da el total de elementos
        destruirPila(p);
        destruirCola(c);
        return false;
    }

    int i = p->tope;
    nodo* iter = c->primero;

    while (iter != NULL) {
        if (p->array[i] != iter->valor) {
            destruirPila(p);
            destruirCola(c);
            return false;
        }
        i--;
        iter = iter->sig;
    }

    destruirPila(p);
    destruirCola(c);
    return true;
}