#ifndef EJ_8
#define EJ_8

struct nodoUrna;
typedef struct nodoUrna* urna;

// Crea y retorna una nueva urna vacia no acotada.
// urnaVacia: O(n) por la inicialización del array
urna urnaVacia();

// Agrega a la urna un voto para ese candidato.
// O(1) peor caso
void insertarVoto(urna& u, int candidato);

// Devuelve la cantidad de votos para ese candidato que están en la urna.
// O(1) peor caso
int cantVotos(urna u, int candidato);

#endif