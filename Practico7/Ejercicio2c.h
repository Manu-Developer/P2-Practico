#ifndef COLA_H
#define COLA_H

struct arrayCircular;
typedef struct arrayCircular *Cola;

// Devuelve la cola vacia.
Cola crearCola(int cota);

// Devuelve 'true' si c es vacia, 'false' en otro caso.
bool esVaciaCola(Cola c);

// Devuelve true si la cola esta llena
bool estaLlenaCola(Cola c);

// Devuelve el primer elemento de c.
// Precondicion : !esVaciaCola(c).
int frente(Cola c);

// Agrega el elemento t al final de c si la cantidad de elementos de la cola no supera su cota.
void encolar(int t, Cola &c);

// Remueve el primer elemento de c.
// Precondicion : !esVaciaCola(c).
void desencolar(Cola &c);

// Libera toda la memoria ocupada por c.
void destruirCola(Cola &c);

#endif