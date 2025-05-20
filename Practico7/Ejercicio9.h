#ifndef EJ_9
#define EJ_9

struct nodoAB;
struct rep_cola;
typedef struct nodoAB *AB;
typedef struct rep_cola *Cola;

// Devuelve la cola vacia.
Cola crearCola();

// Agrega el elemento t al final de c.
void encolar(AB t, Cola &c);

// Remueve el primer elemento de c.
// Precondicion : !esVaciaCola(c).
void desencolar(Cola &c);

// Devuelve 'true' si c es vacia, 'false' en otro caso.
bool esVaciaCola(Cola c);

// Libera toda la memoria ocupada por c.
void destruirCola(Cola &c);

// Devuelve el primer elemento de la cola c.
AB frente(Cola c);

#endif