#include <stdio.h>

#include <iostream>

typedef unsigned int uint;

/* Cuenta los 1s del vector */
int contarUnosVector(int* v, uint m) {
    if (m == 0) {
        return 0;
    } else if (v[m - 1] == 1) {
        return 1 + contarUnosVector(v, m - 1);
    } else {
        return contarUnosVector(v, m - 1);
    }
}

int contarUnosMatriz(int** matriz, int m, int n) {
    if (m == 0) {  // Caso base: si no hay filas, no hay unos
        return 0;
    }
    return contarUnosVector(matriz[m - 1], n) + contarUnosMatriz(matriz, m - 1, n);
}

int main() {
    int m = 3, n = 4;

    // Crear la matriz dinámicamente
    int** matriz = new int*[m];
    for (int i = 0; i < m; i++) {
        matriz[i] = new int[n];
    }

    // Inicializar la matriz con los mismos valores
    int valores[3][4] = {
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 0, 0}};

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = valores[i][j];  // Copiar valores
        }
    }

    // Llamar a la función recursiva
    std::cout << "Cantidad de unos: " << contarUnosMatriz(matriz, m, n) << std::endl;

    // Liberar memoria
    for (int i = 0; i < m; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}