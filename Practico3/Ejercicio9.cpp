#include <stdio.h>

int combinaciones(int m, int n) {
    if ((m == n) || (n == 0)) {
        return 1;
    } else if (n == 1) {
        return m;
    } else if ((m > n) && (n > 0)) {
        return combinaciones(m - 1, n) + combinaciones(m - 1, n - 1);
    }
}

int main() {
    printf("%d", combinaciones(6, 3));
    return 0;
}