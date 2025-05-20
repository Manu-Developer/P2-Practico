#ifndef EJ_10
#define EJ_10

struct nodo_lista;
struct rep_conjunto;
typedef struct nodo_lista *lista;
typedef struct rep_conjunto *conjunto;

// Cuando te pidan una especificación mínima, pensá así:
// ¿Cuáles son las operaciones mínimas que necesito para usar este TAD y resolver el problema?
// Incluí solo esas. Ni más, ni menos.

//  Devuelve el conjunto vacío, con elementos posibles en [0:cota]
conjunto crearConjunto(int cota);

// Devuelve true si y sólo si i está en c.
// Pre: 0<=x<=cota (con cota el valor del parámetro en la creación)
bool pertenece(conjunto c, int x);

// Agrega x en c si no estaba. En caso contrario, no tiene efecto.
// Pre: 0<=x<=cota (con cota el valor del parámetro en la creación)
// Pre: !estaLleno(c)
void insertarElemento(conjunto &c, int x);

// Elimina a x de c si estaba. En caso contrario, no tiene efecto.
// Pre: 0<=x<=cota (con cota el valor del parámetro en la creación)
void eliminarConjunto(conjunto &c, int x);

// Elimina la memoria asociada al conjunto c.
void destruirConjunto(conjunto &c);

#endif
