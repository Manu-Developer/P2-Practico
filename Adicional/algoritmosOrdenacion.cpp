#include <stdio.h>

void imprimirArray(int array[], int largo) {
    for (int i = 0; i < largo; i++) {
        printf("[%d]", array[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubbleSort(int array[], int largo) {
    for (int i = 0; i < largo; i++) {
        for (int j = 0; j < largo - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int auxiliar = array[j];
                array[j] = array[j + 1];
                array[j + 1] = auxiliar;
            }
        }
    }
}

// Selection Sort
void selectionSort(int array[], int largo) {
    for (int i = 0; i < largo - 1; i++) {
        int minPosicion = i;

        for (int j = i + 1; j < largo; j++) {
            if (array[j] < array[minPosicion]) {
                minPosicion = j;
            }
        }

        if (minPosicion != i) {
            int auxiliar = array[i];
            array[i] = array[minPosicion];
            array[minPosicion] = auxiliar;
        }
    }
}

// Insertion Sort
void insertionSort(int array[], int largo) {
    for (int i = 1; i < largo; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = key;
    }
}

int main() {
    int array[] = {6, 2, 3, 7, 9, 10};
    imprimirArray(array, 6);
    selectionSort(array, 6);
    imprimirArray(array, 6);

    return 0;
}