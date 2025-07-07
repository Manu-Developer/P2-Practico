#include <stdio.h>
#include <string.h>

struct pepe {
    int m;
    int f;
};

void intercambia(int &a, int &b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void) {
    pepe p;
    p = {10, 1};
    int m = 8, n = 7;
    printf("Antes: m=%d n=%d\n", m, n);
    intercambia(m, n);
    printf("Despues: m=%d n=%d\n", m, n);

    char frase[10] = "hola555";
    printf("%d", strlen(frase));
    return 0;
}
