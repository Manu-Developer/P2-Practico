#ifndef EJ_7
#define EJ_7

struct nodoLista;
typedef struct nodoLista *multiconjunto;

// Devuelve el multiconjunto vacío no acotado.
multiconjunto crearConjunto();

// Retorna true si y sólo si el multiconjunto c está vacío.
bool esVacioConjunto(multiconjunto c);

// Retorna un puntero al nodo de la lista que contenga 'x', en caso de no encontrarlo retorna 'NULL'.
nodoLista *obtenerElemento(multiconjunto c, int x);

// Agrega x en c si no estaba. En caso contrario, solo incrementa la cantidad de repeticiones de 'x'.
void insertarElemento(multiconjunto &c, int x);

// Elimina a x de c si estaba. En caso contrario, no tiene efecto.
void eliminarElemento(multiconjunto &c, int x);

// Elimina la memoria asociada al multiconjunto c.
void destruirConjunto(multiconjunto &c);

// Retorna un nuevo multiconjunto con la union de los multiconjuntos c1 y c2.
multiconjunto unionMultiConjuntos(multiconjunto c1, multiconjunto c2);

// Retorna un nuevo multiconjunto con la interseccion de los multiconjuntos c1 y c2.
multiconjunto interseccionMultiConjuntos(multiconjunto c1, multiconjunto c2);

// Retorna un nuevo multiconjunto con la diferencia de los multiconjuntos c1 y c2.
multiconjunto diferenciaMultiConjuntos(multiconjunto c1, multiconjunto c2);

#endif
