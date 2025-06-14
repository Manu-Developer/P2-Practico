#include "../Practico11/Ejercicio5.h"

#include <stdio.h>

struct TInfo {
    int elemento;
    int prioridad;
    TInfo *anterior;
    TInfo *siguiente;
};

struct nodoCP {
    TInfo *inicio;
    TInfo *final;
    TInfo *menorPrioridad;
};

typedef struct nodoCP *colaP;

// Crea y retorna una nueva cola de prioridad vacía.
colaP crearColaPrioridadVacia() {
    colaP nuevaCP = new nodoCP;
    nuevaCP->inicio = NULL;
    nuevaCP->final = NULL;
    nuevaCP->menorPrioridad = NULL;
    return nuevaCP;
}

// Inserta el 'elemento' con 'prioridad' al final de la cola.
// No recorre la cola. FIFO garantizado para prioridades iguales.
void insertarElemento(colaP &cp, int elemento, int prioridad) {
    TInfo *nuevo = new TInfo;
    nuevo->elemento = elemento;
    nuevo->prioridad = prioridad;
    nuevo->anterior = cp->final;
    nuevo->siguiente = NULL;

    if (cp->final != NULL) {
        cp->final->siguiente = nuevo;
    } else {
        cp->inicio = nuevo;
    }

    cp->final = nuevo;

    // Si es el primer nodo o tiene menor prioridad, actualizar menorPrioridad.
    if (cp->menorPrioridad == NULL || prioridad < cp->menorPrioridad->prioridad) {
        cp->menorPrioridad = nuevo;
    }
}

// Retorna true si la cola está vacía.
bool esColaVacia(colaP cp) {
    return cp == NULL || cp->inicio == NULL;
}

// Retorna el elemento con menor prioridad numérica.
// Pre: !esColaVacia(cp)
TInfo obtenerMinimo(colaP cp) {
    return *(cp->menorPrioridad);
}

// Elimina el elemento con menor prioridad.
// Pre: !esColaVacia(cp)
void borrarMinimo(colaP &cp) {
    if (cp == NULL || cp->menorPrioridad == NULL) return;

    TInfo *aBorrar = cp->menorPrioridad;

    if (aBorrar->anterior != NULL)
        aBorrar->anterior->siguiente = aBorrar->siguiente;
    else
        cp->inicio = aBorrar->siguiente;

    if (aBorrar->siguiente != NULL)
        aBorrar->siguiente->anterior = aBorrar->anterior;
    else
        cp->final = aBorrar->anterior;

    delete aBorrar;

    // Recalcular menorPrioridad
    cp->menorPrioridad = cp->inicio;
    for (TInfo *aux = cp->inicio; aux != NULL; aux = aux->siguiente) {
        if (aux->prioridad < cp->menorPrioridad->prioridad) {
            cp->menorPrioridad = aux;
        }
    }
}

// Libera la memoria asociada a la cola.
void destruir(colaP &cp) {
    TInfo *actual = cp->inicio;
    while (actual != NULL) {
        TInfo *sig = actual->siguiente;
        delete actual;
        actual = sig;
    }
    delete cp;
    cp = NULL;
}