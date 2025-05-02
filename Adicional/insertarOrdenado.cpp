#include <stdio.h>
const int N = 100;
typedef int tNumeros[N];

void imprimirNumeros(tNumeros arregloNumeros, int numeroElementos) {
    for (int i = 0; i < numeroElementos; i++) {
        printf("[%d]", arregloNumeros[i]);
    }
}

void insertar(tNumeros arregloNumeros, int &numeroElementos, int elemento) {
    int i = numeroElementos - 1;
    while (i >= 0 && arregloNumeros[i] > elemento) {
        arregloNumeros[i + 1] = arregloNumeros[i];
        i--;
    }
    arregloNumeros[i + 1] = elemento;
    numeroElementos++;
}

int main() {
    int numeroElementos = 5;
    tNumeros arregloNumeros = {2, 3, 7, 8, 10};
    insertar(arregloNumeros, numeroElementos, 11);
    imprimirNumeros(arregloNumeros, numeroElementos);
    return 0;
}