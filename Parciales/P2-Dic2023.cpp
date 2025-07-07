#include "../Parciales/P2-Dic2023.h"

#include <stdio.h>

nat min(nat num1, nat num2);
nat max(nat num1, nat num2);

Tabla preciosUnicos(Tabla t1, Tabla t2) {
    Tabla res = crear();
    nat inf = min(minDomino(t1), minDomino(t2));
    nat sup = max(maxDominio(t1), maxDominio(t2));

    for (int i = inf; i <= sup; i++) {
        if (definida(i, t1) && definida(i, t2) && recuperar(i, t1) == recuperar(i, t2)) {
            insertar(i, recuperar(i, t1), res);
        } else if (definida(i, t1)) {
            insertar(i, recuperar(i, t1), res);
        } else {
            insertar(i, recuperar(i, t2), res);
        }
    }

    return res;
}

struct nodoABB {
    nat dom;
    float img;
    nodoABB* izq;
    nodoABB* der;
};

struct RepTabla {
    int cantElems;
    nodoABB* tabla;
    nodoABB* minDom;
    nodoABB* maxDom;
};

Tabla crear() {
    Tabla t = new RepTabla;
    t->cantElems = 0;
    t->tabla = NULL;
    t->minDom = NULL;
    t->maxDom = NULL;
    return t;
}

nodoABB* insertarABB(nat d, float c, nodoABB*& raiz) {
    if (raiz == NULL) {
        raiz = new nodoABB;
        raiz->dom = d;
        raiz->img = c;
        raiz->der = NULL;
        raiz->izq = NULL;
        return raiz;
    } else if (raiz->dom == d) {
        raiz->img = c;
        return NULL;
    } else if (d < raiz->dom) {
        return insertarABB(d, c, raiz->izq);
    } else {
        return insertarABB(d, c, raiz->der);
    }
}

void insertar(nat d, float c, Tabla& t) {
    nodoABB* insertado = insertarABB(d, c, t->tabla);
    if (insertado != NULL) {
        t->cantElems++;
        if (t->minDom == NULL || d < t->minDom->dom)
            t->minDom = insertado;
        if (t->maxDom == NULL || d > t->maxDom->dom)
            t->maxDom = insertado;
    }
}

void impCorrespondencia();

void imprimirABB(nodoABB* raiz) {
    if (raiz == NULL) return;

    imprimirABB(raiz->der);
    impCorrespondencia();
    imprimirABB(raiz->izq);
}

void imprimir(Tabla t) {
    imprimirABB(t->tabla);
}