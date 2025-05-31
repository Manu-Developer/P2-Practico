#ifndef EJ_8
#define EJ_8

struct nodoUrna;
typedef struct nodoUrna* urna;

// Crea y retorna una nueva urna vacia no acotada.
// O(1) peor caso
urna urnaVacia();

// Agrega a la urna un voto para ese candidato.
// O(1) peor caso
void insertarVoto(urna& u, const char* candidato);

// Devuelve la cantidad de votos para ese candidato que están en la urna.
// O(n) peor caso
int cantVotos(urna u, const char* candidato);

#endif