#include <stdio.h>

// ¿Hay al menos un elemento en A que sea menor que algún elemento en B?
bool F(int *A, int *B, int n) {
    bool b = false;
    for (int i = 0; i < n; i++)
        for (int j = n - 1; j > -1; j--)
            b = b || (A[i] < B[j]);
    return b;
}

// Encontrar el mínimo de B: O(n)
// Verificar si algún A[j] < minimioB: O(n)
// Complejidad total: O(n) + O(n) = O(n) (mejor que O(n²) del primer algoritmo)
bool F2(int *A, int *B, int n) {
    bool b = false;
    int minimioB = B[0];

    for (int i = 1; i < n; i++) {
        if (B[i] < minimioB) {
            minimioB = B[i];
        }
    }

    for (int j = 0; j < n; j++) {
        if (A[j] < minimioB) {
            b = true;
        }
    }

    return b;
}

int main() {
    int arregloA[3] = {1, 2, 3};
    int arregloB[3] = {4, 5, 6};

    printf("%d", F2(arregloA, arregloB, 3));
    return 0;
}