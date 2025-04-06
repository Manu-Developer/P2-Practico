#include <stdio.h>

int main() {
    int *puntero = new int;
    *puntero = 5;
    printf("%d\n", puntero);
    return 0;
}