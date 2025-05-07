#ifndef TAD_LISTA_H
#define TAD_LISTA_H

struct cabezal;
typedef struct cabezal* LEnt;

// Crea la lista vacía.
LEnt crearL();

// Inserta el entero x al principio de la lista.
void insertar(int x, LEnt& l);

// Verifica si la lista est á vacía.
bool esVacia(LEnt l);

// Devuelve el primer elemento de una lista.
// Pre: !esVacia(l)
int primero(LEnt l);

// Devuelve la lista l sin su primer elemento.
// Pre: !esVacia (l)
void resto(LEnt& l);

// Inserta el elemento x al final de la lista.
void insFinal(int x, LEnt& l);

#endif