#include <stdio.h>

void Merge(int *A, int inicio, int medio, int fin) {
    int arrayAux[fin - inicio + 1];
    int posAux = 0;
    int inicio1 = inicio;
    int inicio2 = medio + 1;
    int fin1 = medio;
    int fin2 = fin;

    // Mientras hayan elementos para intercalar
    while (inicio1 <= fin1 && inicio2 <= fin2) {
        if (A[inicio1] < A[inicio2]) {
            arrayAux[posAux++] = A[inicio1++];
        } else {
            arrayAux[posAux++] = A[inicio2++];
        }
    }
    // Si quedan elementos en la primera porcion
    while (inicio1 <= fin1) {
        arrayAux[posAux++] = A[inicio1++];
    }

    // Si quedan elementos en la segunda porcion
    while (inicio2 <= fin2) {
        arrayAux[posAux++] = A[inicio2++];
    }

    // Copiar los elementos al vector A
    for (posAux = 0; posAux < (fin - inicio + 1); posAux++) {
        A[inicio + posAux] = arrayAux[posAux];
    }
}

void MergeSort(int *A, int inicio, int fin) {
    if (inicio < fin) {
        int medio = (inicio + fin) / 2;
        MergeSort(A, inicio, medio);
        MergeSort(A, medio + 1, fin);
        Merge(A, inicio, medio, fin);
    }
}

int main() {
    int array[10] = {10, 3, 65, 2, 1, 8, 12, 7, 9, 5};

    MergeSort(array, 0, 9);
    for (int i = 0; i < 10; i++) {
        printf("[%d] -> ", array[i]);
    }
    return 0;
}

// T(0)=T(1)=0
// T(n)<=2T(n/2)+nc1+c0