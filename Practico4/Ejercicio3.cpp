#include <stdio.h>

struct nodo_doble {
    int elemento;
    nodo_doble* siguiente;
    nodo_doble* anterior;
};

typedef nodo_doble* lista;

void imprimirLista(lista l) {
    lista auxiliarLista = l;

    if (l == NULL) {
        printf("Lista vacia\n");
        return;
    }

    printf("Lista: ");

    while (auxiliarLista != NULL) {
        printf("%d ", auxiliarLista->elemento);
        auxiliarLista = auxiliarLista->siguiente;
    }

    printf("\n");
}

lista listaVacia() {
    lista listaVacia = NULL;
    return listaVacia;
}

bool estaVacia(lista l) {
    return l == NULL;
}

lista insertarInicio(lista& l, int x) {
    lista nuevoNodo = new nodo_doble;
    nuevoNodo->elemento = x;

    if (l == NULL) {
        l = nuevoNodo;
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = NULL;
        return nuevoNodo;
    } else {
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = l;
        l->anterior = nuevoNodo;
        l = nuevoNodo;
        return nuevoNodo;
    }
}

bool esElemento(lista l, int x) {
    bool esElemento = false;

    while (l != NULL && !esElemento) {
        if (l->elemento == x) {
            esElemento = true;
        }
        l = l->siguiente;
    }

    return esElemento;
}

void removerOcurrencias(lista& l, int x) {
    // Eliminar nodos al inicio
    while (l != NULL && l->elemento == x) {
        lista temp = l;
        l = l->siguiente;
        if (l != NULL) l->anterior = NULL;
        delete temp;
    }

    // Eliminar nodos en el resto de la lista
    lista actual = l;
    while (actual != NULL) {
        if (actual->elemento == x) {
            lista anterior = actual->anterior;
            lista siguiente = actual->siguiente;

            if (anterior != NULL) anterior->siguiente = siguiente;
            if (siguiente != NULL) siguiente->anterior = anterior;

            delete actual;
            actual = siguiente;
        } else {
            actual = actual->siguiente;
        }
    }
}

void insertarOrdenado(int x, lista& l) {
    nodo_doble* nuevo = new nodo_doble;
    nuevo->elemento = x;

    if (l == NULL || l->elemento >= x) {
        nuevo->siguiente = l;

        if (l != NULL) {
            l->anterior = nuevo;
        }

        l = nuevo;
        nuevo->anterior = NULL;
    } else {
        nodo_doble* iterador = l;

        while (iterador->siguiente != NULL && iterador->siguiente->elemento < x) {
            iterador = iterador->siguiente;
        }

        nuevo->siguiente = iterador->siguiente;
        nuevo->anterior = iterador;

        if (iterador->siguiente != NULL) {
            iterador->siguiente->anterior = nuevo;
        }

        iterador->siguiente = nuevo;
    }
}

void removerUltimo(lista& l) {
    if (l != NULL) {
        lista aux = l;
        while (aux->siguiente != NULL) {
            aux = aux->siguiente;
        }

        if (aux->anterior == NULL) {
            // Solo hay un nodo
            delete aux;
            l = NULL;
        } else {
            aux->anterior->siguiente = NULL;
            delete aux;
        }
    }
}

int main() {
    lista primero = new nodo_doble;
    lista segundo = new nodo_doble;
    lista tercero = new nodo_doble;
    lista cuarto = new nodo_doble;
    lista quinto = new nodo_doble;

    primero->elemento = 100;
    primero->anterior = NULL;
    primero->siguiente = segundo;
    segundo->elemento = 200;
    segundo->anterior = primero;
    segundo->siguiente = tercero;
    tercero->elemento = 300;
    tercero->anterior = segundo;
    tercero->siguiente = cuarto;
    cuarto->elemento = 400;
    cuarto->anterior = tercero;
    cuarto->siguiente = quinto;
    quinto->elemento = 500;
    quinto->anterior = cuarto;
    quinto->siguiente = NULL;

    imprimirLista(primero);
    removerUltimo(primero);
    imprimirLista(primero);

    return 0;
}