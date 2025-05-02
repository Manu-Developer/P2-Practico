#include <stdio.h>

bool esPrimo(int numero) {
    if (numero <= 1) {
        return false;
    }

    // Verificamos si el número es divisible por algún número entre 2 y la raíz cuadrada de 'numero'
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            return false;  // Si es divisible por 'i', no es primo
        }
    }

    return true;  // Si no es divisible por ningún número, es primo
}

int main() {
    int A, B;
    printf("Digite A:");
    scanf("%d", &A);
    printf("Digite B:");
    scanf("%d", &B);

    for (int i = A; i <= B; i++) {
        if (esPrimo(i)) {
            printf("El numero %d es primo\n", i);
        }
    }

    return 0;
}