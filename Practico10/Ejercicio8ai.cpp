#include <stdio.h>

#include "../Practico10/Ejercicio7.h"

struct TInfo {
    int elemento;
    int prioridad;
};

struct nodoCP {
    TInfo info;
    nodoCP* sig;
};

colaP crearColaPrioridadVacia() {
    colaP nuevaCP = NULL;
    return nuevaCP;
}

void insertarElemento(colaP& cp, int x, int prioridad) {
    nodoCP* nuevoNodo = new nodoCP;
    nuevoNodo->info.elemento = x;
    nuevoNodo->info.prioridad = prioridad;
    nuevoNodo->sig = NULL;

    if (cp == NULL || nuevoNodo->info.prioridad < cp->info.prioridad) {
        nuevoNodo->sig = cp;
        cp = nuevoNodo;
    } else {
        colaP aux = cp;
        while (aux->sig != NULL && aux->sig->info.prioridad < nuevoNodo->info.prioridad) {
            aux = aux->sig;
        }
        nuevoNodo->sig = aux->sig;
        aux->sig = nuevoNodo;
    }
}

bool esColaVacia(colaP cp) {
    return cp == NULL;
}

TInfo obtenerMinimo(colaP cp) {
    return cp->info;
}

void borrarMinimo(colaP& cp) {
    if (cp != NULL) {
        nodoCP* aBorrar = cp;
        cp = cp->sig;
        delete aBorrar;
        aBorrar = NULL;
    }
}

// Adicional al ejercicio.
void borrar(colaP& cp, int x) {
    if (cp == NULL) return;

    if (cp->info.elemento == x) {
        nodoCP* aBorrar = cp;
        cp = cp->sig;
        delete aBorrar;
        return;
    }

    nodoCP* aux = cp;
    while (aux->sig != NULL) {
        if (aux->sig->info.elemento == x) {
            nodoCP* aBorrar = aux->sig;
            aux->sig = aux->sig->sig;
            delete aBorrar;
            return;
        }
        aux = aux->sig;
    }
}

void destruir(colaP& cp) {
    while (cp != NULL) {
        colaP aBorrar = cp;
        cp = cp->sig;
        delete aBorrar;
        aBorrar = NULL;
    }
}

int main() {
    return 0;
}