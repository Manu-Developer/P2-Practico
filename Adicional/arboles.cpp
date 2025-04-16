#include <stdio.h>

struct nodoAB {
    int dato;
    nodoAB *derecha;
    nodoAB *izquierda;
    nodoAB *padre;
};

typedef nodoAB *AB;

AB crearNodo(int n, AB padre) {
    AB nuevoNodo = new nodoAB;
    nuevoNodo->dato = n;
    nuevoNodo->derecha = NULL;
    nuevoNodo->izquierda = NULL;
    return nuevoNodo;
}

void insertarNodo(AB &arbol, int n, AB padre) {
    if (arbol == NULL) {  // Si el arbol esta vacio.
        AB nuevoNodo = crearNodo(n, padre);
        arbol = nuevoNodo;
    } else {  // Si el arbol tiene un nodo o mas.
        if (n < arbol->dato) {
            insertarNodo(arbol->izquierda, n, arbol);
        } else {
            insertarNodo(arbol->derecha, n, arbol);
        }
    }
}

void mostrarArbol(AB arbol, int contador) {
    if (arbol == NULL) {
        return;
    } else {
        mostrarArbol(arbol->derecha, contador + 1);
        for (int i = 0; i < contador; i++) {
            printf("    ");
        }
        printf("%d\n", arbol->dato);
        mostrarArbol(arbol->izquierda, contador + 1);
    }
}

// Solo sirve para buscar dentro de un arbol binario de busqueda.
bool busquedaNodo(AB arbol, int n) {
    if (arbol == NULL) {
        return false;
    } else if (arbol->dato == n) {
        return true;
    } else if (n < arbol->dato) {
        return busquedaNodo(arbol->izquierda, n);
    } else {
        return busquedaNodo(arbol->derecha, n);
    }
}

AB busquedaNodoIterativa(AB arbol, int n) {
    while ((arbol != NULL) && (arbol->dato != n)) {
        if (n < arbol->dato) {
            arbol = arbol->izquierda;
        } else {
            arbol = arbol->derecha;
        }
    }
    return arbol;
}

void preOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        printf("%d - ", arbol->dato);
        preOrden(arbol->izquierda);
        preOrden(arbol->derecha);
    }
}

void inOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        inOrden(arbol->izquierda);
        printf("%d - ", arbol->dato);
        inOrden(arbol->derecha);
    }
}

void postOrden(AB arbol) {
    if (arbol == NULL) {
        return;
    } else {
        inOrden(arbol->izquierda);
        inOrden(arbol->derecha);
        printf("%d - ", arbol->dato);
    }
}

AB minimo(AB arbol) {
    if (arbol == NULL) {
        return;
    }
    if (arbol->izquierda) {
        return minimo(arbol->izquierda);
    } else {
        return arbol;
    }
}

void remplazar(AB arbol, AB nuevoNodo) {
    if (arbol->padre) {
        if (arbol->dato == arbol->padre->izquierda->dato) {
            arbol->padre->izquierda = nuevoNodo;
        } else if (arbol->dato == arbol->padre->derecha->dato) {
            arbol->padre->derecha = nuevoNodo;
        }
    }
    if (nuevoNodo) {
        nuevoNodo->padre = arbol->padre;
    }
}

void destriur(AB nodo) {
    nodo->izquierda = NULL;
    nodo->derecha = NULL;
    delete nodo;
}

void eliminarNodo(AB nodoEliminar) {
    if (nodoEliminar->izquierda && nodoEliminar->derecha) {  // Verifico que el nodo tenga un hijo derecho e izquierdo.
        AB menor = minimo(nodoEliminar->derecha);
        nodoEliminar->dato = menor->dato;
        eliminarNodo(menor);
    } else if (nodoEliminar->izquierda) {  // Verifico que el nodo tiene solo un hijo izquierdo.
        remplazar(nodoEliminar, nodoEliminar->izquierda);
        destriur(nodoEliminar);
    } else if (nodoEliminar->izquierda) {  // Verifico que el nodo tiene solo un hijo derecho.
        remplazar(nodoEliminar, nodoEliminar->derecha);
        destriur(nodoEliminar);
    } else {  // No tiene hijos.
        remplazar(nodoEliminar, NULL);
        destriur(nodoEliminar);
    }
}

void eliminar(AB &arbol, int n) {
    if (arbol == NULL) {
        return;
    } else if (n < arbol->dato) {
        eliminar(arbol->izquierda, n);
    } else if (n > arbol->dato) {
        eliminar(arbol->derecha, n);
    } else {  // Encontramos el elemento
        eliminarNodo(arbol);
    }
}

int main() {
    AB arbol = NULL;
    int opcion, elemento;

    do {
        printf("\n");
        printf("-----MENU-----\n");
        printf("1. Insertar un nuevo nodo.\n");
        printf("2. Mostrar los elementos del arbol.\n");
        printf("3. Mostrar los elementos del arbol (preOrden).\n");
        printf("4. Mostrar los elementos del arbol (inOrden).\n");
        printf("5. Mostrar los elementos del arbol (postOrden).\n");
        printf("6. Buscar un elementro dentro del arbol .\n");
        printf("7. Borrar un elementro dentro del arbol .\n");
        printf("8. Salir.\n\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                insertarNodo(arbol, elemento, NULL);
                printf("Elemento insertado correctamente.\n");
                break;

            case 2:
                mostrarArbol(arbol, 0);
                break;

            case 3:
                printf("Recorrido en PreOrden: ");
                preOrden(arbol);
                break;

            case 4:
                printf("Recorrido en InOrden: ");
                inOrden(arbol);
                break;

            case 5:
                printf("Recorrido en PostOrden: ");
                postOrden(arbol);
                break;

            case 6:
                printf("Ingrese el elemento a buscar: ");
                scanf("%d", &elemento);
                if (busquedaNodo(arbol, elemento)) {
                    printf("El elemento %d se encuentra dentro del arbol.\n", elemento);
                } else {
                    printf("El elemento %d NO se encuentra dentro del arbol.\n", elemento);
                }
                break;

            case 7:
                printf("Ingrese el elemento a borrar: ");
                scanf("%d", &elemento);
                eliminar(arbol, elemento);
                break;

            case 8:
                printf("Adios\n");
                break;

            default:
                printf("Opcion incorrecta, digite nuevamente.\n");
                break;
        }

    } while (opcion != 8);

    return 0;
}
