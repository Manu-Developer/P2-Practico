#include "Punto.h"

#include <math.h>

struct rep_punto {
    double x;
    double y;
};

/* Devuelve un 'Punto ' de coordenadas 'x' e 'y '. */
Punto crearPunto(double x, double y) {
    Punto p = new rep_punto;
    p->x = x;
    p->y = y;
    return p;
}

/* Devuelve la coordenada 'x' de 'punto '. */
double coordX(Punto punto) {
    return punto->x;
}

/* Devuelve la coordenada 'y' de 'punto '. */
double coordY(Punto punto) {
    return punto->y;
}

double distanciaEuclidiana(Punto punto1, Punto punto2) {
    return sqrt(pow(coordX(punto2) - coordX(punto1), 2) + pow(coordY(punto2) - coordY(punto1), 2));
}