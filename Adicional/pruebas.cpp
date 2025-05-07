#include <stdio.h>

struct nodo {
    int dato;
    nodo* izq;
    nodo* der;
};

struct nodo2 {
    int dato;
    nodo2* sig;
};

typedef nodo* AB;
typedef nodo2* lista;

void insertar(lista& l, int x) {
    if (l == NULL || l->dato != x) {
        lista nuevoNodo = new nodo2;
        nuevoNodo->dato = x;
        nuevoNodo->sig = l;
        l = nuevoNodo;
    }
}

lista intercalar(int* array1, int* array2, int n, int m) {
    // n es el largo del array1 y m es el largo del array2

    lista resultado = NULL;

    while (n > 0 && m > 0) {
        if (array1[n - 1] >= array2[m - 1]) {
            insertar(resultado, array1[n - 1]);
            n--;
        } else {
            insertar(resultado, array2[m - 1]);
            m--;
        }
    }

    while (n > 0) {
        insertar(resultado, array1[n - 1]);
        n--;
    }

    while (m > 0) {
        insertar(resultado, array2[m - 1]);
        m--;
    }

    return resultado;
}

void imprimirLista(lista l) {
    while (l != NULL) {
        printf("%d ", l->dato);
        l = l->sig;
    }
    printf("\n");
}

AB copiaRec(AB t) {
    if (t == NULL)
        return NULL;
    else {
        AB copia = new nodo;
        copia->dato = t->dato;
        copia->der = copiaRec(t->der);
        copia->izq = copiaRec(t->izq);
        return copia;
    }
}

AB copiaSubArbol(AB t, int x) {
    if (t == NULL) return NULL;
    AB resultado = NULL;

    if (t->dato == x) {
        resultado = copiaRec(t);
        return resultado;
    } else if (copiaSubArbol(t->izq, x) != NULL) {
        return copiaSubArbol(t->izq, x);
    } else {
        return copiaSubArbol(t->der, x);
    }
}

int main() {
    int array1[] = {2, 4, 4, 4, 6, 7, 9, 10, 11, 13, 15};
    int array2[] = {1, 2, 3, 4, 8, 8, 13, 22};

    lista prueba = intercalar(array1, array2, 11, 8);
    imprimirLista(prueba);
    return 0;
}