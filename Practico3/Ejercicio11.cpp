#include <assert.h>
#include <stdio.h>

void vasosAlternados(bool *vectorVasos, int inf, int sup) {
    if (sup - inf < 2) return;  // Caso base: si hay menos de 2 elementos, detenerse

    vectorVasos[inf] = true;
    vectorVasos[inf + 1] = false;

    if (sup - inf >= 4) {  // Si hay suficientes elementos, continuar la recursión
        vectorVasos[sup - 2] = true;
        vectorVasos[sup - 1] = false;
        vasosAlternados(vectorVasos, inf + 2, sup - 2);
    }
}

void imprimirVasos(bool *vectorVasos, int n) {
    for (int i = 0; i < n; i++) {
        if (vectorVasos[i] == true) {
            printf("[T]");
        } else {
            printf("[F]");
        }
    }
}

int main() {
    int n;
    printf("Digite la cantidad de vasos:");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("El numero no es par");
    } else {
        bool *vectorVasos = new bool[n];
        for (int i = 0; i < n / 2; i++) {
            vectorVasos[i] = true;
        }
        for (int i = n / 2; i < n; i++) {
            vectorVasos[i] = false;
        }
        imprimirVasos(vectorVasos, n);
        vasosAlternados(vectorVasos, 0, n);
        printf("\n");
        imprimirVasos(vectorVasos, n);
        delete[] vectorVasos;
    }
    return 0;
}