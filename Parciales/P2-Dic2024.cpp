#include "../Parciales/P2-Dic2024.h"

#include <stdio.h>

struct nodoHash {
    int cantidadVotos;
    char* listaElectoral;
    nodoHash* sig;
};

struct RepVotacion {
    int cantElems;
    int cantEsperada;
    int cant_mas_votada;
    char* masVotada;
    nodoHash** tabla;
};

int h(char* le, int cota);

Votacion crearVotacion(int cant) {
    Votacion nuevaVotacion = new RepVotacion;
    nuevaVotacion->cantElems = 0;
    nuevaVotacion->cantEsperada = cant;
    nuevaVotacion->tabla = new nodoHash*[cant];
    for (int i = 0; i < cant; i++) {
        nuevaVotacion->tabla[i] = NULL;
    }
    return nuevaVotacion;
}

void insertarVoto(Votacion& v, char* le) {
    int posicion = h(le, v->cantEsperada);
    nodoHash* aux = v->tabla[posicion];
    int votos = 1;

    while (aux != NULL && aux->listaElectoral != le) {
        aux = aux->sig;
    }

    if (aux != NULL) {
        aux->cantidadVotos++;
        votos = aux->cantidadVotos;
    } else {
        nodoHash* nuevoNodo = new nodoHash;
        nuevoNodo->cantidadVotos = 1;
        nuevoNodo->listaElectoral = le;
        nuevoNodo->sig = v->tabla[posicion];
        v->tabla[posicion] = nuevoNodo;
    }

    if (v->cantElems == 0 || votos > v->cant_mas_votada) {
        v->cant_mas_votada = votos;
        v->masVotada = le;
    }

    v->cantElems++;
}

char* masVotada(Votacion v) {
    return v->masVotada;
}

bool indistinguibles(CP cp1, CP cp2) {
    if (esVacia(cp1) || esVacia(cp2))
        return (esVacia(cp1) && esVacia(cp2));
    else {
        CP cp1_copia = copia(cp1);
        CP cp2_copia = copia(cp2);
        bool iguales = true;

        while (iguales && !esVacia(cp1_copia) && !esVacia(cp2_copia))
            iguales = (prioritario(cp1_copia) == prioritario(cp2_copia));

        iguales = iguales && esVacia(cp1_copia) && esVacia(cp2_copia);
        destruir(cp1_copia);
        destruir(cp2_copia);

        return iguales;
    }
}