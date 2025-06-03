#ifndef EJ_7B
#define EJ_7B

struct rep_cola_prioridad;
typedef struct rep_cola_prioridad colaP;

// Crea y retorna una nueva cola de prioridad vacia que podrá contener hasta cota elementos.
colaP crearColaPrioridadVacia(int cota);

// Retorna la cantidad de elementos de 'cp'.
int cantidadElementos(colaP cp);

// Retorna la cota de elementos de 'cp'.
int cota(colaP cp);

// Inserta el elemento 'x' con una prioridad en 'cp'.
// Pre: cantidadElementos(cp) < cota(cp)
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