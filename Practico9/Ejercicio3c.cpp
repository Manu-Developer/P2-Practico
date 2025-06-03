#include <stdio.h>

#include "../Practico9/Ejercicio3a.h"

// Podria ser un AVL, pero la complejidad de este ejercicio de Examen seria excesiva.

struct tabla {
    arbol nodoRaiz;
    int cantidadElementos;
};

typedef struct tabla* tablaRaiz;

tablaRaiz crearTabla() {
    tablaRaiz nuevaTabla = new tabla;
    nuevaTabla->cantidadElementos = 0;
    nuevaTabla->nodoRaiz = NULL;
    return nuevaTabla;
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

bool insertarArbol(arbol& t, int d, float c) {
    if (t == NULL) {
        t = new nodoArbol;
        t->dominio = d;
        t->codominio = c;
        t->der = NULL;
        t->izq = NULL;
        return true;
    } else if (t->dominio == d) {
        t->codominio = c;
        return false;
    } else if (d < t->dominio) {
        return insertarArbol(t->izq, d, c);
    } else {
        return insertarArbol(t->der, d, c);
    }
}

void insertar(tablaRaiz t, int d, float c) {
    if (insertarArbol(t->nodoRaiz, d, c)) {
        t->cantidadElementos++;
    }
}

int maxABB(arbol t) {
    while (t->der != NULL) {
        t = t->der;
    }
    return t->dominio;
}

bool eliminarArbolv2(arbol& t, int d) {
    if (t == NULL) return false;

    if (d < t->dominio) {
        return eliminarArbolv2(t->izq, d);
    } else if (d > t->dominio) {
        return eliminarArbolv2(t->der, d);
    } else {
        // Nodo encontrado
        if (t->izq == NULL) {
            nodoArbol* aBorrar = t;
            t = t->der;
            delete aBorrar;
            return true;
        } else if (t->der == NULL) {
            nodoArbol* aBorrar = t;
            t = t->izq;
            delete aBorrar;
            return true;
        } else {
            // Nodo con dos hijos: buscar el predecesor (máximo en izq)
            t->dominio = maxABB(t->izq);
            return eliminarArbolv2(t->izq, t->dominio);
        }
    }
}

void eliminar(tablaRaiz t, int d) {
    if (eliminarArbolv2(t->nodoRaiz, d)) {
        t->cantidadElementos--;
    }
}

void liberarArbol(arbol& t) {
    if (t == NULL) return;

    liberarArbol(t->izq);
    liberarArbol(t->der);
    delete t;
    t = NULL;
}

void liberarTablaRaiz(tablaRaiz t) {
    if (t == NULL) return;
    liberarArbol(t->nodoRaiz);
    delete t;
    t = NULL;
}