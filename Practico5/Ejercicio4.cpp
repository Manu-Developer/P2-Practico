#include <stdio.h>

struct EstInfo {
    int ci;    // clave
    int nota;  // dato
};

struct nodoABB {
    EstInfo info;
    nodoABB *izq, *der;
};

typedef nodoABB *ABB;

ABB maxABB(ABB arbol) {
    if (arbol == NULL) {
        return NULL;
    }

    while (arbol->der != NULL) {
        arbol = arbol->der;
    }
    return arbol;
}

void removerMaxABB(ABB &arbol) {
    if (arbol == NULL) return;

    // Si no hay subárbol derecho, este es el mayor
    if (arbol->der == NULL) {
        ABB temp = arbol;
        arbol = arbol->izq;  // El hijo izquierdo pasa a ocupar el lugar
        delete temp;
    } else {
        removerMaxABB(arbol->der);  // Recorremos hasta el nodo más derecho
    }
}

// Devuelve un árbol con los elementos de 'b' en los que " nota " es mayor que " cota ".
ABB filtrado(ABB arbol, int cota) {
    ABB resultado;
    if (arbol == NULL) {
        resultado = NULL;
    } else {
        ABB fIzq = filtrado(arbol->izq, cota);
        ABB fDer = filtrado(arbol->der, cota);

        EstInfo raiz = arbol->info;

        if (raiz.nota > cota) {
            resultado = new nodoABB;
            resultado->info = raiz;
            resultado->izq = fIzq;
            resultado->der = fDer;
        } else if (fIzq == NULL) {
            resultado = fDer;
        } else if (fDer == NULL) {
            resultado = fIzq;
        } else {
            ABB mayor = maxABB(fIzq);
            resultado = new nodoABB;
            resultado->info = mayor->info;
            resultado->izq = fIzq;
            resultado->der = fDer;
            removerMaxABB(fIzq);
        }
    }
    return resultado;
}