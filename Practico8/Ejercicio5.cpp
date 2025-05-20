#include "./Practico8/Ejercicio5.h"

#include <stdio.h>

struct nodo {
    int clave;
    nodo *sig;
};

struct tabla {
    int tamTabla;
    int cantElems;
    nodo *hash;
};
