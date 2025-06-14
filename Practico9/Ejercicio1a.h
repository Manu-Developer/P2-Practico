#ifndef EJ_1
#define EJ_1

struct nodoTabla;
typedef struct nodoTabla *tabla;

// Crea y retorna una tabla vacia no acotada.
tabla crearTablaVacia();

// Devuelve 'true' si y solo si la tabla t es vacia, false en caso contrario.
bool esVaciaTabla(tabla t);

// Inserta el par (d,r) en t.
// Si el valor d ya estaba definido, lo actualiza.
void insertarElemento(int d, int r, tabla &t);

// Devuelve true si y sólo si d tiene imagen en t, false en caso contrario.
bool estaDefinidoElemento(int d, tabla t);

// Elimina el elemento asociado a d en la tabla t.
// Pre: estaDefinidaTabla(d,t).
void eliminarElemento(int d, tabla &t);

// Retorna la imagen de d en t.
// Pre: estaDefinidaTabla(d,t).
int recuperarElemento(int d, tabla t);

#endif