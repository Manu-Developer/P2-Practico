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

// Se puede refactorizar aun mas.
void insertarInicio(lista& l, int x) {
    lista nuevoNodo = new nodo_doble;
    nuevoNodo->elemento = x;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = l;

    if (l == NULL) {
        l = nuevoNodo;
    } else {
        l->anterior = nuevoNodo;
        l = nuevoNodo;
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
    lista lPosicion, aBorrar = l;

    while (lPosicion != NULL) {
        if (lPosicion->elemento == x) {
            aBorrar = lPosicion;

            if (lPosicion->anterior != NULL) {
                lPosicion->anterior->siguiente = lPosicion->siguiente;
            } else {
                l = lPosicion->siguiente;
            }

            if (lPosicion->siguiente != NULL) {
                lPosicion->siguiente->anterior = lPosicion->anterior;
            }

            lPosicion = lPosicion->siguiente;
            delete aBorrar;
        } else {
            lPosicion = lPosicion->siguiente;
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