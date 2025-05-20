#include "./Practico8/Ejercicio1.h"

#include <stdio.h>

struct nodoHash {
    int dato;
    nodoHash* sig;
};

struct rep_conjunto {
    int cota;
    int cantidad;
    nodoHash** tabla;  // Un array en el cual cada posicion contiene punteros a una lista simplemente encadenada.
};

// Si todos los enteros son igualmente probables devuelvo i.
int hash(int i) {
    return i;
}

conjunto crearConjunto(int cota) {
    conjunto c = new rep_conjunto();
    c->tabla = new nodoHash*[cota];
    for (int i = 0; i < cota; i++) c->tabla[i] = NULL;
    c->cantidad = 0;
    c->cota = cota;
    return c;
}

bool perteneceConjunto(int i, conjunto c) {
    nodoHash* lista = c->tabla[hash(i) % (c->cota)];

    while (lista != NULL && lista->dato != i) {
        lista = lista->sig;
    }

    return lista != NULL;
}

void insertarConjunto(int i, conjunto& c) {
    if (!perteneceConjunto(i, c)) {
        nodoHash* nuevo = new nodoHash;
        nuevo->dato = i;
        nuevo->sig = c->tabla[hash(i) % (c->cota)];
        c->tabla[hash(i) % (c->cota)] = nuevo;
        c->cantidad++;
    }
}

void eliminarConjunto(int i, conjunto& c) {
    if (perteneceConjunto(i, c)) {
        int posicion = hash(i) % c->cota;
        nodoHash* actual = c->tabla[posicion];
        nodoHash* anterior = NULL;

        while (actual != NULL && actual->dato != i) {
            anterior = actual;
            actual = actual->sig;
        }

        if (actual != NULL) {
            if (anterior == NULL) {
                // Era el primero en la lista
                c->tabla[posicion] = actual->sig;
            } else {
                anterior->sig = actual->sig;
            }
            delete actual;
            c->cantidad--;
        }
    }
}

bool esVacioConjunto(conjunto c) {
    return c->cantidad == 0;
}

bool esVacioConjuntoV2(conjunto c) {
    int i = 0;
    for (i; i < c->cota && c->tabla[i] == NULL; i++);
    return i == c->cota;
}

bool esLlenoConjunto(conjunto c) {  // La funcion tambien se puede llamar todasLasPosicionesOcupadas.
    int i = 0;
    for (i; i < c->cota && c->tabla[i] != NULL; i++);
    return i == c->cota;
}

void destruirConjunto(conjunto& c) {
    for (int i = 0; i < c->cantidad; i++) {
        eliminarConjunto(i, c);
    }
    delete[] c->tabla;
    delete c;
    c = NULL;
}