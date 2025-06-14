#include <stdio.h>

#include "../Practico9/Ejercicio4.h"

struct rep_grafica {
    int cota;
    int cantidadElementos;
    Lista *tabla;  // Arreglo de listas
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

    Lista iterador = g->tabla[indiceHash];
    while (!EsVaciaLista(iterador) && Primero(iterador).x != x) {
        Resto(iterador);
    }
    if (EsVaciaLista(iterador)) {
        return -1;
    } else {
        return Primero(iterador).y;
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