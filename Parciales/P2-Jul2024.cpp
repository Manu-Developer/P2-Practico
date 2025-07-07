#include "../Parciales/P2-Jul2024.h"

#include <stdio.h>

// Problema 1

Tabla unionTablas(Tabla t1, Tabla t2) {
    Tabla resultado = copia(t1, cantidad(t1) + cantidad(t2) + 1);
    Tabla copiaT2 = copia(t2, cantidad(t2));
    int valorMin;
    float img_ValorMin;

    while (cantidad(copiaT2) > 0) {
        valorMin = minimo(copiaT2);
        img_ValorMin = recuperar(valorMin, copiaT2);
        if (!pertenece(valorMin, resultado)) {
            insertar(valorMin, img_ValorMin, resultado);
        } else if (pertenece(valorMin, resultado) && recuperar(valorMin, resultado) != recuperar(valorMin, copiaT2)) {
            eliminar(valorMin, resultado);
        }
        eliminar(valorMin, copiaT2);
    }

    destruir(copiaT2);
    return resultado;
}

// Problema 2A

int h(int clave, int cota);

struct nodoHash {
    int dominio;
    float imagen;
    nodoHash* sig;
};

struct repTabla {
    int minimo;
    int cantElems;
    int cantEsperada;
    nodoHash** tabla;
};

Tabla crear(int cota) {
    Tabla nuevaTabla = new repTabla;
    nuevaTabla->cantElems = 0;
    nuevaTabla->cantEsperada = cota;
    nuevaTabla->tabla = new nodoHash*[cota];
    for (int i = 0; i < cota; i++) {
        nuevaTabla->tabla[i] = NULL;
    }
    return nuevaTabla;
}

void insertar(int d, float i, Tabla& t) {
    if (!pertenece(d, t)) {
        int posicion = h(d, t->cantEsperada);
        nodoHash* nodoNuevo = new nodoHash;
        nodoNuevo->dominio = d;
        nodoNuevo->imagen = i;
        nodoNuevo->sig = t->tabla[posicion];
        t->tabla[posicion] = nodoNuevo;
        if (t->cantElems == 0 || d < t->minimo) {
            t->minimo = d;
        }
        t->cantElems++;
    }
}

int minimo(Tabla t) {
    return t->minimo;
}

// Problema 2B

struct nodoAVL {
    int dom;
    float img;
    int altura;
    nodoAVL* izq;
    nodoAVL* der;
};

struct repTabla {
    int cantElems;
    nodoAVL* arbol;
};

float recuperarAux(int d, nodoAVL* raiz) {
    if (raiz->dom == d) {
        return raiz->img;
    } else if (d < raiz->dom) {
        return recuperarAux(d, raiz->izq);
    } else {
        return recuperarAux(d, raiz->der);
    }
}

float recuperar(int d, Tabla t) {
    return recuperarAux(d, t->arbol);
}

nodoAVL* copiaAVL(nodoAVL* arb) {
    if (arb == NULL)
        return NULL;
    else {
        nodoAVL* res = new nodoAVL;
        res->dom = arb->dom;
        res->img = arb->img;
        res->altura = arb->altura;
        res->izq = copiaAVL(arb->izq);
        res->der = copiaAVL(arb->der);
        return res;
    }
}

Tabla copia(Tabla t, int cota) {
    Tabla res = new repTabla;
    res->arbol = copiaAVL(t->arbol);
    res->cantElems = t->cantElems;
    return res;
}
