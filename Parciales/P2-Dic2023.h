struct RepTabla;
typedef RepTabla* Tabla;
typedef unsigned int nat;

// POS: Devuelve la Tabla vacía, sin correspondencias.
Tabla crear();

/* POS: Agrega la correspondencia (d,c) en t, si d no tenía imagen en t. En caso contrario actualiza la imagen de d
con c. */
void insertar(nat d, float c, Tabla& t);

// POS: Devuelve true si y sólo si d tiene imagen en t.
bool definida(nat d, Tabla t);

// POS: Devuelve la cantidad de correspondencias en t. En particular, 0 si t es la tabla vacía.
int cantidad(Tabla t);

// PRE: definida(d,t). POS: Retorna la imagen de d en t.
float recuperar(nat d, Tabla t);

/* POS: Elimina de t la correspondencia que involucra a d, si d está definida en t. En otro caso la operación no
tiene efecto. */
void eliminar(nat d, Tabla& t);

// PRE: cantidad(t)!=0. POS: Retorna el mínimo valor del dominio que tiene imagen en t.
nat minDomino(Tabla t);

// PRE: cantidad(t)!=0. POS: Retorna el máximo valor del dominio que tiene imagen en t.
nat maxDominio(Tabla t);

// POS: Imprime las correspondencias (d,c) de t, ordenadas de mayor a menor por los valores del dominio (d).
void imprimir(Tabla t);