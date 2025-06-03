#ifndef EJ_8
#define EJ_8

struct RepresentacionMultiset;
typedef RepresentacionMultiset* Multiset;

// ¿O(log(n)) en el caso promedio se refiere a un ABB? Porque un AVL es muy complicado.

// POS : Devuelve el multiset vacío.
Multiset crear();

// POS : Agrega n ocurrencias del elemento x al multiset m.
// PRE : n >0.
void insertar(Multiset& m, int x, int n);

// POS : Devuelve la cantidad total de elementos del multiset m (0 si m est á vacío).
int cantidad(Multiset m);

// POS : Devuelve la cantidad de ocurrencias del elemento x del Multiset m (0 si x no est á en m).
int ocurrencias(Multiset m, int x);

/* POS : Elimina a lo sumo n ocurrencia del elemento x del multiset m.
Si ocurrencias (m, x) <=n entonces en m no quedar án ocurrencias del elemento x, y se liberar á la memoria correspondiente. */
void eliminar(Multiset& m, int x, int n);

// POS: Retorna el mínimo elemento del multiset m ( independientemente del número de ocurrencias ).
// PRE: m no vacío.
int min(Multiset m);

// POS: Retorna el máximo elemento del multiset m (independientemente del número de ocurrencias ).
// PRE: m no vacío.
int max(Multiset m);

// POS: Elimina todos los elementos de m, dejando a éste vacío.
void vaciar(Multiset& m);

#endif