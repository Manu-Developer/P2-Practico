#include <stdio.h>

struct nodoABB {
    int elem;
    nodoABB *izq, *der;
};

typedef nodoABB *ABB;

void insertarABB(ABB &arbol, int n) {
    if (arbol == NULL) {
        ABB nuevoNodo = new nodoABB;
        nuevoNodo->elem = n;
        nuevoNodo->der = NULL;
        nuevoNodo->izq = NULL;
    } else if (n < arbol->elem) {
        insertarABB(arbol->izq, n);
    } else {
        insertarABB(arbol->der, n);
    }
}

bool perteneceABB(ABB arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (n == arbol->elem) {
        return true;
    } else if (n < arbol->elem) {
        return perteneceABB(arbol->izq, n);
    } else {
        return perteneceABB(arbol->der, n);
    }
}

int maxABB(ABB arbol) {
    while (arbol->der != NULL) {
        arbol = arbol->der;
    }
    return arbol->elem;
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

void removerABB(ABB &arbol, int x) {
    if (arbol == NULL) return;

    if (x < arbol->elem) {
        removerABB(arbol->izq, x);
    } else if (x > arbol->elem) {
        removerABB(arbol->der, x);
    } else {
        // Nodo encontrado
        if (arbol->izq == NULL) {
            ABB aBorrar = arbol;
            arbol = arbol->der;
            delete aBorrar;
        } else if (arbol->der == NULL) {
            ABB aBorrar = arbol;
            arbol = arbol->izq;
            delete aBorrar;
        } else {
            // Nodo con dos hijos: buscar el predecesor (máximo en izq)
            arbol->elem = maxABB(arbol->izq);
            removerABB(arbol->izq, arbol->elem);
        }
    }
}

void kesimo_aux(ABB arbol, int k, int &cant, ABB &res) {
    if (arbol == NULL) {
        cant = 0;
    } else {
        kesimo_aux(arbol->izq, k, cant, res);
        if (cant == k - 1) {
            res = arbol;
            cant++;
        } else if (cant < k - 1) {
            int cantDer;
            kesimo_aux(arbol->der, k - cant - 1, cantDer, res);
            cant = cant + cantDer + 1;
        } else {
            cant++;
        }
    }
}

void kesimo_auxV2(ABB arbol, int k, ABB &res) {
    ABB res = NULL;
    if (arbol != NULL && k > 0) {
        kesimo_auxV2(arbol->izq, k, res);
        if (k > 0) {
            k--;
            if (k == 0) {
                res = arbol;
            } else {
                kesimo_auxV2(arbol->der, k, res);
            }
        }
    }
}

ABB kesimo(ABB arbol, int k) {
    ABB res = NULL;
    int cantidad;
    kesimo_aux(arbol, k, cantidad, res);
    return res;
}

int main() {
}