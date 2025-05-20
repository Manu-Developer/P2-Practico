#include <stdio.h>

#include "./Practico8/Ejercicio2b.h"

struct rep_conjunto {
    int cota;
    int cantidad;
    bool *elementos;
};

conjunto crearConjunto(int cota) {
    conjunto nuevoConjunto = new rep_conjunto;
    nuevoConjunto->cota = cota;
    nuevoConjunto->cantidad = 0;
    nuevoConjunto->elementos = new bool[cota + 1];
    for (int i = 0; i <= cota; i++) {
        nuevoConjunto->elementos[i] = false;
    }
    return nuevoConjunto;
}

bool esVacioConjunto(conjunto c) {
    return c->cantidad == 0;
}

bool estaLlenoConjunto(conjunto c) {
    return c->cantidad == c->cota;
}

void insertarElemento(conjunto &c, int x) {
    if (c->cantidad < c->cota && c->elementos[x] == false) {
        c->elementos[x] = true;
        c->cantidad++;
    }
}

void eliminarConjunto(conjunto &c, int x) {
    if (c->elementos[x] == true) {
        c->elementos[x] = false;
        c->cantidad--;
    }
}

bool pertenece(conjunto c, int x) {
    return c->elementos[x];
}

void destruirConjunto(conjunto &c) {
    delete[] c->elementos;
    delete c;
    c = NULL;
}

int max(int numero1, int numero2) {
    if (numero1 > numero2) {
        return numero1;
    } else {
        return numero2;
    }
}

conjunto unionConjuntos(conjunto c1, conjunto c2) {
    conjunto unionConjuntos = crearConjunto(max(c1->cota, c2->cota));

    for (int i = 1; i <= unionConjuntos->cota; i++) {
        if (c1->elementos[i] || c2->elementos[i]) {
            unionConjuntos->elementos[i] = true;
            unionConjuntos->cantidad++;
        }
    }

    return unionConjuntos;
}

conjunto interseccionConjuntos(conjunto c1, conjunto c2) {
    conjunto interseccionConjuntos = crearConjunto(max(c1->cota, c2->cota));

    for (int i = 1; i <= interseccionConjuntos->cota; i++) {
        if (c1->elementos[i] && c2->elementos[i]) {
            interseccionConjuntos->elementos[i] = true;
            interseccionConjuntos->cantidad++;
        }
    }

    return interseccionConjuntos;
}

conjunto diferenciaConjuntos(conjunto c1, conjunto c2) {
    conjunto diferenciaConjuntos = crearConjunto(max(c1->cota, c2->cota));

    for (int i = 1; i <= diferenciaConjuntos->cota; i++) {
        if (c1->elementos[i] && !c2->elementos[i]) {
            diferenciaConjuntos->elementos[i] = true;
            diferenciaConjuntos->cantidad++;
        }
    }

    return diferenciaConjuntos;
}