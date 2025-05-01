#include <stdio.h>

struct nodoAB {
    int elem;
    nodoAB *der;
    nodoAB *izq;
};

typedef nodoAB *AB;

AB crearNodo(int valor) {
    AB nuevo = new nodoAB;
    nuevo->elem = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

AB consArbol(int n, AB arbol1, AB arbol2) {
    AB nuevoArbol = new nodoAB;
    nuevoArbol->elem = n;
    nuevoArbol->izq = arbol1;
    nuevoArbol->der = arbol2;
    return nuevoArbol;
}

int contarElems(AB arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        return 1 + contarElems(arbol->izq) + contarElems(arbol->der);
    }
}

int contarHojas(AB arbol) {
    if (arbol == NULL) {
        return 0;
    } else if (arbol->der == NULL && arbol->izq == NULL) {
        return 1;
    } else {
        return contarHojas(arbol->izq) + contarHojas(arbol->der);
    }
}

int maximo(int n1, int n2) {
    if (n1 > n2)
        return n1;
    else
        return n2;
}

int altura(AB arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        return 1 + maximo(altura(arbol->izq), altura(arbol->der));
    }
}

AB copiar(AB arbol) {
    if (arbol == NULL) {
        return NULL;
    } else {
        AB copia = new nodoAB;
        copia->elem = arbol->elem;
        copia->der = copiar(arbol->der);
        copia->izq = copiar(arbol->izq);
        return copia;
    }
}

void liberarArbol(AB &arbol) {
    if (arbol == NULL) return;

    liberarArbol(arbol->izq);
    liberarArbol(arbol->der);
    delete arbol;
    arbol = NULL;
}

void preOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        printf("%d - ", arbol->elem);
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

int main() {
    // Crear las 8 hojas
    AB hoja1 = crearNodo(1);
    AB hoja2 = crearNodo(2);
    AB hoja3 = crearNodo(3);
    AB hoja4 = crearNodo(4);
    AB hoja5 = crearNodo(5);
    AB hoja6 = crearNodo(6);
    AB hoja7 = crearNodo(7);
    AB hoja8 = crearNodo(8);

    // Crear los nodos intermedios (nivel 2)
    AB nodo1 = crearNodo(9);
    nodo1->izq = hoja1;
    nodo1->der = hoja2;

    AB nodo2 = crearNodo(10);
    nodo2->izq = hoja3;
    nodo2->der = hoja4;

    AB nodo3 = crearNodo(11);
    nodo3->izq = hoja5;
    nodo3->der = hoja6;

    AB nodo4 = crearNodo(12);
    nodo4->izq = hoja7;
    nodo4->der = hoja8;

    // Crear los nodos del siguiente nivel (nivel 1)
    AB nodo5 = crearNodo(13);
    nodo5->izq = nodo1;
    nodo5->der = nodo2;

    AB nodo6 = crearNodo(14);
    nodo6->izq = nodo3;
    nodo6->der = nodo4;

    // Finalmente la raíz (nivel 0)
    AB raiz = crearNodo(15);
    raiz->izq = nodo5;
    raiz->der = nodo6;

    AB copiaArbol = copiar(raiz);

    preOrden(raiz);
    printf("\n");

    liberarArbol(raiz);
    preOrden(raiz);

    printf("\n");

    preOrden(copiaArbol);
}

/* ¿Comparte memoria con los parámetros?

Sí, la estructura que se construye con consArbol comparte memoria con los parámetros arbol1 y arbol2.

El nuevo nodo nuevoArbol no copia arbol1 ni arbol2, simplemente apunta a ellos.

Es decir, los subárboles no se duplican. Se enlazan tal como vienen.*/