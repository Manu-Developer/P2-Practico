#include <stdio.h>
#define N 100

typedef struct rep_punto {
    int coordX, coordY;
} Punto;

typedef struct rep_colPuntos {
    int capacidad;
    int cantidad;
    Punto *arregloPuntos;
} ColPuntos;

int coordX(Punto pto) {
    return pto.coordX;
}

int coordY(Punto pto) {
    return pto.coordY;
}

void insertarPunto(ColPuntos &colPtos, Punto pto) {
    if (colPtos.cantidad == 0) {
        colPtos.arregloPuntos[0] = pto;
        colPtos.cantidad++;
    } else {
        colPtos.arregloPuntos[colPtos.cantidad] = pto;
        colPtos.cantidad++;
    }
}

Punto crearPunto(int coordX, int coordY) {
    Punto p;
    p.coordX = coordX;
    p.coordY = coordY;
    return p;
}

int menorCoordX(ColPuntos colPtos) {
    int menorCoordX = coordX(colPtos.arregloPuntos[0]);

    for (int i = 0; i < colPtos.cantidad; i++) {
        if (coordX(colPtos.arregloPuntos[i]) < menorCoordX) {
            menorCoordX = coordX(colPtos.arregloPuntos[i]);
        }
    }

    return menorCoordX;
}

Punto puntoMedio(Punto pto1, Punto pto2) {
    Punto ptoMedio;
    ptoMedio.coordX = (coordX(pto1) + coordX(pto2)) / 2;
    ptoMedio.coordY = (coordY(pto1) + coordY(pto2)) / 2;
    return ptoMedio;
}

int main(int argc, char const *argv[]) {
    ColPuntos colPtos;
    colPtos.cantidad = 0;
    colPtos.capacidad = N;
    colPtos.arregloPuntos = new Punto;

    insertarPunto(colPtos, crearPunto(3, 4));
    insertarPunto(colPtos, crearPunto(4, 5));
    insertarPunto(colPtos, crearPunto(6, 8));

    if (colPtos.cantidad > 0) {
        for (int i = 0; i < colPtos.cantidad; i++) {
            printf("(%d %d)", coordX(colPtos.arregloPuntos[i]), coordY(colPtos.arregloPuntos[i]));
        }
    }

    return 0;
}
