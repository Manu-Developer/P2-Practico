#include <stdio.h>

struct nodoDoble {
    int dato;
    nodoDoble *anterior;
    nodoDoble *siguiente;
};

struct cabezal {
    nodoDoble *inicio;
    nodoDoble *final;
};

void insertarFinal(cabezal *&l, int dato) {
    if (l->inicio == NULL) {
        l->inicio = new nodoDoble;
        l->inicio->dato = dato;
        l->inicio->anterior = NULL;
        l->inicio->siguiente = NULL;
        l->final = l->inicio;
    } else {
        l->final->siguiente = new nodoDoble;
        l->final->siguiente->dato = dato;
        l->final->siguiente->siguiente = NULL;
        l->final->siguiente->anterior = l->final;
        l->final = l->final->siguiente;
    }
}

void insertarFinalV2(cabezal *&l, int dato) {
    nodoDoble *nuevo = new nodoDoble;
    nuevo->dato = dato;
    nuevo->siguiente = NULL;
    nuevo->anterior = l->final;

    if (l->inicio == NULL) {
        l->inicio = nuevo;
        l->final = nuevo;
    } else {
        l->final->siguiente = nuevo;
        l->final = l->final->siguiente;
    }
}

int main() {
}