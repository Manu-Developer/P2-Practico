#include <stdio.h>
#include <string.h>

struct nodoAlumno {
    char *nombre;
    int codigo;
    int *materias;
    char **companeros;
    int topeCompaneros;
    nodoAlumno *izqABB, *derABB, *sigHashNom, *sigHashCod;
};

typedef struct nodoAlumno *ABB;

struct rep_estructura {
    int cota;
    ABB alumnos;
    nodoAlumno **HashNombre;
    nodoAlumno **HashCodigo;
};

typedef struct rep_estructura *estructura;

void inicializarEstructura(estructura &e) {
    e->HashNombre = new nodoAlumno *[e->cota];
    e->HashCodigo = new nodoAlumno *[e->cota];
    for (int i = 0; i < e->cota; i++) {
        e->HashNombre[i] = NULL;
        e->HashCodigo[i] = NULL;
    }
    e->alumnos = NULL;
}