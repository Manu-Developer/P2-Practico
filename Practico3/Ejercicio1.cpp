#include <stdio.h>

int fibonacci(int numero) {
    if (numero == 0 || numero == 1) {
        return numero;
    }

    return fibonacci(numero - 1) + fibonacci(numero - 2);
}

int main() {
    printf("%d", fibonacci(6));
    return 0;
}