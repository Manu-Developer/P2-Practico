#include <stdio.h>

struct nodoABB {
    int telefono;  // número telefónico de un contacto
    char nombre;   // nombre completo del contacto
    nodoABB *izq, *der;
};

typedef nodoABB* ABB;

int contactos(ABB arbol, char nom) {
    if (arbol == NULL) {
        return 0;
    } else {
        if (arbol->nombre == nom) {
            return 1 + contactos(arbol->izq, nom) + contactos(arbol->der, nom);
        } else {
            return contactos(arbol->izq, nom) + contactos(arbol->der, nom);
        }
    }
}

int main() {
}