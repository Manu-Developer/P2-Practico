#include "../Practico11/Ejercicio1.h"

#include <stdio.h>
#include <string.h>

struct nodoHash {
    int posicion;
    const char *pais;
    nodoHash *sig;
};

struct multiFIFA {
    int sigPuesto;
    int cotaPaises;
    nodoHash **tablaHash;
    nodoHash **escala;
};

int funcionHash(const char *nombre, int cotaPaises) {
    int sumaASCII = 0;
    int largoNombre = strlen(nombre);

    for (int i = 0; i < largoNombre; i++) {
        sumaASCII = sumaASCII + int(nombre[i]);
    }

    return sumaASCII % cotaPaises;
}

FIFA crearFIFA(int cotaPaises) {
    FIFA nuevaFIFA = new multiFIFA;
    nuevaFIFA->sigPuesto = 1;
    nuevaFIFA->cotaPaises = cotaPaises;
    nuevaFIFA->tablaHash = new nodoHash *[cotaPaises];
    nuevaFIFA->escala = new nodoHash *[cotaPaises + 1];
    for (int i = 0; i < cotaPaises; i++) {
        nuevaFIFA->tablaHash[i] = NULL;
        nuevaFIFA->escala[i] = NULL;
    }
    return nuevaFIFA;
}

void agregar(const char *pais, FIFA &f) {
    if (f->sigPuesto < f->cotaPaises) {
        int posicionHash = funcionHash(pais, f->cotaPaises);
        nodoHash *nuevoNodo = new nodoHash;
        nuevoNodo->pais = strdup(pais);
        nuevoNodo->posicion = f->sigPuesto;
        nuevoNodo->sig = f->tablaHash[posicionHash];
        f->tablaHash[posicionHash] = nuevoNodo;
        f->escala[f->sigPuesto] = nuevoNodo;
        f->sigPuesto++;
    }
}

const char *rivalDirecto(const char *pais, FIFA f) {
    int posicionHash = funcionHash(pais, f->cotaPaises);
    nodoHash *lista = f->tablaHash[posicionHash];

    while (lista != NULL && strcmp(pais, lista->pais) != 0) {
        lista = lista->sig;
    }

    if (lista != NULL && lista->posicion > 1) {
        return f->escala[lista->posicion - 1]->pais;
    } else {
        return NULL;
    }
}

void intercambia(int i, FIFA &f) {
    nodoHash *nodoVencedor = f->escala[i];
    nodoHash *nodoPerdedor = f->escala[i - 1];
    nodoVencedor->posicion = i - 1;
    nodoPerdedor->posicion = i;
    f->escala[i] = nodoPerdedor;
    f->escala[i - 1] = nodoVencedor;
}

int main() {
    FIFA ranking = crearFIFA(10);

    agregar("Brasil", ranking);
    agregar("Argentina", ranking);
    agregar("Francia", ranking);
    agregar("Alemania", ranking);

    printf("Escala inicial:\n");
    for (int i = 1; i < ranking->sigPuesto; ++i) {
        printf("%d: %s\n", i, ranking->escala[i]->pais);
    }

    const char *rival = rivalDirecto("Francia", ranking);
    if (rival != NULL)
        printf("\nRival directo de Francia: %s\n", rival);
    else
        printf("\nFrancia no tiene rival directo.\n");

    // Intercambiar Francia con Argentina (puestos 3 y 2)
    intercambia(3, ranking);

    printf("\nEscala luego del intercambio entre Francia y Argentina:\n");
    for (int i = 1; i < ranking->sigPuesto; ++i) {
        printf("%d: %s\n", i, ranking->escala[i]->pais);
    }

    return 0;
}