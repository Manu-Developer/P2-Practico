#include <stdio.h>

struct nodo {
    int dato;
    nodo *anterior;
    nodo *siguiente;
};

struct listaDoble {
    nodo *primero;
    nodo *ultimo;
};

void insertarInicio(listaDoble &l, int dato) {
    nodo *nuevoNodo = new nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = l.primero;

    // Lista vacia
    if (l.primero == NULL) {
        l.ultimo = nuevoNodo;
    }
    // Lista no vacia
    else {
        l.primero->anterior = nuevoNodo;
    }
    l.primero = nuevoNodo;
}

void insertarUltimo(listaDoble &l, int dato) {
    nodo *nuevoNodo = new nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->anterior = l.ultimo;
    nuevoNodo->siguiente = NULL;

    // Lista vacia
    if (l.primero == NULL) {
        l.primero = nuevoNodo;
    }
    // Lista no vacia
    else {
        l.ultimo->siguiente = nuevoNodo;
    }
    l.ultimo = nuevoNodo;
}

void eliminarLista(listaDoble &l) {
    nodo *p, *auxiliar;
    p = l.primero;

    while (p != NULL) {
        auxiliar = p;
        p = p->siguiente;
        delete auxiliar;
    }
    l.primero = NULL;
    l.ultimo = NULL;
}

int main() {
}