#include <stdio.h>

struct nodoLista {
    int dato;
    nodoLista *sig;
};

typedef nodoLista *Lista;

struct nodoAB {
    int dato;
    nodoAB *izq, *der;
};

typedef struct nodoAB *AB;

bool sinRepetidos(Lista l, int p) {
    int arregloAux[p + 1];

    for (int i = 0; i <= p; i++) {
        arregloAux[i] = 0;
    }

    while (l != NULL) {
        arregloAux[l->dato]++;
        l = l->sig;
    }

    for (int i = 0; i <= p; i++) {
        if (arregloAux[i] > 1) {
            return false;  // hay repetidos
        }
    }

    return true;  // no hay repetidos
}

bool sinRepetidos(Lista l, int p) {
    bool *Pertenece = new bool[p + 1];

    for (int i = 0; i < p + 1; i++)
        Pertenece[i] = false;

    while (l != NULL && !Pertenece[l->dato]) {
        Pertenece[l->dato] = true;
        l = l->sig;
    }

    delete[] Pertenece;
    return (l == NULL);
}

AB maximo(AB t) {
    if (t == NULL) return NULL;

    AB maxIzq = maximo(t->izq);
    AB maxDer = maximo(t->der);

    AB maxNodo = t;

    if (maxIzq != NULL && maxIzq->dato > maxNodo->dato) {
        maxNodo = maxIzq;
    }
    if (maxDer != NULL && maxDer->dato > maxNodo->dato) {
        maxNodo = maxDer;
    }

    return maxNodo;
}

AB maximo(AB t) {
    if (t == NULL)
        return NULL;
    else {
        AB nodoMax = t;  // inicializamos con la raíz
        AB nodoMaxRec = maximo(t->izq);

        if (nodoMaxRec != NULL && nodoMaxRec->dato > nodoMax->dato)
            nodoMax = nodoMaxRec;  // se considera el max de t->izq

        nodoMaxRec = maximo(t->der);

        if (nodoMaxRec != NULL && nodoMaxRec->dato > nodoMax->dato)
            nodoMax = nodoMaxRec;  // se considera el max de t->der

        return nodoMax;
    }
}