#include "../Practico7/Ejercicio4.h"

#include <stdio.h>

struct nodo {
    int valor;
    nodo* sig;
};

struct rep_pila {
    int cantidad;
    nodo* pila;
};

struct rep_cola {
    nodo* primero;
    nodo* ultimo;
    int cantidad;
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

//-------------------------------------//

Cola crearCola() {
    Cola colaNueva = new rep_cola;
    colaNueva->primero = colaNueva->ultimo = NULL;
    return colaNueva;
}

bool esVaciaCola(Cola c) {
    return c->primero == NULL;
}

void encolar(int t, Cola& c) {
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

int frente(Cola c) {
    return c->primero->valor;
}

bool mismosElementos(Pila& p, Cola& c) {
    Pila p_invertida = crearPila();
    bool resultado = true;

    while (!esVaciaPila(p)) {
        apilar(p_invertida, tope(p));
        desapilar(p);
    }

    while (!esVaciaPila(p_invertida) && !esVaciaCola(c) && resultado) {
        if (tope(p_invertida) != frente(c)) {
            resultado = false;
        }
        desapilar(p_invertida);
        desencolar(c);
    }

    if (!esVaciaCola(c) || !esVaciaPila(p_invertida)) {
        resultado = false;
    }

    destructorPila(p_invertida);
    return resultado;
}

int main() {
    Pila p = crearPila();
    Cola c = crearCola();

    // Ambos tendrán: 1 -> 2 -> 3 (mismo orden)
    apilar(p, 1);
    apilar(p, 2);
    apilar(p, 3);

    encolar(1, c);
    encolar(2, c);
    encolar(3, c);

    if (mismosElementos(p, c)) {
        printf("La pila y la cola contienen los mismos elementos en el mismo orden.\n");
    } else {
        printf("La pila y la cola NO contienen los mismos elementos en el mismo orden.\n");
    }

    destructorPila(p);
    destruirCola(c);

    return 0;
}