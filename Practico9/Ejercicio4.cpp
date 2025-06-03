#include "../Practico9/Ejercicio4.h"

#include <stdio.h>

struct nodoHash {
    int x;
    int y;
    nodoHash *sig;
};

struct rep_grafica {
    int cota;
    int cantidadElementos;
    nodoHash **tabla;
};

int funcionHash(int x, int cantidadElementos) {
    return x % cantidadElementos;
}

grafica CrearGrafica(int N) {
    grafica nuevaGrafica = new rep_grafica;
    nuevaGrafica->cantidadElementos = 0;
    nuevaGrafica->cota = N;
    nuevaGrafica->tabla = new nodoHash *[N];
    for (int i = 0; i < N; i++) {
        nuevaGrafica->tabla[i] = NULL;
    }
    return nuevaGrafica;
}

void Asociar(int x, int y, grafica &g) {
    if (g->cantidadElementos < g->cota) {
        int indiceHash = funcionHash(x, g->cota);
        nodoHash *nuevoNodo = new nodoHash;
        nuevoNodo->x = x;
        nuevoNodo->y = y;
        nuevoNodo->sig = g->tabla[indiceHash];
        g->tabla[indiceHash] = nuevoNodo;
        g->cantidadElementos++;
    }
}

int Valor(int x, grafica g) {
    int indiceHash = funcionHash(x, g->cota);
    nodoHash *lista = g->tabla[indiceHash];

    while (lista != NULL) {
        if (lista->x == x) {
            return x;
        }
        lista = lista->sig;
    }

    return -1;
}

void Desasociar(int x, grafica &g) {
    int indiceHash = funcionHash(x, g->cota);
    nodoHash *lista = g->tabla[indiceHash];

    if (lista != NULL && lista->x == x) {
        nodoHash *aBorrar = lista;
        lista = lista->sig;
        delete aBorrar;
        aBorrar = NULL;
        g->cantidadElementos--;
    } else {
        // Resto de la lista (desde el segundo nodo en adelante)
        nodoHash *actual = lista;
        while (actual != NULL && actual->sig != NULL) {
            if (actual->x == x) {
                nodoHash *aBorrar = actual->sig;
                actual->sig = actual->sig->sig;
                delete aBorrar;
                g->cantidadElementos--;
                break;
            }
            actual = actual->sig;
        }
    }
}