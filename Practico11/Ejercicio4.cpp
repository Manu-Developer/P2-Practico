#include <stdio.h>
#include <string.h>

struct nodoAlumno {
    char *codigo;
    char *nombre;
    char **compas;  // Arrays de char*
    int topeCompas;
    int *materias;  // Array de materias
    nodoAlumno *izqABB, *derABB, *sigHashNom, *sigHashCod;
};

struct rep_alumnos {
    int maxCompas;         // K
    int maxAlumnos;        // M
    int maxCodigoMateria;  // L
    nodoAlumno *abbAlumnos;
    nodoAlumno **HashNombre;  // Array de punteros a nodoAlumno
    nodoAlumno **HashCodigo;  // Array de punteros a nodoAlumno
};

typedef struct rep_alumnos *alumnos;

alumnos crearAlumnos(int l, int k, int m) {
    alumnos nueva = new rep_alumnos;
    nueva->HashNombre = new nodoAlumno *[m];
    nueva->HashCodigo = new nodoAlumno *[m];
    for (int i = 0; i < m; i++) {
        nueva->HashNombre[i] = NULL;
        nueva->HashCodigo[i] = NULL;
    }
    nueva->abbAlumnos = NULL;
    nueva->maxCompas = k;
    nueva->maxAlumnos = m;
    nueva->maxCodigoMateria = l;
    return nueva;
}

int hashNom(char *nombre);
int hashCod(char *nombre);

void insertarABB(nodoAlumno *nuevoAlumno, nodoAlumno *abbAlumnos);

void agregarAlumno(alumnos &a, char *nombre, char *codigo) {
    int posicionNom = hashNom(nombre);
    int posicionCod = hashCod(codigo);

    nodoAlumno *iterNom = a->HashNombre[posicionNom];
    while (iterNom != NULL && iterNom->nombre != nombre) {
        iterNom = iterNom->sigHashNom;
    }

    if (iterNom == NULL) {
        nodoAlumno *iterCod = a->HashCodigo[posicionCod];
        while (iterCod != NULL && iterCod->codigo != codigo) {
            iterCod = iterCod->sigHashCod;
        }

        if (iterCod == NULL) {
            nodoAlumno *nuevoAlumno = new nodoAlumno;
            nuevoAlumno->nombre = nombre;
            nuevoAlumno->codigo = codigo;
            nuevoAlumno->compas = new char *[a->maxCompas];
            nuevoAlumno->topeCompas = 0;
            nuevoAlumno->materias = new int[a->maxCodigoMateria + 1];

            for (int i = 0; i < a->maxCodigoMateria; i++) {
                nuevoAlumno->materias[i] = -1;
            }

            nuevoAlumno->sigHashNom = a->HashNombre[posicionNom];
            a->HashNombre[posicionNom] = nuevoAlumno;

            nuevoAlumno->sigHashCod = a->HashCodigo[posicionCod];
            a->HashCodigo[posicionCod] = nuevoAlumno;

            insertarABB(nuevoAlumno, a->abbAlumnos);
        } else {
            printf("ERROR");
        }
    } else {
        printf("ERROR");
    }
}