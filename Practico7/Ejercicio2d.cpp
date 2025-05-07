#include <stdio.h>

#include "../Practico7/Ejercicio2c.h"

struct rep_cola {
    int *array;
    int principio;
    int fin;
    int cantidad;
    int cota;
};

Cola crearCola(int cota) {
    Cola colaVacia = new rep_cola;
    colaVacia->array = new int[cota];
    colaVacia->principio = 0;
    colaVacia->fin = 0;
    colaVacia->cantidad = 0;
    colaVacia->cota = cota;
    return colaVacia;
}

bool esVaciaCola(Cola c) {
    return c->cantidad == 0;
}

bool esLlenaCola(Cola c) {
    return c->cota == c->cantidad;
}

int frente(Cola c) {
    if (!esVaciaCola(c)) {
        return c->array[c->principio];
    }
}

void encolar(int t, Cola &c) {
    if (!esLlenaCola(c)) {
        c->array[c->fin] = t;
        c->fin++;

        if (c->fin == c->cota) {
            c->fin = 0;
        }

        c->cantidad++;
    }
}

void desencolar(Cola &c) {
    if (!esVaciaCola(c)) {
        c->principio++;

        if (c->principio == c->cota) {
            c->principio = 0;
        }

        c->cantidad--;
    }
}

// Existe una forma de destruir una cola en O(1)?
void destruirCola(Cola &c) {
    delete[] c->array;
    delete c;
}