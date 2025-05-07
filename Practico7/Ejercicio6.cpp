#include "../Practico7/Ejercicio6.h"

#include <stdio.h>

struct nodo {
    Digito digito;
    nodo *sig;
};

LDig crear() {
    LDig nuevaLista = NULL;
    return nuevaLista;
}

void cons(Digito x, LDig &l) {
    LDig nuevoDigito = new nodo;
    nuevoDigito->digito = x;
    nuevoDigito->sig = l;
    l = nuevoDigito;
}

bool esVacia(LDig l) {
    return l == NULL;
}

Digito primero(LDig l) {
    return l->digito;
}

LDig resto(LDig l) {
    return l->sig;
}

void imprimirLista(LDig l) {
    while (l != NULL) {
        printf("%d", l->digito);
        l = l->sig;
    }
}

LDig suma(LDig l1, LDig l2) {
    return NULL;
}

int main() {
}