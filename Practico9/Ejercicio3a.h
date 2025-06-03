#ifndef EJ_3A
#define EJ_3A

struct nodoArbol {
    int dominio;
    float codominio;
    nodoArbol* izq;
    nodoArbol* der;
};

typedef struct nodoArbol* arbol;

// Crea y retorna un nuevo arbol vacio.
arbol crearArbol();

// Retorna el nodo asociado al dominio 'd' del arbol 't';
arbol recuperarNodo(arbol t, int d);

// Retorna 'true' si y solo si el arbol 't' contiene al elemento con dominio 'd', 'false' en caso contrario.
bool perteneceArbol(arbol t, int d);

// Inserta el dominio 'd' y codominio 'd' en el arbol 't'. En caso de estar ya definido 'd' se sobrescribe el codominio 'c'.
void insertarArbol(arbol& t, int d, int c);

// Elimina el nodo 'd' del arbol 't'.
// Pre: perteneceNodo(t, d)=true;
void eliminarArbol(arbol& t, int d);

// Elimina toda la memoria asociada al arbol 't';
void liberarArbol(arbol& t);

#endif