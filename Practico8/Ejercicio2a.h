#ifndef EJ_2A
#define EJ_2A

struct rep_conjunto;
typedef struct rep_conjunto *conjunto;

// Devuelve el Conjunto vacío.
conjunto crearConjunto();

// Agrega x en c si no estaba. En caso contrario, no tiene efecto.
// Pre: x no esta en c.
void insertarElemento(conjunto &c, int x);

// Retorna true si y sólo si el conjunto c está vacío.
bool esVacioConjunto(conjunto c);

// Retorna true si y sólo si el elemento x está en c.
bool pertenece(conjunto c, int x);

// Elimina al elemento x del conjunto c si es que estaba. En caso contrario, no tiene efecto.
// Pre: x esta en c.
void eliminarConjunto(conjunto c, int x);

// Destruye el conjunto c, liberando su memoria.
void destruirConjunto(conjunto c);

// Retorna un nuevo conjunto la union de los conjuntos c1 y c2.
conjunto unionConjuntos(conjunto c1, conjunto c2);

// Retorna un nuevo conjunto la interseccion de los conjuntos c1 y c2.
conjunto interseccionConjuntos(conjunto c1, conjunto c2);

// Retorna un nuevo conjunto la diferencia de los conjuntos c1 y c2.
conjunto diferenciaConjuntos(conjunto c1, conjunto c2);

#endif