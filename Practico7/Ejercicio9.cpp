#include "../Practico7/Ejercicio9.h"

#include <stdio.h>

struct nodo {
    AB valor;
    nodo* sig;
};

struct nodoAB {
    int valor;
    nodoAB* izq;
    nodoAB* der;
};

struct rep_cola {
    nodo* primero;
    nodo* ultimo;
    int cantidad;
};

Cola crearCola() {
    Cola colaNueva = new rep_cola;
    colaNueva->primero = colaNueva->ultimo = NULL;
    return colaNueva;
}

bool esVaciaCola(Cola c) {
    return c->primero == NULL;
}

void encolar(AB t, Cola& c) {
    nodo* nuevo = new nodo;
    nuevo->valor = t;
    nuevo->sig = NULL;
    if (c->primero == NULL)
        c->primero = nuevo;
    else
        c->ultimo->sig = nuevo;
    c->ultimo = nuevo;
}

void desencolar(Cola& c) {
    nodo* aBorrar = c->primero;
    c->primero = c->primero->sig;
    if (c->primero == NULL) {
        c->ultimo = NULL;
    }
    delete aBorrar;
}

void destruirCola(Cola& c) {
    while (!esVaciaCola(c)) {
        desencolar(c);
    }
    delete c;
}

AB frente(Cola c) {
    return c->primero->valor;
}

AB nuevoNodo(int valor) {
    AB nodo = new nodoAB;
    nodo->valor = valor;
    nodo->izq = nodo->der = NULL;
    return nodo;
}

void imprimirPorNiveles(AB arbol) {
    if (arbol != NULL) {
        Cola q = crearCola();
        encolar(arbol, q);

        while (!esVaciaCola(q)) {
            arbol = frente(q);
            desencolar(q);
            printf("%d ", arbol->valor);

            if (arbol->izq != NULL) {
                encolar(arbol->izq, q);
            }

            if (arbol->der != NULL) {
                encolar(arbol->der, q);
            }
        }

        destruirCola(q);
    }
}

void imprimirPorNivelesV2(AB arbol) {
    if (arbol != NULL) {
        Cola q = crearCola();
        encolar(arbol, q);
        encolar(NULL, q);
        int nivel = 1;
        printf("%d - ", nivel);

        while (!esVaciaCola(q)) {
            arbol = frente(q);
            desencolar(q);
            if (arbol != NULL) {
                printf("%d ", arbol->valor);
                if (arbol->izq != NULL) {
                    encolar(arbol->izq, q);
                }
                if (arbol->der != NULL) {
                    encolar(arbol->der, q);
                }
            } else if (!esVaciaCola(q)) {
                nivel++;
                printf("\n");
                printf("%d - ", nivel);
                encolar(NULL, q);
            }
        }
        destruirCola(q);
    }
}

void imprimirPorNivelesV3(AB arbol) {
    if (arbol != NULL) {
        Cola q = crearCola();
        // PilaNat p = crearPila();
        encolar(arbol, q);

        while (!esVaciaCola(q)) {
            arbol = frente(q);
            desencolar(q);
            // apilar(p, arbol->valor);

            if (arbol->izq != NULL) {
                encolar(arbol->izq, q);
            }

            if (arbol->der != NULL) {
                encolar(arbol->der, q);
            }
        }

        destruirCola(q);

        // while (!esVaciaPila(p)) {
        //   printf("%d ", tope(p));
        // desapilar(p);
        //}
        // destruirPila(p);
    }
}

int main() {
    // Crear árbol binario de prueba
    //
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    AB raiz = nuevoNodo(1);
    raiz->izq = nuevoNodo(2);
    raiz->der = nuevoNodo(3);
    raiz->izq->izq = nuevoNodo(4);
    raiz->izq->der = nuevoNodo(5);
    raiz->der->der = nuevoNodo(6);

    printf("Impresión por niveles del árbol:\n");
    imprimirPorNivelesV2(raiz);
    printf("\n");

    // Liberar memoria (simplificado, sin recorrer todo el árbol)
    delete raiz->izq->izq;
    delete raiz->izq->der;
    delete raiz->der->der;
    delete raiz->izq;
    delete raiz->der;
    delete raiz;

    return 0;
}