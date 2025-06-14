#include <stdio.h>

#include "../Practico10/Ejercicio7b.h"

struct elemento {
    int x;
    int prioridad;
};

struct rep_cola_prioridad {
    int tope;
    int cota;
    elemento *arreglo;
};

colaP crearColaPrioridadVacia(int cota) {
    colaP nuevaColaPrioridad = new rep_cola_prioridad;
    nuevaColaPrioridad->tope = 0;
    nuevaColaPrioridad->cota = cota;
    nuevaColaPrioridad->arreglo = new elemento[cota + 1];
    // No es necesaria esta inicialización explícita porque tope=0 indica que el heap está vacío y solo se usan posiciones hasta tope.
    for (int i = 1; i <= cota; i++) {
        nuevaColaPrioridad->arreglo[i].x = 0;
        nuevaColaPrioridad->arreglo[i].prioridad = 0;
    }
    return nuevaColaPrioridad;
}

int cota(colaP cp) {
    return cp->cota;
}

bool estaLLena(colaP cp) {
    return cp->tope == cp->cota;
}

void filtradoAscendenteIter(colaP &cp, int pos) {
    while (pos > 1 && cp->arreglo[pos].prioridad < cp->arreglo[pos / 2].prioridad) {
        elemento temp = cp->arreglo[pos];
        cp->arreglo[pos] = cp->arreglo[pos / 2];
        cp->arreglo[pos / 2] = temp;
        pos /= 2;
    }
}

void filtradoDescendenteIter(colaP &cp, int tope, int pos) {
    while (2 * pos <= tope) {
        int hijo = 2 * pos;
        if (hijo + 1 <= tope && cp->arreglo[hijo + 1].prioridad < cp->arreglo[hijo].prioridad) {
            hijo++;
        }
        if (cp->arreglo[hijo].prioridad < cp->arreglo[pos].prioridad) {
            elemento temp = cp->arreglo[pos];
            cp->arreglo[pos] = cp->arreglo[hijo];
            cp->arreglo[hijo] = temp;
            pos = hijo;
        } else {
            break;
        }
    }
}

// O(logn)
void insertarElemento(colaP &cp, int x, int prioridad) {
    cp->tope++;
    cp->arreglo[cp->tope] = {x, prioridad};
    filtradoAscendenteIter(cp, cp->tope);
}

bool esColaVacia(colaP cp) {
    return cp->tope == 0;
}

elemento obtenerMinimo(colaP cp) {
    return cp->arreglo[1];
}

// O(logn)
void borrarMinimo(colaP &cp) {
    cp->arreglo[1] = cp->arreglo[cp->tope];
    cp->tope--;
    if (cp->tope > 0) {
        filtradoDescendenteIter(cp, cp->tope, 1);
    }
}

void destruir(colaP &cp) {
    delete[] cp->arreglo;
    delete cp;
    cp = NULL;
}

int main() {
    return 0;
}