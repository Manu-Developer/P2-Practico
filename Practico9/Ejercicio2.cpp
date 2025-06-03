#include "../Practico9/Ejercicio2.h"

#include <stdio.h>
#include <string.h>

struct nodoLista {
    char* caracteres;
    nodoLista* sig;
};

struct nodoHash {
    char* caracteres;
    nodoHash* sig;
};

struct rep_tabla {
    int elementosActuales;
    int elementosEsperados;
    nodoHash** tabla;
};

lista crearLista() {
    lista nuevaLista = NULL;
    return nuevaLista;
}

void insertarString(lista& l, char* caracteres) {
    nodoLista* nuevoNodo = new nodoLista;
    nuevoNodo->caracteres = caracteres;
    nuevoNodo->sig = l;
    l = nuevoNodo;
}

void eliminarString(lista& l, char* caracteres) {
}

int funcionHash(char* caracteres, int largoTabla) {
    int sumaASCII = 0;
    int largo = strlen(caracteres);

    for (int i = 0; i < largo; i++) {
        sumaASCII = sumaASCII + int(caracteres[i]);
    }

    return sumaASCII % largoTabla;
}

tabla crearTabla(int elementosEsperados) {
    tabla nuevaTabla = new rep_tabla;
    nuevaTabla->elementosEsperados = elementosEsperados;
    nuevaTabla->elementosActuales = 0;
    nuevaTabla->tabla = new nodoHash*[elementosEsperados];
    for (int i = 0; i < elementosEsperados; i++) nuevaTabla->tabla[i] = NULL;
    return nuevaTabla;
}

bool esVaciaTabla(tabla t) {
    return t->elementosActuales == 0;
}

bool estaLlenaTabla(tabla t) {
    return t->elementosActuales == t->elementosEsperados;
}

void insertarTabla(tabla& t, char* caracteres) {
    if (t->elementosActuales < t->elementosEsperados) {
        int indiceHash = funcionHash(caracteres, t->elementosEsperados);
        nodoHash* nuevoNodo = new nodoHash;
        nuevoNodo->caracteres = caracteres;
        nuevoNodo->sig = t->tabla[indiceHash];
        t->tabla[indiceHash] = nuevoNodo;
        t->elementosActuales++;
    }
}

void eliminarTabla(tabla& t, char* caracteres) {
    int indiceHash = funcionHash(caracteres, t->elementosEsperados);
    nodoHash* lista = t->tabla[indiceHash];

    if (lista != NULL && strcmp(lista->caracteres, caracteres) == 0) {
        nodoHash* aBorrar = lista;
        t->tabla[indiceHash] = lista->sig;
        delete aBorrar;
        t->elementosActuales--;
        return;
    }

    // Resto de la lista (desde el segundo nodo en adelante)
    nodoHash* actual = lista;
    while (actual != NULL && actual->sig != NULL) {
        if (strcmp(actual->sig->caracteres, caracteres) == 0) {
            nodoHash* aBorrar = actual->sig;
            actual->sig = actual->sig->sig;
            delete aBorrar;
            t->elementosActuales--;
            return;  // eliminar solo una ocurrencia
        }
        actual = actual->sig;
    }
}

bool perteneceString(tabla t, char* caracteres) {
    int indiceHash = funcionHash(caracteres, t->elementosEsperados);
    nodoHash* lista = t->tabla[indiceHash];

    while (lista != NULL && strcmp(lista->caracteres, caracteres) != 0) {
        lista = lista->sig;
    }

    return lista != NULL;
}

void destruirTabla(tabla& t) {
    for (int i = 0; i < t->elementosEsperados; i++) {
        nodoHash* lista = t->tabla[i];
        while (lista != NULL) {
            nodoHash* aBorrar = lista;
            lista = lista->sig;
            delete aBorrar;
            aBorrar = NULL;
        }
    }
    delete[] t->tabla;
    delete t;
    t = NULL;
}

#include <stdio.h>

#include "Ejercicio2.h"

int main() {
    tabla t = crearTabla(5);

    insertarTabla(t, (char*)"hola");
    insertarTabla(t, (char*)"mundo");
    insertarTabla(t, (char*)"tabla");
    insertarTabla(t, (char*)"prueba");

    printf("Pertenece 'mundo'? %s\n", perteneceString(t, (char*)"mundo") ? "Si" : "No");
    printf("Pertenece 'python'? %s\n", perteneceString(t, (char*)"python") ? "Si" : "No");

    printf("Eliminando 'mundo'...\n");
    eliminarTabla(t, (char*)"mundo");

    printf("Pertenece 'mundo'? %s\n", perteneceString(t, (char*)"mundo") ? "Si" : "No");

    printf("Esta llena la tabla? %s\n", estaLlenaTabla(t) ? "Si" : "No");

    destruirTabla(t);

    printf("Tabla destruida.\n");

    return 0;
}