#ifndef EJ_7A
#define EJ_7A

struct TInfo;
struct nodoCP;
typedef struct nodoCP *colaP;

// Crea y retorna una nueva cola de prioridad vacia que podra contener elementos de tipo int.
colaP crearColaPrioridadVacia();

// Inserta el elemento 'x' con una prioridad en 'cp'.
void insertarElemento(colaP &cp, int x, int prioridad);

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