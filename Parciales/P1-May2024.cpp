#include <stdio.h>

struct nodoLista {
    int persona;
    nodoLista* sig;
};

typedef nodoLista* Lista;

struct nodoABB {
    int dato;
    nodoABB* izq;
    nodoABB* der;
};

typedef nodoABB* ABB;

struct nodoAG {
    int dato;
    nodoAG* pH;
    nodoAG* sH;
};

typedef nodoAG* AG;

// Sea n la cantidad de nodos dentro del ABB.
// El peor caso es O(n), ya que el camino al mínimo puede involucrar a todos los nodos del árbol (árbol degenerado hacia la izquierda). Sobre cada nodo las acciones involucradas son de O(1).
// El caso promedio es O(log2(n)), ya que en promedio la altura del árbol es log2(n). Luego, el camino más hacia la izquierda tiene en promedio log2(n) nodos. Sobre cada nodo las acciones involucradas son de O(1).

int delMin(ABB& t) {
    if (t->izq == NULL) {
        int menorElemento = t->dato;
        ABB aBorrar = t;
        t = t->der;
        delete aBorrar;
        return menorElemento;
    } else {
        delMin(t->izq);
    }
}

int masVotada(Lista& l, int m) {
    int* arrayAux = new int[m + 1];
    for (int i = 0; i <= m; i++) {
        arrayAux[i] = 0;
    }

    while (l != NULL) {
        arrayAux[l->persona]++;
        Lista aBorrar = l;
        l = l->sig;
        delete aBorrar;
    }

    int elementoMax = arrayAux[0];
    for (int i = 0; i < m + 1; i++) {
        if (arrayAux[i] > elementoMax) {
            elementoMax = arrayAux[i];
        }
    }

    delete[] arrayAux;
    return elementoMax;
}

int nivel(AG t, int x) {
    if (t == NULL)
        return 0;
    else if (t->dato == x)
        return 1;
    else {
        int resultado = nivel(t->pH, x);
        if (resultado > 0)
            return 1 + resultado;
        else
            return nivel(t->sH, x);
    }
}

int main() {
    Lista l1 = new nodoLista;
    l1->persona = 1;
    Lista l2 = new nodoLista;
    l2->persona = 4;
    Lista l3 = new nodoLista;
    l3->persona = 2;
    Lista l4 = new nodoLista;
    l4->persona = 4;
    Lista l5 = new nodoLista;
    l5->persona = 2;
    Lista l6 = new nodoLista;
    l6->persona = 2;
    Lista l7 = new nodoLista;
    l7->persona = 3;
    Lista l8 = new nodoLista;
    l8->persona = 2;
    Lista l9 = new nodoLista;
    l9->persona = 8;
    Lista l10 = new nodoLista;
    l10->persona = 2;

    l1->sig = l2;
    l2->sig = l3;
    l3->sig = l4;
    l4->sig = l5;
    l5->sig = l6;
    l6->sig = l7;
    l7->sig = l8;
    l8->sig = l9;
    l9->sig = l10;
    l10->sig = NULL;

    int m = 9;  // valor máximo posible en la lista
    int votosMax = masVotada(l1, m);
    printf("%d", votosMax);

    return 0;
}