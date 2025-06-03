#include <stdio.h>

#include "../Practico9/Ejercicio3a.h"

// Tengo que ver como no acceder a la representacion de la tabla.
// 'arbol' es lo mismo que tabla.

arbol consolidar(arbol t1, arbol t2, unsigned int inf, unsigned int sup) {
    arbol nuevaTabla = crearArbol();

    if (t1 != NULL) {
        if (t1->dominio >= inf && t1->dominio <= sup) {
            insertarArbol(nuevaTabla, t1->dominio, t1->codominio);
        }

        // Necesito guardar estas variables por que el nodo raiz puede no llegar a cumplir la propiedad de infimos y supremos, pero sus nodos hijos si pueden llegar a cumplir dichas propiedades.
        arbol izq = consolidar(t1->izq, NULL, inf, sup);
        arbol der = consolidar(t1->der, NULL, inf, sup);

        if (izq != NULL) {
            insertarArbol(nuevaTabla, izq->dominio, izq->codominio);
        }
        if (der != NULL) {
            insertarArbol(nuevaTabla, der->dominio, der->codominio);
        }
    }

    if (t2 != NULL) {
        if (t2->dominio >= inf && t2->dominio <= sup) {
            if (perteneceArbol(nuevaTabla, t2->dominio)) {
                nodoArbol *nodoRecuperado = recuperarNodo(nuevaTabla, t2->dominio);
                nodoRecuperado->codominio = nodoRecuperado->codominio + t2->codominio;
            } else {
                insertarArbol(nuevaTabla, t2->dominio, t2->codominio);
            }
        }

        // Necesito guardar estas variables por que el nodo raiz puede no llegar a cumplir la propiedad de infimos y supremos, pero sus nodos hijos si pueden llegar a cumplir dichas propiedades.
        arbol izq = consolidar(t2->izq, NULL, inf, sup);
        arbol der = consolidar(t2->der, NULL, inf, sup);

        if (izq != NULL) {
            insertarArbol(nuevaTabla, izq->dominio, izq->codominio);
        }
        if (der != NULL) {
            insertarArbol(nuevaTabla, der->dominio, der->codominio);
        }
    }

    return nuevaTabla;
}