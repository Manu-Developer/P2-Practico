#ifndef EJ_10
#define EJ_10
#define K 10

struct cabezal;
typedef struct cabezal *colaImpresora;

// Crea y retorna una nueva cola de prioridad vacia.
colaImpresora crearCola();

// Inserta el elemento 'string' con una prioridad en 'cp'.
// Pre: 1<=prioridad<=K
void insertarElemento(colaImpresora &cp, char *string, int prioridad);

// Retorna 'true' si y solo si la cola de prioridad 'cp' es vacia. En caso contrario retorna 'false'.
bool esColaVacia(colaImpresora cp);

// Imprime todos los elementos de la cola 'cp'.
//  Pre: esColaVacia(cp)=false
char *imprimir(colaImpresora &cp);

// Retorna 'true' si y solo el elemento 'string' esta definido en la cola de prioridad 'cp'.
bool estaDefinido(colaImpresora cp, char *string);

// Elimina el elemento 'string' ubicado en la cola de prioridad 'cp'.
// Pre: estaDefinido(cp, string)=true
void borrar(colaImpresora &cp, char *string);

// Destruye toda la memoria asociada a la cola de prioridad 'cp'.
void destruir(colaImpresora &cp);

#endif
