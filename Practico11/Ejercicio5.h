#ifndef EJ_5
#define EJ_5

struct TInfo;
struct nodoCP;
typedef struct nodoCP *colaP;

// Crea y retorna una nueva cola de prioridad vacia.
colaP crearColaPrioridadVacia();

// Inserta el elemento con una prioridad en 'cp'.
// Si dos elementos tienen igual prioridad en la cola de prioridad, se respeta la política FIFO.
// Pre: prioridad >= 0

void insertarElemento(colaP &cp, int elemento, int prioridad);

// Retorna 'true' si y solo si la cola de prioridad 'cp' es vacia. En caso contrario retorna 'false'.
bool esColaVacia(colaP cp);

// Retorna el elemento con menor prioridad numérica en 'cp'.
// Pre: !esColaVacia(cp)
TInfo obtenerMinimo(colaP cp);

// Elimina el elemento con menor prioridad en la cola de prioridad 'cp'.
// Pre: !esColaVacia(cp)
void borrarMinimo(colaP &cp);

// Destruye toda la memoria asociada a la cola de prioridad 'cp'.
void destruir(colaP &cp);

#endif