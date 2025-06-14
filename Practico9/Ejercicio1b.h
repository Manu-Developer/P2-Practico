#ifndef EJ_1
#define EJ_1

struct rep_tabla;
typedef struct rep_tabla *tabla;

// Crea una tabla vacia acotada.
tabla crearTablaVacia(int cota);

// Devuelve 'true' si y solo si la tabla 't' es vacia, false en caso contrario.
bool esVaciaTabla(tabla t);

// Devuelve 'true' si y solo si la tabla 't' tiene 'cota' elementos, false en caso contrario.
bool esLlenaTabla(tabla t);

// Retorna la cantidad de elementos dentro de la tabla 't'.
int cantidadElementosTabla(tabla t);

// Inserta el par (d,r) en t.
// Si el valor d ya estaba definido, lo actualiza.
// Pre: !estaLlenaTabla(t) || estaDefinidoElemento(d,t)
void insertarElemento(int d, int r, tabla &t);

// // Devuelve true si y sólo si d tiene imagen en t, false en caso contrario.
bool estaDefinidoElemento(int d, tabla t);

// Elimina el elemento asociado a d en la tabla t.
// Pre: estaDefinidaTabla(d,t).
void eliminarElemento(int d, tabla &t);

// Retorna la imagen de d en t.
// Pre: estaDefinidaTabla(d,t).
int recuperarElemento(int d, tabla t);

#endif