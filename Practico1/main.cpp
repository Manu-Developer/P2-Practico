#include <stdio.h>

#include "Punto.h"

int main(int argc, char const *argv[]) {
    Punto p1 = crearPunto(3, 4);
    Punto p2 = crearPunto(0, 8.5);

    printf("%f, %f\n", coordX(p1), coordY(p1));
    printf("Distancia Euclidiana: %f", distanciaEuclidiana(p1, p2));
    return 0;
}
