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
    return c->inicio->elemento;
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
    if (c->inicio != NULL) {
        nodoQ *aBorrar = c->inicio;
        c->inicio = c->inicio->sig;
        if (c->inicio == NULL) {
            c->final = NULL;
        }
        delete aBorrar;
    }
}

// Destruir cola siempre es en O(n)
void destruirCola(Cola &c) {
    while (!esVaciaCola(c)) {
        desencolar(c);
    }
    delete c;
}

void destruirColaV2(Cola &c) {
    while (c->inicio != NULL) {
        nodoQ *aux = c->inicio;
        c->inicio = c->inicio->sig;
        delete aux;
    }
    delete c;
}

void imprimirCola(Cola c) {
    nodoQ *actual = c->inicio;
    printf("Cola: ");
    while (actual != NULL) {
        printf("%d ", actual->elemento);
        actual = actual->sig;
    }
    printf("\n");
}

int main() {
    Cola colaNueva = colaVacia();
    encolar(1, colaNueva);
    encolar(2, colaNueva);
    encolar(3, colaNueva);
    encolar(4, colaNueva);
    encolar(5, colaNueva);
    printf("Elemento del frente: %d\n", frente(colaNueva));
    imprimirCola(colaNueva);
    desencolar(colaNueva);
    imprimirCola(colaNueva);
    destruirColaV2(colaNueva);
    imprimirCola(colaNueva);
}