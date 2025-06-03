#include <stdio.h>

#define M 100
typedef unsigned int uint;

struct tipo_t {
    int dato;
    float orden;
};

struct estructura_t {
    // heap ordenado segun los valores de 'orden'
    // puede contener hasta M elementos. No se usa la posicion 0.
    tipo_t heap[M + 1];
    uint tope;

    // posiciones[i]==0 sii heap[posiciones[i]] no esta definido.
    // posiciones[heap[i].dato]==heap[posiciones[i]].dato
    //  vector de posiciones
    uint posiciones[M];
};

void iniciarEstructura(estructura_t &e) {
    e.tope = 0;
    for (int i = 0; i < M; i++) {
        e.posiciones[i] = 0;
    }
}

// Pre: e.posiciones[dato]!=0
void modificarOrden(int dato, float orden, estructura_t &e) {
    uint pos = e.posiciones[dato];  // posicion del elemento en el heap
    float orden_ant = e.heap[pos].orden;
    e.heap[pos].orden = orden;

    if (orden > orden_ant) {
        filtradoDescendente(e, pos);
    } else {
        filtradoAscendente(e, pos);
    }
}

// Pre: e.posiciones[dato]==0
void insertar(int dato, float orden, estructura_t &e) {
    e.tope++;
    e.heap[e.tope] = (tipo_t){dato, orden};
    e.posiciones[dato] = e.tope;
    filtradoAscendente(e, e.tope);
}

void eliminarMin(estructura_t &e, uint pos) {
    if (e.tope > 0) {
        e.heap[1] = e.heap[e.tope];
        e.posiciones[e.heap[e.tope].dato] = 1;
        e.tope--;  // elimina el nodo del monticulo

        if (e.tope > 1) {
            filtradoDescendente(e, 1);
        }
    }
}

void filtradoAscendente(estructura_t &e, uint pos) {
    tipo_t swap = e.heap[pos];

    while (pos != 1 && e.heap[pos].orden < e.heap[pos / 2].orden) {
        e.heap[pos] = e.heap[pos / 2];
        e.posiciones[e.heap[pos / 2].dato] = pos;
        pos /= 2;
    }
    e.heap[pos] = swap;
    e.posiciones[swap.dato] = pos;
}

void filtradoDescendente(estructura_t &e, uint pos) {
    tipo_t swap = e.heap[pos];
    uint hijo;

    while (2 * pos <= e.tope) {
        // Seleccionar el hijo con menor orden
        hijo = 2 * pos;
        if (hijo < e.tope && e.heap[hijo + 1].orden < e.heap[hijo].orden) {
            hijo++;
        }

        // Si el hijo tiene mayor o igual orden, se cumple la propiedad del heap
        if (swap.orden <= e.heap[hijo].orden) {
            break;
        }

        // Hacer el swap con el hijo
        e.heap[pos] = e.heap[hijo];
        e.posiciones[e.heap[hijo].dato] = pos;

        pos = hijo;
    }

    e.heap[pos] = swap;
    e.posiciones[swap.dato] = pos;
}