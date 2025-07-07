#include <stdio.h>

struct nodoLista {
    int elem;
    nodoLista *sig;
};

typedef nodoLista *Lista;

struct nodoAG {
    int elem;
    nodoAG *pH, *sH;
};

typedef nodoAG *AG;

bool esPrefijo(Lista prefijo, AG ag) {
    if (prefijo == NULL)
        return true;
    else if (ag == NULL)
        return false;
    else if (prefijo->elem == ag->elem)
        return esPrefijo(prefijo->sig, ag->pH);
    else
        return esPrefijo(prefijo, ag->sH);
}

int main() {
    return 0;
}