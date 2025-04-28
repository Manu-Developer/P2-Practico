#include <stdio.h>

int busquedaBinaria(char c, char *A, int inf, int sup) {
    int resultado;
    if (inf > sup) {
        resultado = -1;
    } else {
        int medio = (inf + sup) / 2;
        if (c < A[medio]) {
            resultado = busquedaBinaria(c, A, inf, medio - 1);
        } else if (c > A[medio]) {
            resultado = busquedaBinaria(c, A, medio + 1, sup);
        } else {
            resultado = medio;
        }
        return resultado;
    }
}

// T(0) <= c1 (Si L==NULL, c1 es constante)
// T(n) <= T(n/2)+c0 (Si L!=NULL, c0 es constante)

// Expandiendo por recurrencia:

// T(n) <= T(n/2)+c0 <= T(n/4)+2c0 <= T(n/8)+3c0 <=...<= T(n/2^i)+ic0

// Caso Base (n/2^i=1): => i=log(n)

// T(n) = log(n)c+T(1) = log(n)c0 + c1

// Entonces T(n) es O(log(n))