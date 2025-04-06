#include <stdio.h>

/* Inserta e en A [1.. n +1] de manera ordenada .
Precondicion: n >=0. Si n >=1 = > A [1.. n] está ordenado de manera creciente . A[n+1] es indeterminado .
Postcondicion: A [1.. n+1] queda ordenado de manera creciente . */
void insertarOrdenado(float* A, int n, float e) {
    if (n == 0) {  // Arreglo Vacio
        A[1] = e;
    } else if (e > A[n]) {  // Si "e" es el mayor de todos, lo pongo al final.
        A[n + 1] = e;
    } else {
        A[n + 1] = A[n];
        insertarOrdenado(A, n - 1, e);
    }
}

/* Ordena A [1.. n] de manera creciente . */
void ordenar(float* A, int n) {
    if (n > 1) {
        ordenar(A, n - 1);
        insertarOrdenado(A, n - 1, A[n]);
    }
}

int main() {
    float array[5] = {1, 2, 6, 9};
    insertarOrdenado(array, 5, 4);
    for (int i = 0; i < 5; i++) {
        printf("[%d]", array[i]);
    }

    return 0;
}