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

bool esColaVacia(colaImpresora cp) {
    return cp->aImprimir = 0;
}

void insertarElemento(colaImpresora &cp, char *string, int prioridad) {
    encolarColaString(string, cp->colas[prioridad]);

    if (prioridad > cp->aImprimir) {
        cp->aImprimir = prioridad;
    }
}

char *imprimir(colaImpresora &cp) {
    int maxPrioridad = cp->aImprimir;
    char *texto = frenteColaString(cp->colas[maxPrioridad]);
    desencolarColaString(cp->colas[maxPrioridad]);

    while (esColaVacia(cp->colas[maxPrioridad] && maxPrioridad > 0)) {
        maxPrioridad--;
    }

    return texto;
}

void destruir(colaImpresora &cp) {
    for (int i = 0; i <= K; i++) {
        destruirColaString(cp->colas[i]);
    }
    delete[] cp->colas;
    delete cp;
    cp = NULL;
}
