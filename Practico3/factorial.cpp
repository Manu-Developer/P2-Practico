#include <stdio.h>

int factorial(int numero) {
    if (numero == 1) {
        return 1;
    }

    return numero * factorial(numero - 1);
}

int main() {
    printf("El factorial de %d es %d", 5, factorial(5));
    return 0;
}