#include <stdio.h>

struct nodoLista {
    char caracter;
    nodoLista* sig;
};

typedef struct nodoLista* listaCaracteres;

listaCaracteres listaCaracteresVacia() {
    listaCaracteres listaCaracteresVacia = NULL;
    return listaCaracteresVacia;
}

void insertarCaracter(listaCaracteres& lista, char caracter) {
    nodoLista* nuevoNodo = new nodoLista;
    nuevoNodo->caracter = caracter;
    nuevoNodo->sig = lista;
    lista = nuevoNodo;
}

void imprimirListaCaracteres(listaCaracteres lista) {
    while (lista != NULL) {
        printf("%c", lista->caracter);
        lista = lista->sig;
    }
}

// Como efecto secundario, invierte la cadena de caracteres que estaba previamente invertida.
listaCaracteres editorTexto(listaCaracteres lista) {
    listaCaracteres listaNueva = listaCaracteresVacia();
    int cantidadBackspaces = 0;

    while (lista != NULL) {
        if (lista->caracter == '#') {
            cantidadBackspaces++;
        } else {
            if (cantidadBackspaces > 0) {
                cantidadBackspaces--;
            } else {
                insertarCaracter(listaNueva, lista->caracter);
            }
        }
        lista = lista->sig;
    }

    return listaNueva;
}

int main() {
    listaCaracteres miLista = listaCaracteresVacia();

    insertarCaracter(miLista, 'a');
    insertarCaracter(miLista, 'b');
    insertarCaracter(miLista, 'c');
    insertarCaracter(miLista, '#');
    insertarCaracter(miLista, 'd');
    insertarCaracter(miLista, '#');
    insertarCaracter(miLista, '#');
    insertarCaracter(miLista, 'e');

    printf("Contenido de la lista: ");
    imprimirListaCaracteres(editorTexto(miLista));
    printf("\n");

    return 0;
}