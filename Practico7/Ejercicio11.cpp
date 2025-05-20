#include "../Practico7/Ejercicio11.h"

#include <stdio.h>

struct nodo {
    int valor;
    nodo* sig;
};

struct rep_pila {
    int cantidad;
    nodo* pila;
};

Pila crearPila() {
    Pila p = new rep_pila;
    p->cantidad = 0;
    p->pila = NULL;
    return p;
}

void apilar(Pila& p, int elemento) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->valor = elemento;
    nuevoNodo->sig = p->pila;
    p->pila = nuevoNodo;
    p->cantidad++;
}

bool esVaciaPila(Pila p) {
    return p->cantidad == 0;
}

void desapilar(Pila& p) {
    nodo* aBorrar = p->pila;
    p->pila = p->pila->sig;
    delete aBorrar;
    p->cantidad--;
}

void destructorPila(Pila& p) {
    while (!esVaciaPila(p)) {
        desapilar(p);
    }
    delete p;
}

int tope(Pila p) {
    return p->pila->valor;
}

Pila maximosRelativos(Pila p) {
    Pila aux = crearPila();
    Pila resultado = crearPila();

    // Paso 1: Volcar pila a aux para invertir el orden
    while (!esVaciaPila(p)) {
        apilar(aux, tope(p));
        desapilar(p);
    }

    // Paso 2: Recorrer aux y calcular máximos relativos
    int maxAnterior = 0;

    while (!esVaciaPila(aux)) {
        int valor = tope(aux);

        if (valor > maxAnterior) {
            apilar(resultado, valor);
            maxAnterior = valor;
        }

        // restaurar pila original (opcional, si querés preservarla)
        apilar(p, valor);

        desapilar(aux);
    }

    destructorPila(aux);
    return resultado;
}