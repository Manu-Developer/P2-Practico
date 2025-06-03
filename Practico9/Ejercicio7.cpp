#include "../Practico9/Ejercicio7.h"

#include <stdio.h>

struct nodoLista {
    int elemento;
    int cantidadRepeticiones;
    nodoLista *sig;
};

typedef struct nodoLista *multiconjunto;

multiconjunto crearConjunto() {
    multiconjunto nuevoConjunto = NULL;
    return nuevoConjunto;
}

bool esVacioConjunto(multiconjunto c) {
    return c == NULL;
}

nodoLista *obtenerElemento(multiconjunto c, int x) {
    while (c != NULL && c->elemento != x) {
        c = c->sig;
    }

    if (c != NULL) {
        nodoLista *aux = c;
        return aux;
    } else {
        return NULL;
    }
}

void insertarElemento(multiconjunto &c, int x) {
    nodoLista *nodoObtenido = obtenerElemento(c, x);

    if (nodoObtenido != NULL) {
        nodoObtenido->cantidadRepeticiones++;
    } else {
        nodoLista *nuevoNodo = new nodoLista;
        nuevoNodo->elemento = x;
        nuevoNodo->cantidadRepeticiones = 1;
        nuevoNodo->sig = c;
        c = nuevoNodo;
    }
}

void eliminarElemento(multiconjunto &c, int x) {
    // Encuentro el nodo al inicio de la lista.
    if (c != NULL && c->elemento == x) {
        nodoLista *aBorrar = c;
        c = c->sig;
        delete aBorrar;
        aBorrar = NULL;
        return;
    }

    // Buscar el nodo cuyo siguiente es el que contiene x.
    nodoLista *actual = c;
    while (actual->sig != NULL && actual->sig->elemento != x) {
        actual = actual->sig;
    }

    // Si no lo encontramos, salir
    if (actual->sig == NULL) return;

    // Nodo a eliminar
    nodoLista *aBorrar = actual->sig;
    actual->sig = aBorrar->sig;
    delete aBorrar;
    aBorrar = NULL;
}

void destruirConjunto(multiconjunto &c) {
    while (c != NULL) {
        nodoLista *aBorrar = c;
        c = c->sig;
        delete aBorrar;
        aBorrar = NULL;
    }

    c = NULL;
}

multiconjunto unionConjuntos(multiconjunto c1, multiconjunto c2) {
    multiconjunto nuevoConjunto = crearConjunto();

    // Copiar todos los nodos de c1
    while (c1 != NULL) {
        nodoLista *nuevoNodo = new nodoLista;
        nuevoNodo->elemento = c1->elemento;
        nuevoNodo->cantidadRepeticiones = c1->cantidadRepeticiones;
        nuevoNodo->sig = nuevoConjunto;
        nuevoConjunto = nuevoNodo;
        c1 = c1->sig;
    }

    // Agregar nodos de c2 (sumando repeticiones si ya existen)
    while (c2 != NULL) {
        nodoLista *nodoObtenido = obtenerElemento(nuevoConjunto, c2->elemento);

        if (nodoObtenido != NULL) {
            nodoObtenido->cantidadRepeticiones += c2->cantidadRepeticiones;
        } else {
            nodoLista *nuevoNodo = new nodoLista;
            nuevoNodo->elemento = c2->elemento;
            nuevoNodo->cantidadRepeticiones = c2->cantidadRepeticiones;
            nuevoNodo->sig = nuevoConjunto;
            nuevoConjunto = nuevoNodo;
        }

        c2 = c2->sig;
    }

    return nuevoConjunto;
}

int min(int numero1, int numero2) {
    if (numero1 < numero2) {
        return numero1;
    } else {
        return numero2;
    }
}

multiconjunto interseccionMultiConjuntos(multiconjunto c1, multiconjunto c2) {
    multiconjunto nuevoConjunto = crearConjunto();

    while (c1 != NULL) {
        nodoLista *nodoEnC2 = obtenerElemento(c2, c1->elemento);

        if (nodoEnC2 != NULL) {
            nodoLista *nuevoNodo = new nodoLista;
            nuevoNodo->elemento = c1->elemento;
            nuevoNodo->cantidadRepeticiones = min(c1->cantidadRepeticiones, nodoEnC2->cantidadRepeticiones);
            nuevoNodo->sig = nuevoConjunto;
            nuevoConjunto = nuevoNodo;
        }

        c1 = c1->sig;
    }

    return nuevoConjunto;
}

multiconjunto diferenciaMultiConjuntos(multiconjunto c1, multiconjunto c2) {
    multiconjunto nuevoConjunto = crearConjunto();

    while (c1 != NULL) {
        nodoLista *nodoEnC2 = obtenerElemento(c2, c1->elemento);

        if (nodoEnC2 == NULL) {
            // Solo agregamos si el elemento NO está en c2
            nodoLista *nuevoNodo = new nodoLista;
            nuevoNodo->elemento = c1->elemento;
            nuevoNodo->cantidadRepeticiones = c1->cantidadRepeticiones;
            nuevoNodo->sig = nuevoConjunto;
            nuevoConjunto = nuevoNodo;
        }

        c1 = c1->sig;
    }

    return nuevoConjunto;
}

void imprimirConjunto(multiconjunto c) {
    while (c != NULL) {
        printf("El elemento %d se repite %d veces en el MultiConjunto\n", c->elemento, c->cantidadRepeticiones);
        c = c->sig;
    }
}

int main() {
    multiconjunto c = crearConjunto();

    // Insertar elementos
    insertarElemento(c, 3);
    insertarElemento(c, 1);
    insertarElemento(c, 3);
    insertarElemento(c, 4);
    insertarElemento(c, 1);

    printf("MultiConjunto despues de insertar elementos:\n");
    imprimirConjunto(c);

    // Eliminar todas las ocurrencias de un elemento
    eliminarElemento(c, 3);
    printf("\nMultiConjunto despues de eliminar todas las ocurrencias de 3:\n");
    imprimirConjunto(c);

    // Verificar si está vacío
    printf("\nEl multiconjunto esta vacio? %s\n", esVacioConjunto(c) ? "Si" : "No");

    // Destruir multiconjunto
    destruirConjunto(c);
    printf("\nMultiConjunto despues de destruirlo:\n");
    imprimirConjunto(c);

    printf("\nEl multiconjunto esta vacio? %s\n", esVacioConjunto(c) ? "Si" : "No");

    return 0;
}