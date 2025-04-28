#include <stdio.h>

struct nodoAG {
    int dato;
    nodoAG *pH;
    nodoAG *sH;
};

typedef nodoAG *AG;

AG copiaParcial(AG arbol, int k) {
    AG copia = NULL;

    if (arbol != NULL && k > 0) {
        copia = new nodoAG;
        copia->dato = arbol->dato;
        copia->pH = copiaParcial(arbol->pH, k - 1);
        copia->sH = copiaParcial(arbol->sH, k);
    }

    return copia;
}

int main() {
    return 0;
}