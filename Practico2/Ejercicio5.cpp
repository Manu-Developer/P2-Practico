#include <stdio.h>

void imprimir(int *arreglo, int n) {
    for (int i = 0; i < n; i++) {
        printf("[%d]", arreglo[i]);
    }
}

int elementoMax(int A[], int n) {
    int max = A[0];
    for (int i = 0; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

// Algoritmo de ordenacion Counting Sort
void countigSort(int array[], int largoArreglo) {
    int max = elementoMax(array, largoArreglo);
    int arrayAux[largoArreglo];
    int count[max + 1];
    int num, newIndex;

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < largoArreglo; i++) {
        num = array[i];
        count[num]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < largoArreglo; i++) {
        num = array[i];
        newIndex = count[num] - 1;
        arrayAux[newIndex] = num;
        count[num]--;
    }

    for (int i = 0; i < largoArreglo; i++) {
        array[i] = arrayAux[i];
    }
}

int main() {
    int arreglo[] = {8, 10, 3, 1, 3, 5, 7, 3, 5, 2};
    imprimir(arreglo, 10);
    countigSort(arreglo, 10);
    printf("\n");
    imprimir(arreglo, 10);
    return 0;
}