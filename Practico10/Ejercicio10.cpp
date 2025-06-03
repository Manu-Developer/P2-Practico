#include "../Practico10/Ejercicio10.h"

#include <stdio.h>

struct cabezal {
    ColaStrings *colas;
    int aImprimir;
};

colaImpresora crearCola() {
    colaImpresora nuevaCI = new cabezal;
    nuevaCI->aImprimir = 0;
    nuevaCI->colas = new ColaStrings[K + 1];
    for (int i = 0; i <= K; i++) {
        nuevaCI->colas[i] = crearColaString();
    }
    return nuevaCI;
}

bool esColaVacia(colaImpresora ci) {
    return ci->aImprimir = 0;
}

void insertarElemento(colaImpresora &ci, char *string, int prioridad) {
    encolarColaString(string, ci->colas[prioridad]);

    if (prioridad > ci->aImprimir) {
        ci->aImprimir = prioridad;
    }
}

char *imprimir(colaImpresora &ci) {
    int maxPrioridad = ci->aImprimir;
    char *texto = frenteColaString(ci->colas[maxPrioridad]);
    desencolarColaString(ci->colas[maxPrioridad]);

    while (esColaVacia(ci->colas[maxPrioridad] && maxPrioridad > 0)) {
        maxPrioridad--;
    }

    return texto;
}

void destruir(colaImpresora &ccip) {
    for (int i = 0; i <= K; i++) {
        destruirColaString(ci->colas[i]);
    }
    delete[] ci->colas;
    delete ci;
    ci = NULL;
}
