#include "../Practico11/Ejercicio3.h"

#include <stdio.h>
#include <string.h>

struct nodoEmpleado {
    const char* nombre;
    int nroEmpleado;
    int nroSegSocial;
    nodoEmpleado* sigHash_nombre;
    nodoEmpleado* sigHash_nro_empleado;
    nodoEmpleado* sigHash_nro_seg_social;
};

struct rep_estructura {
    int cota;
    int cantidadEmpleados;
    nodoEmpleado** HashNombre;
    nodoEmpleado** HashNroEmpleado;
    nodoEmpleado** HashNroSegSocial;
};

// O(L) peor caso, siendo L la longitud del nombre.
// Si asumimos que el largo del nombre es acotado (constante), se vuelve O(1).
int funcionHash(const char* nombre, int cota) {
    int sumaASCII = 0;
    int largoNombre = strlen(nombre);

    for (int i = 0; i < largoNombre; i++) {
        sumaASCII = sumaASCII + int(nombre[i]);
    }

    return sumaASCII % cota;
}

// O(n) peor caso.
estructura crearEstructura(int k) {
    estructura nuevaEstructura = new rep_estructura;
    nuevaEstructura->cota = k;
    nuevaEstructura->cantidadEmpleados = 0;
    nuevaEstructura->HashNombre = new nodoEmpleado*[k];
    nuevaEstructura->HashNroEmpleado = new nodoEmpleado*[k];
    nuevaEstructura->HashNroSegSocial = new nodoEmpleado*[k];
    for (int i = 0; i < k; i++) {
        nuevaEstructura->HashNombre[i] = NULL;
        nuevaEstructura->HashNroEmpleado[i] = NULL;
        nuevaEstructura->HashNroSegSocial[i] = NULL;
    }
    return nuevaEstructura;
}

// O(1) peor caso.
bool estaLLenaEstructura(estructura e) {
    return e->cantidadEmpleados >= e->cota;
}

// O(1) caso promedio.
void ingresarEmpleado(estructura& e, const char* nombre, int nroSegSocial, int nroEmpleado) {
    if (!estaLLenaEstructura(e)) {
        int indiceHash = funcionHash(nombre, e->cota);
        nodoEmpleado* nuevoEmpleado = new nodoEmpleado;
        nuevoEmpleado->nombre = strdup(nombre);
        nuevoEmpleado->nroSegSocial = nroSegSocial;
        nuevoEmpleado->nroEmpleado = nroEmpleado;

        nuevoEmpleado->sigHash_nombre = e->HashNombre[indiceHash];
        e->HashNombre[indiceHash] = nuevoEmpleado;

        nuevoEmpleado->sigHash_nro_empleado = e->HashNroEmpleado[indiceHash];
        e->HashNroEmpleado[indiceHash] = nuevoEmpleado;

        nuevoEmpleado->sigHash_nro_seg_social = e->HashNroSegSocial[indiceHash];
        e->HashNroSegSocial[indiceHash] = nuevoEmpleado;

        e->cantidadEmpleados++;
    }
}

// O(1) caso promedio.
int obtenerNroSegSocial(estructura e, const char* nombre) {
    int indice = funcionHash(nombre, e->cota);
    nodoEmpleado* actual = e->HashNombre[indice];
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Nombre de empleado: %s | Numero de Seguridad Social: %d\n", actual->nombre, actual->nroSegSocial);
            return actual->nroSegSocial;
        }
        actual = actual->sigHash_nombre;
    }
    return -1;  // No encontrado
}

// O(1) caso promedio.
int obtenerNroEmpleado(estructura e, const char* nombre) {
    int indice = funcionHash(nombre, e->cota);
    nodoEmpleado* actual = e->HashNombre[indice];
    while (actual != NULL) {
        if (strcmp(actual->nombre, nombre) == 0) {
            printf("Nombre de empleado: %s | Numero de Empleado: %d\n", actual->nombre, actual->nroEmpleado);
            return actual->nroEmpleado;
        }
        actual = actual->sigHash_nombre;
    }
    return -1;  // No encontrado
}

// ¿Podemos suponer que la funcion de hash ingresa a los empleados de forma ordenada segun su nombre?
void imprimirEmpleados(estructura e) {
    for (int i = 0; i < e->cota; i++) {
        nodoEmpleado* aux = e->HashNombre[i];
        while (aux != NULL) {
            printf("Nombre de empleado: %s\n", aux->nombre);
            aux = aux->sigHash_nombre;
        }
    }
}