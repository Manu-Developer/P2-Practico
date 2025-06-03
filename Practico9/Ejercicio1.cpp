#include <stdio.h>

#include "./Practico9/Ejercicio1a.h"

struct nodoTabla {
    int d;
    int r;
    nodoTabla* sig;
};

tabla crearTablaVacia() {
    tabla nuevaTabla = NULL;
    return nuevaTabla;
}

bool esVaciaTabla(tabla t) {
    return t == NULL;
}

void insertarElemento(int d, int r, tabla& t) {
    tabla actual = t;

    while (actual != NULL) {
        if (actual->d == d) {
            // Ya estaba definido: actualizar su valor
            actual->r = r;
            return;
        }
        actual = actual->sig;
    }

    // No estaba definido: insertar al principio
    tabla nuevo = new nodoTabla;
    nuevo->d = d;
    nuevo->r = r;
    nuevo->sig = t;
    t = nuevo;
}

bool estaDefinidoElemento(int d, tabla t) {
    while (t != NULL && t->d != d) {
        t = t->sig;
    }
    return t != NULL;
}

void eliminarElemento(int d, tabla& t) {
    // Caso especial: si el nodo a eliminar está al principio
    if (t != NULL && t->d == d) {
        tabla aBorrar = t;
        t = t->sig;
        delete aBorrar;
        return;
    }

    // Resto de la lista (desde el segundo nodo en adelante)
    tabla actual = t;
    while (actual != NULL && actual->sig != NULL) {
        if (actual->sig->d == d) {
            tabla aBorrar = actual->sig;
            actual->sig = actual->sig->sig;
            delete aBorrar;
            return;  // eliminar solo una ocurrencia
        }
        actual = actual->sig;
    }
}

int recuperarElemento(int d, tabla t) {
    while (t != NULL) {
        if (t->d == d) {
            return t->r;
        }
        t = t->sig;
    }
}

int main() {
    return 0;
}