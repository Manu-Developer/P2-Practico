typedef struct nodo *LDig;

typedef unsigned int Digito;

/* Crea la lista de dígitos vacía */
LDig crear();

/* Inserta un elemento al principio de la lista de dígitos */
void cons(Digito x, LDig &l);

/* Devuelve true si y solo si la lista de dígitos esta vacía */
bool esVacia(LDig l);

/* Devuelve el primer elemento de la lista de dígitos.
Precondición: la lista no es vacía.*/
Digito primero(LDig l);

/* Devuelve la lista de dígitos sin su primer elemento.
Precondición: la lista no es vacía.*/
LDig resto(LDig l);

/*  Imprime la lista de digitos. */
void imprimirLista(LDig l);

/* Devuelve la lista de dígitos que representa al número natural resultado de sumar los dos números naturales parámetros representados mediante listas de dígitos. */
LDig suma(LDig l1, LDig l2);
