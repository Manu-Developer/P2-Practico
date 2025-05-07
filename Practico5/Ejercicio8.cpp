#include <stdio.h>

struct par {
    int max, her;
};

struct nodoAG {
    int elem;
    nodoAG *pH, *sH;
};

typedef nodoAG *AG;

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

par mayorAmplitudAux(AG arbol) {
    par res;
    if (arbol == NULL)
        res.max = res.her = 0;
    else {
        par res_pH = mayorAmplitudAux(arbol->pH);
        par res_sH = mayorAmplitudAux(arbol->sH);
        res.max = max(res_pH.max, res_sH.max);
        res.max = max(res.max, res_pH.her);
        res.her = res_sH.her + 1;
    }
    return res;
}

int mayorAmplitud(AG arbol) {
    par res = mayorAmplitudAux(arbol);
    return res.max;
}