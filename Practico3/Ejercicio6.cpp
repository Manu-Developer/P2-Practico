#include <stdio.h>

typedef unsigned int uint;

void hanoi(uint n, char origen, char auxiliar, char destino) {
    if (n > 0) {
        if (n == 1) {
            printf("Disco:%d | Origen:%c | Destino:%c \n", 1, origen, destino);
        } else {
            hanoi(n - 1, origen, destino, auxiliar);
            printf("Disco:%d | Origen:%c | Destino:%c \n", n, origen, destino);
            hanoi(n - 1, auxiliar, origen, destino);
        }
    }
}

int main() {
    hanoi(4, 'A', 'B', 'C');
    return 0;
}