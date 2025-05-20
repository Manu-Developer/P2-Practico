#ifndef COLA_H
#define COLA_H

struct cabezal;
typedef struct cabezal *Cola;

// Crea una cola de enteros vacia.
Cola colaVacia();

// Devuelve 'true' si c es vacia, 'false' en otro caso.
bool esVaciaCola(Cola c);

// Devuelve el primer elemento de c.
// Precondicion : !esVaciaCola(c).
int frente(Cola c);

// Agrega el elemento t al final de c.
void encolar(int t, Cola &c);

// Remueve el primer elemento de c.
// Precondicion: si la cola es vacia la operacion no tiene efecto.
// Precondicion : !esVaciaCola(c).
void desencolar(Cola &c);

// Libera toda la memoria ocupada por c.
void destruirCola(Cola &c);

#endif