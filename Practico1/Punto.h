// punto .h
#ifndef _PUNTO_H
#define _PUNTO_H

// En el .h definimos las cabeceras de las funciones para que no tengamos que hacerlo en el .principal

/* Representación de puntero apuntando a la estructura rep_punto */
typedef struct rep_punto* Punto;

/* Operaciones de Punto */

/* Devuelve un 'Punto ' de coordenadas 'x' e 'y '. */
Punto crearPunto(double x, double y);

/* Devuelve la coordenada 'x' de 'punto '. */
double coordX(Punto punto);

/* Devuelve la coordenada 'y' de 'punto '. */
double coordY(Punto punto);

double distanciaEuclidiana(Punto punto1, Punto punto2);

#endif