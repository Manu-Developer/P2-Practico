#include <stdio.h>

struct nodoLista {
    int dato;
    nodoLista* sig;
    nodoLista* ant;
};

struct cabezal {
    nodoLista* inicio;
    nodoLista* final;
};

typedef cabezal* Lista;

struct nodoABB {
    float dato;
    nodoABB *izq, *der;
};

typedef nodoABB* ABB;

void insFinal(int x, Lista& l) {
    nodoLista* nuevo = new nodoLista;
    nuevo->dato = x;
    nuevo->sig = NULL;
    if (l->inicio == NULL) {
        l->inicio = nuevo;
        nuevo->ant = NULL;
    } else {
        nuevo->ant = l->final;
        l->final->sig = nuevo;
    }
    l->final = nuevo;
}

int borrarMayores(float x, ABB& t) {
    int result = 0;
    if (t != NULL) {
        if (t->dato > x) {
            result = 1 + borrarMayores(x, t->izq) + borrarMayores(x, t->der);
            ABB aBorrar = t;
            t = t->izq;
            delete aBorrar;
        } else
            result = borrarMayores(x, t->der);
    }
    return result;
}