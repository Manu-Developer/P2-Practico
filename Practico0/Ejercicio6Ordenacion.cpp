#include <stdio.h>

// Algoritmo de Ordenacion Utilizado>: Bubble Sort
void ordenarArreglo(int arreglo[], int largoArreglo) {
    int auxiliar = 0;

    for (int i = 0; i < largoArreglo; i++) {
        for (int j = 0; j < largoArreglo - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    int arrayAOrdenar[] = {43, 5, 1, 76, 23, 8, 34};

    printf("Arreglo sin ordenar: ");

    for (int i = 0; i < 7; i++) {
        printf("[%d]", arrayAOrdenar[i]);
    }

    printf("\n");

    ordenarArreglo(arrayAOrdenar, 7);

    printf("Arreglo ordenado: ");

    for (int i = 0; i < 7; i++) {
        printf("[%d]", arrayAOrdenar[i]);
    }

    return 0;
}
