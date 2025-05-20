#ifndef DEQUE_H
#define DEQUE_H

struct cabezal;
typedef struct cabezal *Deque;

// Devuelve una deque vacia.
Deque dequeVacia();

// Devuelve 'true' si c es vacia, 'false' en otro caso.
bool esVaciaDeque(Deque c);

// Devuelve el primer elemento de c.
// Precondicion : !esVaciaCola(c).
int inicio(Deque c);

// Devuelve el ultimo elemento de c.
// Precondicion : !esVaciaCola(c).
int final(Deque c);

// Agrega el elemento t al inicio de c.
void insertar_inicio(int t, Deque &c);

// Agrega el elemento t al final de c.
void insertar_final(int t, Deque &c);

// Elimina el primer elemento de c.
// Precondicion : !esVaciaCola(c).
void eliminar_inicio(Deque &c);

// Elimina el ultimo elemento de c.
// Precondicion : !esVaciaCola(c).
void eliminar_final(Deque &c);

#endif