#include <stdio.h>

int factorialAcum(int n, int acum) {
    if (n == 1) {
        return acum;
    } else {
        acum = acum * n;
        return factorialAcum(n - 1, acum);
    }
}

// 5! = fact(5,1)
// 5! = fact(4,5)
// 5! = fact(3,20)
// 5! = fact(2,60)
// 5! = fact(1,120) -> Retornamos el acumulador

int main() {
    printf("%d", factorialAcum(5, 1));
    return 0;
}