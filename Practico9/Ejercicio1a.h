#ifndef EJ_1
#define EJ_1

struct nodoTabla;
typedef struct nodoTabla *tabla;

// Crea una tabla vacia no acotada.
tabla crearTablaVacia();

// Devuelve 'true' si y solo si la tabla 't' es vacia, false en caso contrario.
bool esVaciaTabla(tabla t);

// Agrega la correspondencia (d,r) en t, si d no tenia imagen en t.
void insertarElemento(int d, int r, tabla &t);

// // Devuelve true si y sólo si d tiene imagen en t, false en caso contrario.
bool estaDefinidoElemento(int d, tabla t);

// Elimina 'T(d)' si es que estaba previamente definido, en caso de no estarlo la funcion no tiene efecto.
void eliminarElemento(int d, tabla &t);

// Retorna la imagen de d en t.
// Pre: estaDefinidaTabla(d,t).
int recuperarElemento(int d, tabla t);

#endif