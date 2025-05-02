#include <stdio.h>

struct nodo {
    int elemento;
    nodo *siguiente;
};

typedef nodo *lista;

lista ultimo(lista l) {
    lista auxiliar = l;
    while (auxiliar->siguiente != NULL) {
        auxiliar = auxiliar->siguiente;
    }
    return auxiliar;
}

int promedio(lista l) {
    int promedio = 0;
    int contadorNodos;

    while (l != NULL) {
        promedio = promedio + l->elemento;
        contadorNodos++;
        l = l->siguiente;
    }

    return promedio / contadorNodos;
}

void insertarOrdenado(int x, lista &l) {
    lista nuevoNodo = new nodo;
    nuevoNodo->elemento = x;

    if (l == NULL || l->elemento >= x) {
        nuevoNodo->siguiente = l;
        l = nuevoNodo;
    } else {
        lista auxiliarLista = l;
        while (auxiliarLista->siguiente != NULL && auxiliarLista->siguiente->elemento < x) {
            auxiliarLista = auxiliarLista->siguiente;
        }
        nuevoNodo->siguiente = auxiliarLista->siguiente;
        auxiliarLista->siguiente = nuevoNodo;
    }
}

void insertarOrdenadoV2(int x, lista &l) {
    if (l == NULL || l->elemento >= x) {
        lista nuevo = new nodo;
        nuevo->elemento = x;
        nuevo->siguiente = l;
        l = nuevo;
    } else {
        insertarOrdenadoV2(x, l->siguiente);
    }
}

void insertarOrdenadoV3(int x, lista &l) {
    lista nuevoNodo = new nodo;
    nuevoNodo->elemento = x;
    nuevoNodo->siguiente = NULL;

    lista dummy = new nodo;
    dummy->siguiente = l;
    l = dummy;

    while (l->siguiente != NULL && l->siguiente->elemento < x) {
        l = l->siguiente;
    }
    nuevoNodo->siguiente = l->siguiente;
    l->siguiente = nuevoNodo;

    l = dummy->siguiente;
    delete dummy;
}

void insertarFinal(lista &l, int x) {
    lista nuevoNodo = new nodo;
    nuevoNodo->elemento = x;
    nuevoNodo->siguiente = NULL;

    if (l == NULL) {
        l = nuevoNodo;
    } else {
        lista auxiliar = l;
        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }
        auxiliar->siguiente = nuevoNodo;
    }
}

void removerOcurrencias(lista &l, int x) {
    // Caso especial: eliminar nodos desde el principio
    while (l != NULL && l->elemento == x) {
        lista temp = l;
        l = l->siguiente;
        delete temp;
    }

    // Remuevo el resto de elementos
    lista auxiliar = l;
    while (auxiliar != NULL && auxiliar->siguiente != NULL) {
        if (auxiliar->siguiente->elemento == x) {
            lista temp = auxiliar->siguiente;
            auxiliar->siguiente = auxiliar->siguiente->siguiente;
            delete temp;
        } else {
            auxiliar = auxiliar->siguiente;
        }
    }
}

bool esSubLista(lista l, lista p) {
    bool estaInculido = false;
    if (l == NULL) {
        return true;
    } else {
        while (p != NULL && !estaInculido) {
            while (p != NULL && p->elemento != l->elemento) {
                p = p->siguiente;
            }

            lista auxiliarListaP = p;
            lista auxiliarListaL = l;

            while (auxiliarListaL != NULL && auxiliarListaP != NULL && auxiliarListaL->elemento == auxiliarListaP->elemento) {
                auxiliarListaP = auxiliarListaP->siguiente;
                auxiliarListaL = auxiliarListaL->siguiente;
            }

            if (auxiliarListaL == NULL) {
                estaInculido = true;
            }

            if (p != NULL) {
                p = p->siguiente;
            }
        }
    }
    return estaInculido;
}

bool esListaVacia(lista l) {
    return l == NULL;
}

void imprimirLista(lista l) {
    if (l == NULL) {
        printf("Lista vacia\n");
        return;
    }

    printf("Lista: ");

    while (l != NULL) {
        printf("%d ", l->elemento);
        l = l->siguiente;
    }

    printf("\n");
}

int main() {
    lista primero = new nodo;
    lista segundo = new nodo;
    lista tercero = new nodo;
    lista cuarto = new nodo;
    lista quinto = new nodo;

    primero->elemento = 100;
    primero->siguiente = segundo;
    segundo->elemento = 200;
    segundo->siguiente = tercero;
    tercero->elemento = 300;
    tercero->siguiente = cuarto;

    cuarto->elemento = 500;
    cuarto->siguiente = quinto;
    quinto->elemento = 600;
    quinto->siguiente = NULL;

    imprimirLista(primero);

    return 0;
}