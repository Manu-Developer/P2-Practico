#include <stdio.h>

struct nodo {
    int elemento;
    nodo *siguiente;
};

typedef nodo *lista;

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

// obtenerPrimeros: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elementos de l.

lista obtenerPrimeros(lista l, int i) {
    lista resultado = NULL;
    lista *actual = &resultado;

    int contador = 0;
    while (l != NULL && contador < i) {
        *actual = new nodo;
        (*actual)->elemento = l->elemento;
        (*actual)->siguiente = NULL;

        // Avanzar
        actual = &((*actual)->siguiente);
        l = l->siguiente;
        contador++;
    }

    return resultado;
}

// No se si esta correcta esta funcion
lista sinPrimeros(lista l, int i) {
    lista auxiliar = l;
    int contadorNodos = 0;

    while (auxiliar != NULL && contadorNodos != i) {
        auxiliar = auxiliar->siguiente;
        contadorNodos++;
    }

    return auxiliar;
}

lista mergeSort(lista l, lista p) {
    lista resultado, dummy = new nodo;
    resultado = dummy;

    while (l != NULL && p != NULL) {
        resultado->siguiente = new nodo;
        resultado = resultado->siguiente;
        if (l->elemento < p->elemento) {
            resultado->elemento = l->elemento;
            l = l->siguiente;
        } else {
            resultado->elemento = p->elemento;
            p = p->siguiente;
        }
    }

    while (l != NULL) {
        resultado->siguiente = new nodo;
        resultado = resultado->siguiente;
        resultado->elemento = l->elemento;
        l = l->siguiente;
    }

    while (p != NULL) {
        resultado->siguiente = new nodo;
        resultado = resultado->siguiente;
        resultado->elemento = p->elemento;
        p = p->siguiente;
    }

    resultado->siguiente = NULL;
    resultado = dummy->siguiente;
    delete dummy;

    return resultado;
}

lista concatenar(lista l, lista p) {
    lista res;
    lista dummy = new nodo;
    res = dummy;  // res sirve de iterador

    while (l != NULL && p != NULL) {
        lista nuevo = new nodo;
        res->siguiente = nuevo;

        if (l->elemento < p->elemento) {
            nuevo->elemento = l->elemento;
            l = l->siguiente;
        } else {
            nuevo->elemento = p->elemento;
            p = p->siguiente;
        }
        res = res->siguiente;
    }

    while (l != NULL) {
        lista nuevo = new nodo;
        res->siguiente = nuevo;
        nuevo->elemento = l->elemento;
        l = l->siguiente;
        res = res->siguiente;
    }

    while (p != NULL) {
        lista nuevo = new nodo;
        res->siguiente = nuevo;
        nuevo->elemento = p->elemento;
        p = p->siguiente;
        res = res->siguiente;
    }

    res->siguiente = NULL;
    res = dummy->siguiente;
    delete dummy;

    return res;
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
    tercero->siguiente = NULL;
    cuarto->elemento = 400;
    cuarto->siguiente = quinto;
    quinto->elemento = 500;
    quinto->siguiente = NULL;

    imprimirLista(primero);
    imprimirLista(mergeSort(primero, cuarto));
    imprimirLista(primero);

    return 0;
}