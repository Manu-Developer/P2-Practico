#include <stdio.h>

/* Inserta e en A [1.. n +1] de manera ordenada .
Precondicion: n >=0. Si n >=1 = > A [1.. n] está ordenado de manera creciente . A[n+1] es indeterminado .
Postcondicion: A [1.. n+1] queda ordenado de manera creciente . */
void insertarOrdenado(int* A, int n, float e) {
    if ((n == 0) || e > A[n]) {  // Si el arreglo es vacio o "e" es el mayor de todos, lo pongo al final.
        A[n + 1] = e;
    } else {
        A[n + 1] = A[n];
        insertarOrdenado(A, n - 1, e);
    }
}

void insertarOrdenadov2(int* A, int n, float e) {
    while ((n > 0) && (e < A[n])) {
        A[n + 1] = n;
        n--;
    }
    A[n + 1] = e;
}

/* Ordena A [1.. n] de manera creciente . */
void ordenar(int* A, int n) {
    if (n > 1) {
        ordenar(A, n - 1);
        insertarOrdenado(A, n - 1, A[n]);
    }
}

int main() {
    int array[5] = {5, 2, 1, 9, 3};
    ordenar(array, 5);
    for (int i = 0; i < 5; i++) {
        printf("[%d]", array[i]);
    }

    return 0;
}