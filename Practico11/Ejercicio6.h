#ifndef EJ_6
#define EJ_6

struct nodoT;
typedef nodoT *T;

// Constructoras //

// Construye el TAD T vacio el cual podra contener hasta K elementos.
T crearTADVacio(int K);

// Inserta el elemento e al TAD t
// Si el TAD ya contiene K elementos, se sobrescribe el mas antiguo.
void insertar(generico e, T &t);

// Selectoras //

// Devuelve el ultimo elemento ingresado en t.
// Pre: !esVacio(t)
generico tope(T t);

// Remueve en t el ultimo elemento ingresado.
void desapilar(T &t);

// Predicados //

// Devuelve true si y solo si el TAD t es vacio, false en caso contrario.
bool esVacio(T t);

// Devuelve true si y solo si el TAD t cuenta con K elementos, false en caso contrario.
bool esLLeno(T t);

// Destructura //

// Libera toda la memoria ocupada por t.
void destruir(T &t);

#endif