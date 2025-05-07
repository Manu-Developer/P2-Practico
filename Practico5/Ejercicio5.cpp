#include <stdio.h>

struct nodoAG {
    int dato;
    nodoAG *pH;
    nodoAG *sH;
};

typedef nodoAG *AG;

AG arbolHoja(int x) {
    AG nuevaHoja = new nodoAG;
    nuevaHoja->dato = x;
    nuevaHoja->pH = NULL;
    nuevaHoja->sH = NULL;
    return nuevaHoja;
}

bool esArbolHoja(AG arbol) {
    return arbol != NULL && arbol->pH == NULL;
}

bool pertenece(AG arbol, int x) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->dato == x) {
        return true;
    } else {
        return pertenece(arbol->pH, x) || pertenece(arbol->sH, x);
    }
}

AG buscar(AG arbol, int x) {
    if (arbol == NULL) {
        return NULL;
    } else if (arbol->dato == x) {
        return arbol;
    } else {
        AG buscar_hijos = buscar(arbol->pH, x);
        AG buscar_hermanos = buscar(arbol->sH, x);

        if (buscar_hijos != NULL) {
            return buscar_hijos;
        } else {
            return buscar_hermanos;
        }
    }
}

void insertar(AG &arbol, int hermano, int padre) {
    AG nodo_h = buscar(arbol, hermano);
    AG nodo_p = buscar(arbol, padre);

    if (nodo_h == NULL && nodo_p != NULL) {
        nodo_h = new nodoAG;
        nodo_h->dato = hermano;
        nodo_h->pH = NULL;
        nodo_h->sH = nodo_p->pH;
        nodo_p->pH = nodo_h;
    }
}

void insertarV2(AG arbol, int hermano, int padre) {
    if (!pertenece(arbol, hermano)) {
        arbol = buscar(arbol, padre);
        if (arbol != NULL) {
            AG nuevoNodo = new nodoAG;
            nuevoNodo->dato = hermano;
            nuevoNodo->pH = NULL;
            nuevoNodo->sH = arbol->pH;
            arbol->pH = nuevoNodo;
        }
    }
}

void borrar(AG &arbol, int x) {
    if (arbol == NULL || arbol->dato == x) return;  // No borrar si es NULL o raíz

    AG padre = NULL;
    AG actual = arbol->pH;

    // Buscar al nodo y su padre
    while (actual != NULL) {
        if (actual->dato == x) break;
        padre = actual;
        actual = actual->sH;
    }

    // Si lo encontramos y es hoja
    if (actual != NULL && actual->pH == NULL) {
        if (padre == NULL) {
            // Primer hijo del nodo raíz
            arbol->pH = actual->sH;
        } else {
            // Hermano intermedio
            padre->sH = actual->sH;
        }
        delete actual;
    }
}

bool borrarAux(AG &arbol, int x) {
    if (arbol == NULL)
        return false;
    else {
        if (arbol->dato == x) {
            if (esArbolHoja(arbol)) {
                delete arbol;
                arbol = NULL;
            }
            return true;
        } else
            return borrarAux(arbol->pH, x) || borrarAux(arbol->sH, x);
    }
}

void borrarV2(AG arbol, int x) {
    if (arbol != NULL && arbol->dato != x)
        borrarAux(arbol, x);
}

void borrarArbol(AG &arbol) {
    borrarArbol(arbol->pH);
    borrarArbol(arbol->sH);
    delete arbol;
    arbol = NULL;
}

bool borrarSubAux(AG &arbol, int x) {
    if (arbol == NULL)
        return false;
    else {
        if (arbol->dato == x) {
            AG aux = arbol;
            arbol = arbol->sH;
            aux->sH = NULL;
            borrarArbol(aux);
            return true;
        } else
            return borrarSubAux(arbol->pH, x) || borrarSubAux(arbol->sH, x);
    }
}

void borrarSub(AG ag, int x) {
    if (ag != NULL && ag->dato != x)
        borrarSubAux(ag, x);
}

int main() {
    AG nodo1 = new nodoAG;
    AG nodo2 = new nodoAG;
    AG nodo3 = new nodoAG;
    AG nodo4 = new nodoAG;
    AG nodo5 = new nodoAG;
    AG nodo6 = new nodoAG;

    nodo1->dato = 1;
    nodo2->dato = 2;
    nodo3->dato = 3;
    nodo4->dato = 4;
    nodo5->dato = 5;
    nodo6->dato = 6;

    nodo1->pH = nodo2;
    nodo1->sH = NULL;

    nodo2->pH = NULL;
    nodo2->sH = nodo3;

    nodo3->pH = nodo5;
    nodo3->sH = nodo4;

    nodo4->pH = nodo6;
    nodo4->sH = NULL;

    nodo5->pH = NULL;
    nodo5->sH = NULL;

    nodo6->pH = NULL;
    nodo6->sH = NULL;

    printf("%d", nodo6->pH);

    insertar(nodo1, 1000, 6);

    printf("%d", nodo6->pH->dato);

    return 0;
}