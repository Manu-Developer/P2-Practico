#include <stdio.h>

#include "../Practico10/Ejercicio7.h"

struct nodoCP {
    int elemento;
    int prioridad;
    nodoCP* sig;
};

colaP crearColaPrioridadVacia() {
    colaP nuevaCP = NULL;
    return nuevaCP;
}

void insertarElemento(colaP& cp, int x, int prioridad) {
    nodoCP* nuevoNodo = new nodoCP;
    nuevoNodo->elemento = x;
    nuevoNodo->prioridad = prioridad;
    nuevoNodo->sig = NULL;

    if (cp == NULL || nuevoNodo->prioridad < cp->prioridad) {
        nuevoNodo->sig = cp;
        cp = nuevoNodo;
    } else {
        colaP aux = cp;
        while (aux->sig != NULL && aux->sig->prioridad < nuevoNodo->prioridad) {
            aux = aux->sig;
        }
        nuevoNodo->sig = aux->sig;
        aux->sig = nuevoNodo;
    }
}

bool esColaVacia(colaP cp) {
    return cp == NULL;
}

bool estaDefinido(colaP cp, int x) {
    while (cp != NULL) {
        if (cp->elemento == x) return true;
        cp = cp->sig;
    }
    return false;
}

void borrar(colaP& cp, int x) {
    if (cp == NULL) return;

    if (cp->elemento == x) {
        nodoCP* aBorrar = cp;
        cp = cp->sig;
        delete aBorrar;
        return;
    }

    nodoCP* aux = cp;
    while (aux->sig != NULL) {
        if (aux->sig->elemento == x) {
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