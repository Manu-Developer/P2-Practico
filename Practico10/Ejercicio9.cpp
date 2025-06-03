#include <stdio.h>
#define cota 1024

// Elementos de las listas para cola de prioridad.
struct infoCP {
    int elemento;
    int prioridad;
};

struct heap_t {
    infoCP arreglo[cota];
    int tope;
};

typedef struct heap_t *colaPrioridad;

// Decrementa el valor 'restar ' a las prioridades de todos los elementos de 'cp'.
void decTodas(int restar, colaPrioridad &cp) {
    for (int i = 1; i <= cp->tope; i++) {
        cp->arreglo[i].prioridad -= restar;
    }
}

// Funcion fuera del practico
// Retorna true si y solo si en cp hay un elemento con prioridad prio.
bool buscar(int prio, colaPrioridad cp) {
    for (int i = 0; i < cp->tope; i++) {
        if (cp->arreglo[i].prioridad == prio) {
            return true;
        }
    }
    return false;
}