#include <stdio.h>

struct rep_heap {
    int tope;
    int *arreglo;
};

// Caso base: pos==1 y arreglo[pos]>=arreglo[pos/2]
// Pre: 1<=pos<=n

void filtradoAscendenteRec(int *arreglo, int pos) {
    if (pos > 1 && arreglo[pos] < arreglo[pos / 2]) {
        int swap = arreglo[pos];
        arreglo[pos] = arreglo[pos / 2];
        arreglo[pos / 2] = swap;
        filtradoAscendenteRec(arreglo, pos / 2);
    }
}

// Pre: 1<=pos<=n
void filtradoAscendenteIter(int *arreglo, int pos) {
    while (pos > 1 && arreglo[pos] < arreglo[pos / 2]) {
        int swap = arreglo[pos];
        arreglo[pos] = arreglo[pos / 2];
        arreglo[pos / 2] = swap;
        pos /= 2;  // pos = pos/2;
    }
}

// Revisar parametros
// Caso base: 2*pos > n y arreglo[2*pos] > arreglo[pos] && arreglo[2*pos+1] > arreglo[pos]
void filtradoDescendenteRec(int *arreglo, int pos, int n) {
    if (2 * pos <= n) {
        int hijo = 2 * pos;

        if (hijo + 1 <= n && arreglo[hijo + 1] < arreglo[hijo]) {
            hijo++;
        }

        if (arreglo[hijo] < arreglo[pos]) {
            int swap = arreglo[pos];
            arreglo[pos] = arreglo[hijo];
            arreglo[hijo] = swap;

            filtradoDescendenteRec(arreglo, hijo, n);
        }
    }
}

void filtradoDescendenteIter(int *arreglo, int tope, int pos) {
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

rep_heap crearHeap(int tamanio) {
    rep_heap nuevoHeap;
    nuevoHeap.arreglo = new int[tamanio];
    nuevoHeap.tope = 0;
    return nuevoHeap;
}

// Pre: El heap no esta lleno.
void insertar(int dato, rep_heap heap) {
    heap.tope++;
    heap.arreglo[heap.tope] = dato;
    filtradoAscendenteIter(heap.arreglo, heap.tope);
}

// Pre: El heap no esta vacio.
void eliminarMinimo(rep_heap heap) {
    heap.arreglo[1] = heap.arreglo[heap.tope];
    heap.tope--;
    if (heap.tope > 0) {
        filtradoDescendenteIter(heap.arreglo, heap.tope, 1);
    }
}