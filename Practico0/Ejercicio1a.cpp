#include <stdio.h>

int minimoValor(int cal1, int cal2, int cal3, int cal4, int cal5) {
    int valorMinimo = cal1;

    if (cal2 < valorMinimo) {
        valorMinimo = cal2;
    } else if (cal3 < valorMinimo) {
        valorMinimo = cal3;
    } else if (cal4 < valorMinimo) {
        valorMinimo = cal4;
    } else if (cal5 < valorMinimo) {
        valorMinimo = cal5;
    }

    return valorMinimo;
}

int PromedioClase() {
    int cal1, cal2, cal3, cal4, cal5;
    printf("Ingrese 5 calificaciones:");

    scanf("%d %d %d %d %d", &cal1, &cal2, &cal3, &cal4, &cal5);

    int promedioTotal = cal1 + cal2 + cal3 + cal4 + cal5;

    return (promedioTotal - minimoValor(cal1, cal2, cal3, cal4, cal5)) / 5;
}

int main(int argc, char const *argv[]) {
    printf("%d", PromedioClase());
    return 0;
}