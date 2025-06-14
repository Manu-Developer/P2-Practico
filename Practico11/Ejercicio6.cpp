#include "../Practico11/Ejercicio6.h"

#include <stdio.h>

struct nodoT {
    int tope;
    int cota;
    int cant;
    generico* array;
};

T crearTADVacio(int K) {
    T nuevaT = new nodoT;
    nuevaT->cant = 0;
    nuevaT->tope = K - 1;
    nuevaT->cota = K;
    nuevaT->array = new generico[K];
    return nuevaT;
}

void insertar(generico e, T& t) {
    t->tope = (t->tope++) % t->cota;
    t->array[t->tope] = e;
    if (t->cant < t->cota) {
        t->cant++;
    }
}

generico tope(T t) {
    return t->array[t->tope];
}

void desapilar(T& t) {
    if (t->cant > 0) {
        t->cant--;
        if (--t->tope < 0) {
            t->tope = t->cota - 1;
        }
    }
}

bool esVacio(T t) {
    return t->cant == 0;
}

bool esLLeno(T t) {
    return t->cant == t->cota;
}

void destruir(T& t) {
    delete[] t->array;
    delete t;
    t = NULL;
}