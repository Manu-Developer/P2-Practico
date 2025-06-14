#include <stdio.h>

struct representacion_heap {
    int tope;
    int* arreglo;
};

typedef struct representacion_heap* heap;

void filtradoAscendenteIter(int* arreglo, int pos) {
    while (pos > 1 && arreglo[pos] < arreglo[pos / 2]) {
        int swap = arreglo[pos];
        arreglo[pos] = arreglo[pos / 2];
        arreglo[pos / 2] = swap;
        pos /= 2;  // pos = pos/2;
    }
}

void filtradoDescendenteIter(int* arreglo, int tope, int pos) {
    while (2 * pos <= tope) {
        int hijo = 2 * pos;

        if (hijo + 1 <= tope && arreglo[hijo + 1] < arreglo[hijo]) {
            hijo++;
        }

        if (arreglo[hijo] < arreglo[pos]) {
            int swap = arreglo[pos];
            arreglo[pos] = arreglo[hijo];
            arreglo[hijo] = swap;
            pos = hijo;
        } else {
            break;
        }
    }
}

void construirHeap(int* arreglo, int tope) {
    for (int i = 1; i <= tope; i++) {
        filtradoAscendenteIter(arreglo, i);
    }
}

// El filtradodescendente queda O(n)
void construirHeap(int* arreglo, int tope) {
    for (int i = tope / 2; i >= 1; i--) {
        filtradoDescendenteIter(arreglo, tope, i);
    }
}