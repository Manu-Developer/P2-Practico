#ifndef EJ_11
#define EJ_11

struct rep_pila;
typedef struct rep_pila *Pila;

// Crea una nueva pila vacia.
Pila crearPila();

// Agrega un elemento al tope de la pila p.
void apilar(Pila &p, int elemento);

// Devuelve 'true' si y solo si la pila es vacia, en caso contrario 'false'.
bool esVaciaPila(Pila p);

// Elimina el elemento ubicado en el tope de la pila p.
// Pre: !esVacia(pila)
void desapilar(Pila &p);

// Elimina todos los elementos de la pila p y destruye la pila p.
void destructorPila(Pila &p);

// Devuelve el primer elemento de la pila p.
int tope(Pila p);

#endif