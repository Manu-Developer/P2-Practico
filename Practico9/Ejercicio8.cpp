#include "../Practico9/Ejercicio8.h"

#include <stdio.h>

struct nodoArbol {
    int elemento;
    int cantidadRepeticiones;
    nodoArbol *izq;
    nodoArbol *der;
};

struct RepresentacionMultiset {
    int cantidadNodos;
    int elementoMin;
    int elementoMax;
    nodoArbol *arbol;
};

Multiset crear() {
    Multiset nuevoMultiSet = new RepresentacionMultiset;
    nuevoMultiSet->cantidadNodos = 0;
    nuevoMultiSet->elementoMin = 0;
    nuevoMultiSet->elementoMax = 0;
    nuevoMultiSet->arbol = NULL;
    return nuevoMultiSet;
}

void insertarNodo(nodoArbol *&raiz, int x, int n) {
    if (raiz == NULL) {
        raiz = new nodoArbol;
        raiz->elemento = x;
        raiz->cantidadRepeticiones = n;
        raiz->izq = NULL;
        raiz->der = NULL;
    } else if (x == raiz->elemento) {
        raiz->cantidadRepeticiones += n;
    } else if (x < raiz->elemento) {
        insertarNodo(raiz->izq, x, n);
    } else {
        insertarNodo(raiz->der, x, n);
    }
}

void insertar(Multiset &m, int x, int n) {
    if (m->arbol == NULL) {
        m->elementoMin = x;
        m->elementoMax = x;
        m->cantidadNodos++;
    } else {
        int antes = ocurrencias(m, x);
        if (x < m->elementoMin) m->elementoMin = x;
        if (x > m->elementoMax) m->elementoMax = x;
        if (antes == 0) m->cantidadNodos++;
    }

    insertarNodo(m->arbol, x, n);
}

int cantidad(Multiset m) {
    return m->cantidadNodos;
}

int ocurrenciasNodo(nodoArbol *raiz, int x) {
    if (raiz == NULL)
        return 0;

    if (x == raiz->elemento) {
        return raiz->cantidadRepeticiones;
    } else if (x < raiz->elemento) {
        return ocurrenciasNodo(raiz->izq, x);
    } else {
        return ocurrenciasNodo(raiz->der, x);
    }
}

int ocurrencias(Multiset m, int x) {
    return ocurrenciasNodo(m->arbol, x);
}

int maxABB(nodoArbol *raiz) {
    while (raiz->der != NULL) {
        raiz = raiz->der;
    }
    return raiz->elemento;
}

int minABB(nodoArbol *raiz) {
    while (raiz->izq != NULL) {
        raiz = raiz->izq;
    }
    return raiz->elemento;
}

// La funcion eliminarArbol no esta bien implementada.
void eliminarArbol(nodoArbol *&t, int elemento, int ocurrencias) {
    if (t == NULL) return;

    if (elemento < t->elemento) {
        eliminarArbol(t->izq, elemento, ocurrencias);
    } else if (elemento > t->elemento) {
        eliminarArbol(t->der, elemento, ocurrencias);
    } else {
        // Nodo encontrado
        if (t->izq == NULL) {
            nodoArbol *aBorrar = t;
            t = t->der;
            delete aBorrar;
        } else if (t->der == NULL) {
            nodoArbol *aBorrar = t;
            t = t->izq;
            delete aBorrar;
        } else {
            // Nodo con dos hijos: buscar el predecesor (máximo en izq)
            t->elemento = maxABB(t->izq);
            eliminarArbol(t->izq, t->elemento, ocurrencias);
        }
    }
}

void eliminar(Multiset &m, int x, int n) {
    eliminarArbol(m->arbol, x, n);
}

int min(Multiset m) {
    return m->elementoMin;
}

int max(Multiset m) {
    return m->elementoMax;
}

void liberarArbol(nodoArbol *arbol) {
    if (arbol != NULL) {
        liberarArbol(arbol->izq);
        liberarArbol(arbol->der);
        delete arbol;
        arbol = NULL;
    }
}

void vaciar(Multiset &m) {
    liberarArbol(m->arbol);
    m->arbol = NULL;
    m->cantidadNodos = 0;
    m->elementoMin = 0;
    m->elementoMax = 0;
}