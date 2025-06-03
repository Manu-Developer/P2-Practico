#ifndef EJ_10
#define EJ_10
#define K 10

struct cabezal;
typedef struct cabezal *colaImpresora;

// Crea y retorna una nueva cola de prioridad vacia.
colaImpresora crearCola();

// Inserta el elemento 'string' con una prioridad en 'ci'.
// Pre: 1<=prioridad<=K
void insertarElemento(colaImpresora &ci, char *string, int prioridad);

// Retorna 'true' si y solo si la cola de prioridad 'ci' es vacia. En caso contrario retorna 'false'.
bool esColaVacia(colaImpresora ci);

// Imprime todos los elementos de la cola 'ci'.
//  Pre: esColaVacia(ci)=false
char *imprimir(colaImpresora &ci);

// Retorna el menor elemento asociado a la cola de prioridad 'ci'.
bool obtenerMinimo(colaImpresora ci, char *string);

// Elimina el elemento 'string' ubicado en la cola de prioridad 'ci'.
// Pre: estaDefinido(ci, string)=true
void borrarMinimo(colaImpresora &ci, char *string);

// Destruye toda la memoria asociada a la cola de prioridad 'ci'.
void destruir(colaImpresora &ci);

#endif
