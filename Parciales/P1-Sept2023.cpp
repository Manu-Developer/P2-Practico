#include <stdio.h>

struct nodoABB {
    int telefono;  // número telefónico de un contacto
    char nombre;   // nombre completo del contacto
    nodoABB *izq, *der;
};

typedef nodoABB* ABB;

void agendar(ABB& arbol, int num, char nom) {
    if (arbol == NULL) {
        ABB nuedoNodo = new nodoABB;
        nuedoNodo->nombre = nom;
        nuedoNodo->telefono = num;
        nuedoNodo->izq = NULL;
        nuedoNodo->der = NULL;
    } else if (arbol->telefono == num) {
        arbol->nombre = nom;
    } else if (num < arbol->telefono) {
        agendar(arbol->izq, num, nom);
    } else {
        agendar(arbol->der, num, nom);
    }
}

int contactos(ABB t, char nom) {
    if (t == NULL)
        return 0;
    else if (t->nombre == nom)
        return 1 + contactos(t->izq, nom) + contactos(t->der, nom);
    else
        return contactos(t->izq, nom) + contactos(t->der, nom);
}