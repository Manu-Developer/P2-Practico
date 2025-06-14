#include <stdio.h>

struct rep_heap {
    int tope;
    int *arreglo;
};

typedef struct rep_heap *heap;

bool buscarEnHeap(int elemento, heap h, int indice) {
    // Si el índice está fuera del rango del heap, no hay nada que buscar
    if (indice >= h->tope) {
        return false;
    }

    // Si el valor en la posición actual es mayor que el buscado, no puede estar en esta rama (heap mínimo)
    if (h->arreglo[indice] > elemento) {
        return false;
    }

    // Si encontramos el elemento, retornamos true
    if (h->arreglo[indice] == elemento) {
        return true;
    }

    // Buscar en los hijos izquierdo y derecho
    return buscarEnHeap(elemento, h, 2 * indice) || buscarEnHeap(elemento, h, 2 * indice + 1);
}

// En el peor caso: O(n) (si todos los elementos son iguales o menores que x)
// En el mejor caso: O(log n) o incluso mejor, si se podan muchas ramas rápidamente.