#include <stdio.h>

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

void filtradoDescendenteIter(int *arreglo, int pos, int n) {
    while (2 * pos <= n) {
        int hijo = 2 * pos;

        if (hijo + 1 <= n && arreglo[hijo + 1] < arreglo[hijo]) {
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