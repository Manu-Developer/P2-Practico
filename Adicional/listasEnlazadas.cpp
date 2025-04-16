#include <stdio.h>

struct nodo {
    int elemento;
    nodo* siguiente;
};

// ¿Porque el puntero lista no pierde la referencia al 1er elemento si lo estamos cambiando siempre dentro del bucle while?
void imprimirLista(nodo* lista) {
    if (lista == NULL) {
        printf("La lista esta vacia.");
    }
    while (lista != NULL) {
        printf("[%d] -> ", lista->elemento);
        lista = lista->siguiente;
    }
    printf("\n");
}

void insertarPrimero(nodo*& lista, int elemento) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = lista;
    lista = nuevoNodo;
}

void insertarFinal(nodo*& lista, int elemento) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->elemento = elemento;
    nuevoNodo->siguiente = NULL;

    if (lista == NULL) {
        lista = nuevoNodo;
    } else {
        nodo* auxiliar = lista;

        while (auxiliar->siguiente != NULL) {
            auxiliar = auxiliar->siguiente;
        }

        auxiliar->siguiente = nuevoNodo;
    }
}

void insertarOrdenado(int x, nodo*& l) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->elemento = x;

    if (l == NULL || l->elemento >= x) {
        nuevoNodo->siguiente = l;
        l = nuevoNodo;
    } else {
        nodo* auxiliarLista = l;
        while (auxiliarLista->siguiente != NULL && auxiliarLista->siguiente->elemento < x) {
            auxiliarLista = auxiliarLista->siguiente;
        }
        nuevoNodo->siguiente = auxiliarLista->siguiente;
        auxiliarLista->siguiente = nuevoNodo;
    }
}

void insertarDespues(nodo* nodoPrevio, int elemento) {
    if (nodoPrevio == NULL) {
        printf("El nodo no puede ser NULL.");
    }

    nodo* nuevoNodo = new nodo;
    nuevoNodo->elemento = elemento;

    nuevoNodo->siguiente = nodoPrevio->siguiente;
    nodoPrevio->siguiente = nuevoNodo;
}

void eliminarNodo(nodo*& lista, int elemento) {
    bool eliminado = false;

    // Caso especial: eliminar nodos desde el principio
    while (lista != NULL && lista->elemento == elemento) {
        nodo* temp = lista;
        lista = lista->siguiente;
        delete temp;
    }

    // Ahora eliminamos nodos que estén después del primero
    nodo* auxiliar = lista;
    while (auxiliar != NULL && auxiliar->siguiente != NULL) {
        if (auxiliar->siguiente->elemento == elemento) {
            auxiliar->siguiente = auxiliar->siguiente->siguiente;
            delete auxiliar;
            bool eliminado = true;
        } else {
            auxiliar = auxiliar->siguiente;
        }
    }

    if (!eliminado) {
        printf("No se ha encontrado el elemento a eliminar.\n");
    }
}

void removerElemento(nodo*& lista, int x) {
    if (lista != NULL) {
        nodo* aux = lista;
        nodo* anterior = NULL;

        while (aux != NULL && aux->elemento != x) {
            anterior = aux;
            aux = aux->siguiente;
        }

        // El elemento no ha sido encontrado
        if (aux == NULL) {
            printf("El elemento no ha sido encontrado");
        }
        // El primer elemento sera el que eliminemos
        else if (anterior == NULL) {
            lista = lista->siguiente;
            delete aux;
        }
        // El elemento a eliminar esta en la lista, pero no es el primer nodo
        else {
            anterior->siguiente = aux->siguiente;
            delete aux;
        }
    }
}

void eliminarTodos(nodo*& lista) {
    nodo* auxiliar;
    while (lista != NULL) {
        auxiliar = lista->siguiente;
        delete lista;
        lista = auxiliar;
    }
}

void eliminarUltimo(nodo*& lista) {
    if (lista != NULL) {
        if (lista->siguiente == NULL) {
            delete lista;
            lista = NULL;
        } else {
            nodo* auxiliar = lista;
            while (auxiliar->siguiente->siguiente != NULL) {
                auxiliar = auxiliar->siguiente;
            }
            delete auxiliar->siguiente;
            auxiliar->siguiente = NULL;
        }
    }
}

void estaEnLista(nodo* lista, int elemento) {
    nodo* auxiliar = lista;
    bool estaEnLista = false;

    while (auxiliar != NULL) {
        if (auxiliar->elemento == elemento) {
            estaEnLista = true;
        }
        auxiliar = auxiliar->siguiente;
    }

    if (estaEnLista) {
        printf("El elemento %d se encuentra en la lista.\n", elemento);
    } else {
        printf("El elemento %d no se encuentra en la lista.\n", elemento);
    }
}

int main() {
    nodo* primero = NULL;
    int opcion, elemento;

    do {
        printf("\n");
        printf("-----MENU-----\n");
        printf("1. Insertar elementos a la lista.\n");
        printf("2. Mostrar los elementos de la lista.\n");
        printf("3. Buscar un elemento dentro de la lista.\n");
        printf("4. Eliminar un elemento de la lista.\n");
        printf("5. Eliminar todos los elementos de la lista.\n");
        printf("6. Salir.\n\n");

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el elemento a insertar: ");
                scanf("%d", &elemento);
                insertarOrdenado(elemento, primero);
                printf("Elemento insertado correctamente.\n");
                break;

            case 2:
                imprimirLista(primero);
                break;

            case 3:
                printf("Ingrese el elemento a buscar: ");
                scanf("%d", &elemento);
                estaEnLista(primero, elemento);
                break;

            case 4:
                printf("Ingrese el elemento a eliminar: ");
                scanf("%d", &elemento);
                removerElemento(primero, elemento);
                break;

            case 5:
                eliminarTodos(primero);
                break;

            case 6:
                printf("Adios\n");
                break;

            default:
                printf("Opcion incorrecta, digite nuevamente.\n");
                break;
        }

    } while (opcion != 6);

    return 0;
}