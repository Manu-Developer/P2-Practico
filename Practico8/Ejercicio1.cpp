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

bool pertenece(int i, conjunto c) {
    nodoHash* lista = c->tabla[hash(i) % (c->cota)];  // int posicion = hash(i) % (c->cota)

    while (lista != NULL && lista->dato != i) {
        lista = lista->sig;
    }

    return lista != NULL;
}

void insertar(int i, conjunto& c) {
    nodoHash* nuevo = new nodoHash;
    nuevo->dato = i;
    nuevo->sig = c->tabla[hash(i) % (c->cota)];
    c->tabla[hash(i) % (c->cota)] = nuevo;
    c->cantidad++;
}

void eliminar(int i, conjunto& c) {
    int posicion = hash(i) % (c->cota);
    while (c->tabla[posicion] != NULL && c->tabla[posicion]->dato == i) {
        nodoHash* aBorrar = c->tabla[posicion];
        c->tabla[posicion] = c->tabla[posicion]->sig;
        delete aBorrar;
    }

    nodoHash* lista = c->tabla[posicion];

    if (lista != NULL) {
        while (lista->sig != NULL) {
            if (lista->sig->dato == i) {
                nodoHash* aBorrar = lista->sig;
                lista->sig = lista->sig->sig;
                delete aBorrar;
            } else {
                lista = lista->sig;
            }
        }
    }
}

void eliminarV2(int i, conjunto& c) {
    if (pertenece(i, c)) {
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
        eliminar(i, c);
    }
    delete[] c->tabla;
    delete c;
    c = NULL;
}