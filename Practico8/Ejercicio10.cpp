#include "./Practico8/Ejercicio10.h"

#include <stdio.h>

struct nodo_lista {
    int dato;
    nodo_lista *sig;
};

struct rep_conjunto {
    int cota;
    int cantidad;
    bool *elementos;
};

conjunto crearConjunto(int cota) {
    conjunto nuevoConjunto = new rep_conjunto;
    nuevoConjunto->cota = cota;
    nuevoConjunto->cantidad = 0;
    nuevoConjunto->elementos = new bool[cota + 1];
    for (int i = 0; i <= cota; i++) {
        nuevoConjunto->elementos[i] = false;
    }
    return nuevoConjunto;
}

void insertarElemento(conjunto &c, int x) {
    if (c->cantidad < c->cota && c->elementos[x] == false) {
        c->elementos[x] = true;
        c->cantidad++;
    }
}

void eliminarConjunto(conjunto &c, int x) {
    if (c->elementos[x] == true) {
        c->elementos[x] = false;
        c->cantidad--;
    }
}

bool pertenece(conjunto c, int x) {
    return c->elementos[x];
}

void destruirConjunto(conjunto &c) {
    delete[] c->elementos;
    delete c;
    c = NULL;
}

int max(int numero1, int numero2) {
    if (numero1 > numero2) {
        return numero1;
    } else {
        return numero2;
    }
}

// Encuentra el valor máximo en una lista
int encontrarMaximo(lista l) {
    int maximo = 0;
    while (l != NULL) {
        if (l->dato > maximo) {
            maximo = l->dato;
        }
        l = l->sig;
    }
    return maximo;
}

lista interseccionListas(lista l1, lista l2) {
    // Obtener el máximo valor en ambas listas
    int max1 = encontrarMaximo(l1);
    int max2 = encontrarMaximo(l2);
    int cota = max(max1, max2);

    conjunto l1_conjunto = crearConjunto(cota);
    conjunto l2_conjunto = crearConjunto(cota);

    // Insertar elementos de l1 en l1_conjunto
    lista p1 = l1;
    while (p1 != NULL) {
        insertarElemento(l1_conjunto, p1->dato);
        p1 = p1->sig;
    }

    // Insertar elementos de l2 en l2_conjunto
    lista p2 = l2;
    while (p2 != NULL) {
        insertarElemento(l2_conjunto, p2->dato);
        p2 = p2->sig;
    }

    // Crear lista resultado con elementos comunes
    lista resultado = crearLista();

    for (int i = 0; i <= cota; i++) {
        if (pertenece(l1_conjunto, i) && pertenece(l2_conjunto, i)) {
            insertar(resultado, i);  // Inserta al principio
        }
    }

    // Liberar memoria
    destruirConjunto(l1_conjunto);
    destruirConjunto(l2_conjunto);

    return resultado;
}