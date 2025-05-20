#include <stdio.h>

bool encontrar(int *array, int largo, int elemento, int inicio, int final) {
    while (inicio <= final) {
        int medio = (inicio + final) / 2;

        if (array[medio] == elemento) {
            return true;
        }

        if (array[medio] < elemento) {
            return encontrar(array, largo, elemento, medio + 1, final);
        } else if (array[medio] > elemento) {
            return encontrar(array, largo, elemento, inicio, medio - 1);
        }
    }

    return false;
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d", encontrar(array, 10, 226, 0, 9));
    return 0;
}