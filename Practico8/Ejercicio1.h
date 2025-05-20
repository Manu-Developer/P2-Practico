#ifndef EJ_1
#define EJ_1

struct rep_conjunto;
typedef rep_conjunto *conjunto;

// Devuelve el conjunto vacío para una cantidad estimada cota.
conjunto crearConjunto(int cota);

// Agrega i en c, si no estaba. En caso contrario, no tiene efecto.
void insertarConjunto(int i, conjunto &c);

// Elimina i de c, si estaba. En caso contrario, no tiene efecto.
void eliminarConjunto(int i, conjunto &c);

// Devuelve true si y sólo si i está en c.
bool perteneceConjunto(int i, conjunto c);

// Devuelve true si y sólo si c es vacío.
bool esVacioConjunto(conjunto c);

// Devuelve true si y sólo si c esta lleno.
bool esLlenoConjunto(conjunto c);

// Libera toda la memoria ocupada por c.
void destruirConjunto(conjunto &c);

#endif