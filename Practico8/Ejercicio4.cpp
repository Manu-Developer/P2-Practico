#include "./Practico8/Ejercicio4.h"

#include <stdio.h>

#include <string>

struct nodo_pedido {
    int id;
    char *descripcion;
    nodo_pedido *sig;
};

struct cabezalPedidos {
    bool *identificadoresPedidos;  // Para saber en O(1) si un elemento existe o no.
    cola_pedidos inicioPed;
    cola_pedidos finPed;
};

pedidos crearPedidos(int k) {
    pedidos p = new cabezalPedidos;
    p->identificadoresPedidos = new bool[k + 1];
    for (int i = 0; i <= k; i++) {
        p->identificadoresPedidos[i] = false;
    }
    p->inicioPed = NULL;
    p->finPed = NULL;
    return p;
}

void insertar(pedidos &p, int i, char *d) {
    if (!p->identificadoresPedidos[i]) {
        p->identificadoresPedidos[i] = true;
        cola_pedidos nuevoPedido = new nodo_pedido;
        nuevoPedido->descripcion = d;
        nuevoPedido->id = i;
        nuevoPedido->sig = NULL;

        if (p->inicioPed == NULL) {
            p->inicioPed = nuevoPedido;
        } else {
            p->finPed->sig = nuevoPedido;
        }
        p->finPed = nuevoPedido;
    }
}