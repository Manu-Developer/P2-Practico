#ifndef EJ_2B
#define EJ_2B

struct rep_conjunto;
typedef struct rep_conjunto *conjunto;

//-------------------------------------------------------------------------------------------------------------------------//
// ¿Qué operación u operaciones se deben agregar/quitar para que la especificación sea del TAD Conjunto acotado de naturales?
//-------------------------------------------------------------------------------------------------------------------------//

// Devuelve el conjunto vacío, con elementos posibles en [0:cota]
conjunto crearConjunto(int cota);

// Retorna true si y sólo si el conjunto c está lleno.
bool estaLlenoConjunto(conjunto c);

// Retorna true si y sólo si el conjunto c está vacío.
bool esVacioConjunto(conjunto c);

// Devuelve true si y sólo si i está en c.
// Pre: 0<=x<=cota (con cota el valor del parámetro en la creación)
bool pertenece(conjunto c, int x);

// Agrega x en c si no estaba. En caso contrario, no tiene efecto.
// Pre: 0<=x<=cota (con cota el valor del parámetro en la creación)
// Pre: !estaLleno(c)
void insertarElemento(conjunto &c, int x);

// Elimina a x de c si estaba. En caso contrario, no tiene efecto.
// Pre: 0<=x<=cota (con cota el valor del parámetro en la creación)
void eliminarElemento(conjunto &c, int x);

// Elimina la memoria asociada al conjunto c.
void destruirConjunto(conjunto &c);

// Retorna un nuevo conjunto la union de los conjuntos c1 y c2.
// Pre: los valores posibles (x) en c1 y c2 cumplen: 0<=x<=cota (con cota el valor del parámetro en la creación)
conjunto unionConjuntos(conjunto c1, conjunto c2);

// Retorna un nuevo conjunto la interseccion de los conjuntos c1 y c2.
// Pre: los valores posibles (x) en c1 y c2 cumplen: 0<=x<=cota (con cota el valor del parámetro en la creación)
conjunto interseccionConjuntos(conjunto c1, conjunto c2);

// Retorna un nuevo conjunto la diferencia de los conjuntos c1 y c2.
// Pre: los valores posibles (x) en c1 y c2 cumplen: 0<=x<=cota (con cota el valor del parámetro en la creación)
conjunto diferenciaConjuntos(conjunto c1, conjunto c2);

#endif
