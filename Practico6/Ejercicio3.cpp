#include <stdio.h>

struct nodoAB {
    int dato;
    nodoAB *derecha;
    nodoAB *izquierda;
    nodoAB *padre;
};

typedef nodoAB *AB;

void preOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        printf("%d - ", arbol->dato);
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}

void inOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        inOrden(arbol->izquierda);
        printf("%d - ", arbol->dato);
        inOrden(arbol->derecha);
    }
}

void postOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        inOrden(arbol->izquierda);
        inOrden(arbol->derecha);
        printf("%d - ", arbol->dato);
    }
}

// T(n) = d (Si n<=1 d es una constante)
// T(n) = T(n-1)+c (Si n>1 c es una constante)

// Expandiendo por recurrencia:

// T(n) = T(n-1)+c = T(n-2)+2c = T(n-3)+3c = ... = T(n-i)+ic (Si n>i)

// Caso Base (i=n-1):

// T(n) = T(1) + (n-1)c = T(1) + nc -c = d + nc - c

// Entonces T(n) es O(n) en todos los casos