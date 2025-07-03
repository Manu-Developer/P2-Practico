#include "../Practico11/Ejercicio8.h"

#include <stdio.h>
#include <string.h>

struct rep_PAgrupacion {
    int puntaje;
    char *nombre;
    rep_PAgrupacion *izqABB_agrupacion, *derABB_agrupacion;
    rep_PAgrupacion *sigPuntaje_agrupacion;
};

struct rep_listaPuntos {
    rep_PAgrupacion **arrayPuntajes;
};

struct rep_conCarnaval {
    int maximoPuntaje;
    rep_PAgrupacion *ABB_agrupaciones;
    rep_listaPuntos *listaPuntajes;
};

// Devuelve true si a es lexicográficamente menor que b
bool esMenorLexicografico(const char *nombre1, const char *nombre2) {
    int i = 0;
    while (nombre1[i] != '\0' && nombre2[i] != '\0') {
        if (nombre1[i] < nombre2[i]) {
            return true;
        } else if (nombre1[i] > nombre2[i]) {
            return false;
        }
        i++;
    }
    // Si llegamos al final de uno o ambos strings
    // Si a terminó antes que b, es menor (por ejemplo "abc" < "abcd")
    return nombre1[i] == '\0' && nombre2[i] != '\0';
}

bool sonNombresIguales(const char *nombre1, const char *nombre2) {
    int i = 0;

    while (nombre1[i] != '\0' && nombre2[i] != '\0') {
        if (nombre1[i] != nombre2[i]) {
            return false;
        }
        i++;
    }

    return nombre1[i] == '\0' && nombre2[i] == '\0';
}

conCarnaval crearConcCarnaval(int N) {
    conCarnaval nuevoCarnaval = new rep_conCarnaval;
    nuevoCarnaval->maximoPuntaje = N;
    nuevoCarnaval->ABB_agrupaciones = NULL;
    nuevoCarnaval->listaPuntajes = new rep_listaPuntos;
    nuevoCarnaval->listaPuntajes->arrayPuntajes = new PAgrupacion[N + 1];
    for (int i = 0; i <= N; i++) {
        nuevoCarnaval->listaPuntajes->arrayPuntajes[i] = NULL;
    }
    return nuevoCarnaval;
}

PAgrupacion buscarAsociacion(char *agrupacion, PAgrupacion abb) {
    if (abb == NULL) return NULL;

    if (sonNombresIguales(agrupacion, abb->nombre)) {
        return abb;
    } else if (esMenorLexicografico(agrupacion, abb->nombre)) {
        return buscarAsociacion(agrupacion, abb->izqABB_agrupacion);
    } else {
        return buscarAsociacion(agrupacion, abb->derABB_agrupacion);
    }
}

void insertarEnABB(PAgrupacion &abb, PAgrupacion nuevoGrupo) {
    if (abb == NULL) {
        abb = nuevoGrupo;
    } else if (esMenorLexicografico(nuevoGrupo->nombre, abb->nombre)) {
        insertarEnABB(abb->izqABB_agrupacion, nuevoGrupo);
    } else {
        insertarEnABB(abb->derABB_agrupacion, nuevoGrupo);
    }
}

void asociarAsociacion(char *agrupacion, int puntaje, conCarnaval &c) {
    PAgrupacion busquedaAgrupacion = buscarAsociacion(agrupacion, c->ABB_agrupaciones);

    if (busquedaAgrupacion != NULL) {
        busquedaAgrupacion->puntaje = puntaje;
    } else {
        PAgrupacion nuevoGrupo = new rep_PAgrupacion;
        nuevoGrupo->nombre = new char[strlen(agrupacion) + 1];
        strcpy(nuevoGrupo->nombre, agrupacion);
        nuevoGrupo->puntaje = puntaje;
        nuevoGrupo->izqABB_agrupacion = NULL;
        nuevoGrupo->derABB_agrupacion = NULL;

        // Insertamos el nodo en el ABB
        insertarEnABB(c->ABB_agrupaciones, nuevoGrupo);

        // Insertamos el nodo en el arreglo de listas
        nuevoGrupo->sigPuntaje_agrupacion = c->listaPuntajes->arrayPuntajes[puntaje];
        c->listaPuntajes->arrayPuntajes[puntaje] = nuevoGrupo;
    }
}

bool existeAsociacionABB(const char *agrupacion, PAgrupacion abb) {
    if (abb == NULL) return false;

    if (sonNombresIguales(agrupacion, abb->nombre)) {
        return true;
    } else if (esMenorLexicografico(agrupacion, abb->nombre)) {
        return existeAsociacionABB(agrupacion, abb->izqABB_agrupacion);
    } else {
        return existeAsociacionABB(agrupacion, abb->derABB_agrupacion);
    }
}

bool existeAsociacion(char *agrupacion, conCarnaval c) {
    return existeAsociacionABB(agrupacion, c->ABB_agrupaciones);
}

int puntajeAgrupacionABB(const char *agrupacion, PAgrupacion abb) {
    if (abb == NULL) {
        printf("Error: agrupación no encontrada\n");
    }

    if (sonNombresIguales(agrupacion, abb->nombre)) {
        return abb->puntaje;
    } else if (esMenorLexicografico(agrupacion, abb->nombre)) {
        return puntajeAgrupacionABB(agrupacion, abb->izqABB_agrupacion);
    } else {
        return puntajeAgrupacionABB(agrupacion, abb->derABB_agrupacion);
    }
}

int puntajeAgrupacion(char *agrupacion, conCarnaval c) {
    return puntajeAgrupacionABB(agrupacion, c->ABB_agrupaciones);
}

void imprimirABB(PAgrupacion raiz) {
    if (raiz == NULL) return;
    imprimirABB(raiz->izqABB_agrupacion);
    printf("Grupo: %s | Puntaje: %d\n", raiz->nombre, raiz->puntaje);
    imprimirABB(raiz->derABB_agrupacion);
}

void imprimirAgrupacion(conCarnaval c) {
    imprimirABB(c->ABB_agrupaciones);
}

PAgrupacion listaPuntos(conCarnaval c, int puntaje) {
    return c->listaPuntajes->arrayPuntajes[puntaje];
}