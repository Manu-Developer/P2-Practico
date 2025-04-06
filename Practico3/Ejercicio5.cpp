#include <stdio.h>

int mcd(int numero1, int numero2) {
    int mcd = 1;
    for (int i = 1; i <= numero2; i++) {
        if (numero1 % i == 0 && numero2 % i == 0) {
            mcd = i;
        }
    }
    return mcd;
}

int mcd2(int numero1, int numero2) {
    if (numero2 == 0) {
        return numero1;
    }
    return mcd2(numero2, numero1 % numero2);
}

int main() {
    printf("%d", mcd(24, 16));
    return 0;
}