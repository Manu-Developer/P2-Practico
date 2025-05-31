#include <stdio.h>

struct nodoAVL {
    int dato;
    int altura;
    nodoAVL *izq, *der;
};

typedef struct nodoAVL *arbolAVL;

bool buscarAVL(arbolAVL a, int x) {
    if (a == NULL) {
        return false;
    } else if (a->dato == x) {
        return true;
    } else if (x < a->dato) {
        return buscarAVL(a->izq, x);
    } else {
        return buscarAVL(a->der, x);
    }
}

int alturaAVL(arbolAVL arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        return arbol->altura;
    }
}

int max(int n1, int n2) {
    if (n1 > n2) {
        return n1;
    } else {
        return n2;
    }
}

void rotarDerecha(arbolAVL &a) {
    nodoAVL *y = a->izq;
    nodoAVL *aux = y->der;

    y->der = a;
    a->izq = aux;

    a->altura = max(alturaAVL(a->izq), alturaAVL(a->der)) + 1;
    y->altura = max(alturaAVL(y->izq), alturaAVL(y->der)) + 1;

    a = y;
}

void rotarIzquierda(arbolAVL &a) {
    nodoAVL *y = a->der;
    nodoAVL *aux = y->izq;

    y->izq = a;
    a->der = aux;

    a->altura = max(alturaAVL(a->izq), alturaAVL(a->der)) + 1;
    y->altura = max(alturaAVL(y->izq), alturaAVL(y->der)) + 1;

    a = y;
}

void insertarAVL(int x, arbolAVL &arbol) {
    if (arbol == NULL) {
        arbol = new nodoAVL;
        arbol->dato = x;
        arbol->izq = NULL;
        arbol->der = NULL;
        arbol->altura = 1;
    } else {
        if (x < arbol->dato) {
            insertarAVL(x, arbol->izq);
            arbol->altura = max(alturaAVL(arbol->izq), alturaAVL(arbol->der)) + 1;

            int factorBalanceo = alturaAVL(arbol->izq) - alturaAVL(arbol->der);

            if (factorBalanceo > 1) {
                if (alturaAVL(arbol->izq->izq) > alturaAVL(arbol->izq->der)) {
                    rotarDerecha(arbol);
                } else {
                    rotarIzquierda(arbol->izq);
                    rotarDerecha(arbol);
                }
            }
        } else {
            insertarAVL(x, arbol->der);
            arbol->altura = max(alturaAVL(arbol->izq), alturaAVL(arbol->der)) + 1;

            int factorBalanceo = alturaAVL(arbol->izq) - alturaAVL(arbol->der);

            if (factorBalanceo < -1) {
                if (alturaAVL(arbol->der->der) > alturaAVL(arbol->der->izq)) {
                    rotarIzquierda(arbol);
                } else {
                    rotarDerecha(arbol->der);
                    rotarIzquierda(arbol);
                }
            }
        }
    }
}

void eliminarAVL(int x, arbolAVL &arbol) {
    if (arbol == NULL) return;

    if (x < arbol->dato) {
        eliminarAVL(x, arbol->izq);
    } else if (x > arbol->dato) {
        eliminarAVL(x, arbol->der);
    } else {
        // Nodo encontrado
        if (arbol->izq == NULL || arbol->der == NULL) {
            arbolAVL temp = arbol->izq ? arbol->izq : arbol->der;
            if (temp == NULL) {
                // Sin hijos
                delete arbol;
                arbol = NULL;
            } else {
                // Un hijo
                *arbol = *temp;
                delete temp;
            }
        } else {
            // Dos hijos: obtener el sucesor inmediato (mínimo del subárbol derecho)
            arbolAVL temp = arbol->der;
            while (temp->izq != NULL) temp = temp->izq;

            arbol->dato = temp->dato;
            eliminarAVL(temp->dato, arbol->der);
        }
    }

    if (arbol == NULL) return;

    // Actualizar altura
    arbol->altura = max(alturaAVL(arbol->izq), alturaAVL(arbol->der)) + 1;

    // Obtener factor de balanceo
    int balance = alturaAVL(arbol->izq) - alturaAVL(arbol->der);

    // Rebalancear si es necesario
    if (balance > 1) {
        if (alturaAVL(arbol->izq->izq) >= alturaAVL(arbol->izq->der)) {
            rotarDerecha(arbol);  // Caso LL
        } else {
            rotarIzquierda(arbol->izq);  // Caso LR
            rotarDerecha(arbol);
        }
    } else if (balance < -1) {
        if (alturaAVL(arbol->der->der) >= alturaAVL(arbol->der->izq)) {
            rotarIzquierda(arbol);  // Caso RR
        } else {
            rotarDerecha(arbol->der);  // Caso RL
            rotarIzquierda(arbol);
        }
    }
}