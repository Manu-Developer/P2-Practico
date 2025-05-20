#include "./Practico8/Ejercicio4.h"

#include <stdio.h>

#include <string>

struct nodo_pedido {
    int id;
    string *descripcion;
    nodo_pedido *sig;
};

struct cabezalPedidos {
    bool *iDesp;
    colaP inicioPed;
    colaP finPed;
};

pedido crearPedidos(int k) {
    pedido p = new cabezalPedidos;
    p->iDesp = new bool[k + 1];
    for (int i = 0; i <= k; i++) {
        p->iDesp[i] = false;
    }
    p->inicioPed = NULL;
    p->finPed = NULL;
    return p;
}

void insertar(pedido &p, int i, string d) {
    if (!existePedido(p, i)) {
        p->iDesp[i] = true;
        nodo_pedido *nuevoP = new nodo_pedido;
        nuevoP->id = i;
        nuevoP->descripcion = d;
        nuevoP->sig = NULL;
        if (p->inicioPed == NULL) {
            p->inicioPed = nuevoP;
        } else {
            p->finPed->sig = nuevoP;
        }
        p->finPed = nuevoP;
    }
}