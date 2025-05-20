#ifndef EJ_4
#define EJ_4

struct rep_pila;
struct rep_cola;
typedef struct rep_pila *Pila;
typedef struct rep_cola *Cola;

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

//----------------------------------------------//

// Devuelve la cola vacia.
Cola crearCola();

// Agrega el elemento t al final de c.
void encolar(int t, Cola &c);

// Remueve el primer elemento de c.
// Precondicion : !esVaciaCola(c).
void desencolar(Cola &c);

// Devuelve 'true' si c es vacia, 'false' en otro caso.
bool esVaciaCola(Cola c);

// Libera toda la memoria ocupada por c.
void destruirCola(Cola &c);

// Devuelve el primer elemento de la cola c.
int frente(Cola c);

#endif