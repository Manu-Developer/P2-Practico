#ifndef EJ_7B
#define EJ_7B

struct elemento;
struct rep_cola_prioridad;
typedef struct rep_cola_prioridad *colaP;

// Crea y retorna una nueva cola de prioridad vacía y acotada de 'cota' elementos de tipo int.
colaP crearColaPrioridadVacia(int cota);

// Retorna la cota de elementos de 'cp'.
int cota(colaP cp);

// Retorna 'true' si y solo si la cola 'cp' esta llena. En caso contrario retorna 'false'.
bool estaLLena(colaP cp);

// Inserta el elemento 'x' con una prioridad en 'cp'.
// Pre: !estaLLena(cp)
void insertarElemento(colaP &cp, int x, int prioridad);

// Retorna 'true' si y solo si la cola de prioridad 'cp' es vacia. En caso contrario retorna 'false'.
bool esColaVacia(colaP cp);

// Retorna el elemento con menor prioridad numérica en 'cp'.
// Pre: !esColaVacia(cp)
elemento obtenerMinimo(colaP cp);

// Elimina el elemento con menor prioridad de la cola de prioridad 'cp'.
// Pre: !esColaVacia(cp)
void borrarMinimo(colaP &cp);

// Destruye toda la memoria asociada a la cola de prioridad 'cp'.
void destruir(colaP &cp);

#endif