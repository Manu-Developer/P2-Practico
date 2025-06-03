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

// Opcion de un repositorio externo:

/*

# include <stdio.h>

typedef unsigned int nat;

struct nodo_AVL {
    int value;
    nat height;
    nodo_AVL *left, *right;
};
typedef nodo_AVL * TAVL;

TAVL buscar(int val, TAVL avl) {
    while (avl != NULL && avl->value != val)
        if (avl->value > val)
            avl = avl->left;
        else
            avl = avl->right;
    return avl;
}

nat altura(TAVL avl) {
    if (avl == NULL)
        return 0;
    else
        return avl->height;
}

// Precondición: avl != NULL
nat nuevaAltura(TAVL avl) {
    nat hl = altura(avl->left);
    nat hr = altura(avl->right);
    return ((hl > hr) ? hl : hr) + 1;
}

// Precondición: avl != NULL && avl->right != NULL
TAVL rotarL(TAVL avl) {
    TAVL aux = avl->left;
    avl->left = aux->right;
    aux->right = avl;
    avl->height = nuevaAltura(avl);
    aux->height = nuevaAltura(aux);
    return aux;
}

// Precondición: avl != NULL && avl->right != NULL
TAVL rotarR(TAVL avl) {
    TAVL aux = avl->right;
    avl->right = aux->left;
    aux->left = avl;
    avl->height = nuevaAltura(avl);
    aux->height = nuevaAltura(aux);
    return aux;
}

// Precondición: avl != NULL && avl->left != NULL && * avl->left->right != NULL
TAVL rotarLR(TAVL avl) {
    avl->left = rotarR(avl->left);
    return rotarL(avl);
}

// Precondición: avl != NULL && avl->right != NULL %% avl->rigth->left != NULL
TAVL rotarRL(TAVL avl) {
    avl->right = rotarL(avl->right);
    return rotarR(avl);
}

// Precondición: avl != NULL
TAVL balancear(TAVL avl) {
    nat hl = altura(avl->left);
    nat hr = altura(avl->right);
    if (hl - hr < 2 && hr - hl < 2)
        avl->height = nuevaAltura(avl);
    else if (hl > hr)
        if (altura(avl->left->left) > altura(avl->left->right))
            rotarL(avl);
        else
            rotarLR(avl);
    else if (altura(avl->right->right) > altura(avl->right->left))
        rotarR(avl);
    else
        rotarRL(avl);
    return avl;
}

TAVL insertar(int val, TAVL avl) {
    if (avl == NULL) {
        avl = new nodo_AVL;
        avl->value = val;
        avl->height = 1;
        avl->left = avl->right = NULL;
        return avl;
    } else if (avl->value == val)
        return avl;
    else if (avl->value > val)
        avl->left = insertar(val, avl->left);
    else
        avl->right = insertar(val, avl->right);
    return balancear(avl);
}

// Precondición: avl != NULL
TAVL buscarBorrarMax(TAVL avl, int &max) {
    if (avl->right == NULL) {
        TAVL aux = avl->left;
        max = avl->value;
        delete avl;
        return aux;
    } else {
        avl->right = buscarBorrarMax(avl->right, max);
        return balancear(avl);
    }
}

TAVL borrar(int val, TAVL avl) {
    if (avl == NULL)
        return avl;
    else if (avl->value == val)
        if (avl->left == NULL) {
            TAVL aux = avl->right;
            delete avl;
            return aux;
        } else if (avl->right == NULL) {
            TAVL aux = avl->left;
            delete avl;
            return aux;
        } else {
            int max;
            avl->left = buscarBorrarMax(avl->left, max);
            avl->value = max;
        }
    else if (avl->value > val)
        avl->left = borrar(val, avl->left);
    else
        avl->right = borrar(val, avl->right);
    return balancear(avl);
}
*/
