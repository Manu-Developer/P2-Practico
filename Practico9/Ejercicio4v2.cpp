#include <stdio.h>

#include "../Practico9/Ejercicio4.h"

struct nodoHash {
    Punto pt;
    nodoHash *sig;
};

struct rep_grafica {
    int cota;
    int cantidadElementos;
    Lista *tabla;
};

int funcionHash(int x, int cantidadElementos) {
    return x % cantidadElementos;
}

grafica CrearGrafica(int N) {
    grafica nuevaGrafica = new rep_grafica;
    nuevaGrafica->cantidadElementos = 0;
    nuevaGrafica->cota = N;
    nuevaGrafica->tabla = new Lista[N];
    for (int i = 0; i < N; i++) {
        nuevaGrafica->tabla[i] = CrearLista();
    }
    return nuevaGrafica;
}

void Asociar(int x, int y, grafica &g) {
    if (g->cantidadElementos < g->cota) {
        int indiceHash = funcionHash(x, g->cota);
        Punto puntoNuevo;
        puntoNuevo.x = x;
        puntoNuevo.y = y;
        Insertar(puntoNuevo, g->tabla[indiceHash]);
        g->cantidadElementos++;
    }
}

int Valor(int x, grafica g) {
    int indiceHash = funcionHash(x, g->cota);

    if (ExisteX(x, g->tabla[indiceHash])) {
        return x;
    } else {
        return -1;
    }
}

void Desasociar(int x, grafica &g) {
    int indiceHash = funcionHash(x, g->cota);
    Lista lista = g->tabla[indiceHash];

    if (ExisteX(x, lista)) {
        RemoverX(x, lista);
        g->cantidadElementos--;
    }
}