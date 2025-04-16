#include <math.h>
#include <stdio.h>

struct nodoAB {
    int elem;
    nodoAB *izq, *der;
};

typedef nodoAB* AB;

AB crearNodo(int valor) {
    AB nuevo = new nodoAB;
    nuevo->elem = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    return nuevo;
}

AB copiar(AB arbol) {
    if (arbol == NULL) return NULL;

    AB copia = new nodoAB;
    copia->elem = arbol->elem;
    copia->der = copiar(arbol->der);
    copia->izq = copiar(arbol->izq);
    return copia;
}

void liberarArbol(AB& arbol) {
    if (arbol == NULL) return;

    liberarArbol(arbol->izq);
    liberarArbol(arbol->der);
    delete arbol;
    arbol = NULL;
}

bool esPerfecto(AB arbol, int h) {
    if (arbol == NULL) return false;

    // Caso base: si estamos en altura 1, debe ser una hoja
    if (h == 1) {
        return (arbol->izq == NULL && arbol->der == NULL);
    }

    // Si uno de los hijos falta, no es perfecto
    if (arbol->izq == NULL || arbol->der == NULL) return false;

    // Ambos hijos deben ser perfectos con altura h
    return esPerfecto(arbol->izq, h - 1) && esPerfecto(arbol->der, h - 1);
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
}