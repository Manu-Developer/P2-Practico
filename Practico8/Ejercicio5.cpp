#include "./Practico8/Ejercicio5.h"

#include <stdio.h>

struct nodo {
    int clave;
    nodo *sig;
};

struct tabla {
    int tamTabla;
    int cantElems;
    nodo **hash;
};

int functionHash(int d);

void insertarH(int d, TTabla &t) {
    int posicion = functionHash(d);
    nodo *nuevo = new nodo;
    nuevo->clave = d;
    nuevo->sig = t->hash[posicion];
    t->hash[posicion] = nuevo;
}

bool sumaPares(ListaEnt l, int largo, int k) {
    ListaEnt aux = crearVaciaL();
    TTabla THash = crearTabla();
    bool resultado = false;

    while (l != NULL && !resultado) {
        int x = primeroL(l);
        restoL(l);
        resultado = resultado && estaDefinidaH(THash, x - k);
        insertarH(x, THash);
    }

    destruirL(l);
    destruirH(THash);
    return resultado;
}