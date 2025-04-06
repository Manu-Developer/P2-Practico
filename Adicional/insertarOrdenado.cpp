#include <stdio.h>
const int N = 100;
typedef int tNumeros[N];

void imprimirNumeros(tNumeros arregloNumeros, int numeroElementos) {
    for (int i = 0; i < numeroElementos; i++) {
        printf("[%d]", arregloNumeros[i]);
    }
}

void insertar(tNumeros arregloNumeros, int &numeroElementos, int elemento) {
    int i = numeroElementos;
    while (elemento < arregloNumeros[i - 1]) {
        arregloNumeros[i] = arregloNumeros[i - 1];
        i--;
    }
    arregloNumeros[i] = elemento;
    numeroElementos++;
}

int main() {
    int numeroElementos = 5;
    tNumeros arregloNumeros = {1, 2, 7, 8, 10};
    insertar(arregloNumeros, numeroElementos, 6);
    imprimirNumeros(arregloNumeros, numeroElementos);
    return 0;
}