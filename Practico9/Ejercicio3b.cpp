#include <stdio.h>

#include "../Practico9/Ejercicio3a.h"

// Podria ser un AVL, pero la complejidad de este ejercicio de Examen seria excesiva.

struct nodoArbol {
    int dominio;
    float codominio;
    nodoArbol* izq;
    nodoArbol* der;
};

arbol crearArbol() {
    arbol nuevoArbol = NULL;
    return nuevoArbol;
}

arbol recuperarNodo(arbol t, int d) {
    if (t == NULL) {
        return NULL;
    } else if (d == t->dominio) {
        arbol nodoRecuperado = t;
        return nodoRecuperado;
    } else if (d < t->dominio) {
        return recuperarNodo(t->izq, d);
    } else {
        return recuperarNodo(t->der, d);
    }
}

bool perteneceArbol(arbol t, int d) {
    if (t == NULL) {
        return false;
    } else if (d == t->dominio) {
        return true;
    } else if (d < t->dominio) {
        return perteneceArbol(t->izq, d);
    } else {
        return perteneceArbol(t->der, d);
    }
}

void insertarArbol(arbol& t, int d, int c) {
    if (t == NULL) {
        t = new nodoArbol;
        t->dominio = d;
        t->codominio = c;
        t->der = NULL;
        t->izq = NULL;
    } else if (t->dominio == d) {
        t->codominio = c;
    } else if (d < t->dominio) {
        insertarArbol(t->izq, d, c);
    } else {
        insertarArbol(t->der, d, c);
    }
}

int maxABB(arbol t) {
    while (t->der != NULL) {
        t = t->der;
    }
    return t->dominio;
}

void eliminarArbol(arbol& t, int d) {
    if (t == NULL) return;

    if (d < t->dominio) {
        eliminarArbol(t->izq, d);
    } else if (d > t->dominio) {
        eliminarArbol(t->der, d);
    } else {
        // Nodo encontrado
        if (t->izq == NULL) {
            nodoArbol* aBorrar = t;
            t = t->der;
            delete aBorrar;
        } else if (t->der == NULL) {
            nodoArbol* aBorrar = t;
            t = t->izq;
            delete aBorrar;
        } else {
            // Nodo con dos hijos: buscar el predecesor (máximo en izq)
            t->dominio = maxABB(t->izq);
            eliminarArbol(t->izq, t->dominio);
        }
    }
}

void liberarArbol(arbol& t) {
    if (t == NULL) return;

    liberarArbol(t->izq);
    liberarArbol(t->der);
    delete t;
    t = NULL;
}