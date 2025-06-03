#ifndef EJ_7A
#define EJ_7A

struct nodoCP;
typedef struct nodoCP *colaP;

// Crea y retorna una nueva cola de prioridad vacia.
colaP crearColaPrioridadVacia();

// Inserta el elemento 'x' con una prioridad en 'cp'.
// Pre: estaDefinido(cp, x)=false
void insertarElemento(colaP &cp, int x, int prioridad);

// Retorna 'true' si y solo si la cola de prioridad 'cp' es vacia. En caso contrario retorna 'false'.
bool esColaVacia(colaP cp);

// Retorna 'true' si y solo el elemento 'x' esta definido en la cola de prioridad 'cp'.
bool estaDefinido(colaP cp, int x);

// Elimina el elemento 'x' ubicado en la cola de prioridad 'cp'.
// Pre: estaDefinido(cp, x)=true
void borrar(colaP &cp, int x);

// Destruye toda la memoria asociada a la cola de prioridad 'cp'.
void destruir(colaP &cp);

#endif