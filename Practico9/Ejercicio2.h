#ifndef EJ_2
#define EJ_2

struct nodoHash;
struct rep_tabla;
struct nodoLista;
typedef struct nodoLista* lista;
typedef struct rep_tabla* tabla;

// Crea y retorna una lista vacia.
lista crearLista();

// Inserta al comienzo de la lista 'l' el string caracteres.
void insertarLista(lista& l, char* caracteres);

// Elimina en la lista 'l' el string caracteres.
// Pre: perteneceTabla(t, caracteres)=true
void eliminarLista(lista& l, char* caracteres);

//---------------------------------------------------------------//

// Crea y retorna una tabla vacia para una cantidad estimada de elementos.
tabla crearTabla(int elementosEsperados);

// Retorna 'true' si y solo si la tabla 't' es vacia, 'false' en caso contrario.
bool esVaciaTabla(tabla t);

// Retorna 'true' si y solo si la tabla 't' esta llena, 'false' en caso contrario.
bool estaLlenaTabla(tabla t);

// Inserta en la tabla 't' el string caracteres.
void insertarTabla(tabla& t, char* caracteres);

// Elimina en la tabla 't' el string caracteres.
// Pre: perteneceTabla(t, caracteres)=true
void eliminarTabla(tabla& t, char* caracteres);

// Retorna 'true' si y solo si el string caracteres se encuentra en la tabla 't', 'false' en caso contrario.
bool perteneceTabla(tabla t, char* caracteres);

// Elimina toda la memoria ocupada por la tabla 't'.
void destruirTabla(tabla& t);

#endif