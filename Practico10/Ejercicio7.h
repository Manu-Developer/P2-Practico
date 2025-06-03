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

// Retorna el menor elemento asociado a la cola de prioridad 'cp'.
bool obtenerMinimo(colaP cp, int x);

// Elimina el elemento con menor prioridad en la cola de prioridad 'cp'.
// Pre: estaDefinido(cp, x)=true
void borrarMinimo(colaP &cp);

// Destruye toda la memoria asociada a la cola de prioridad 'cp'.
void destruir(colaP &cp);

#endif