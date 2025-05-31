#include "../Practico8/Ejercicio8.h"

#include <stdio.h>

// Para strcpy, strcmp, strlen
#include <cstring>

struct nodoUrna {
    char* candidato;
    nodoUrna* sig;
};

urna urnaVacia() {
    urna urnaVacia = NULL;
    return urnaVacia;
}

void insertarVoto(urna& u, const char* candidato) {
    urna nuevoNodoUrna = new nodoUrna;
    nuevoNodoUrna->candidato = new char[strlen(candidato) + 1];
    strcpy(nuevoNodoUrna->candidato, candidato);
    nuevoNodoUrna->sig = u;
    u = nuevoNodoUrna;
}

int cantVotos(urna u, const char* candidato) {
    int cantidad = 0;
    while (u != NULL) {
        if (strcmp(u->candidato, candidato) == 0) {
            cantidad++;
        }
        u = u->sig;
    }
    return cantidad;
}

// Opcional: para evitar fugas de memoria
void destruirUrna(urna& u) {
    while (u != NULL) {
        nodoUrna* temp = u;
        u = u->sig;
        delete[] temp->candidato;
        delete temp;
    }
}

int main() {
    urna u = urnaVacia();

    // Insertar votos
    insertarVoto(u, "Alice");
    insertarVoto(u, "Bob");
    insertarVoto(u, "Alice");
    insertarVoto(u, "Charlie");
    insertarVoto(u, "Alice");
    insertarVoto(u, "Bob");

    // Mostrar resultados
    printf("Votos para Alice: %d\n", cantVotos(u, "Alice"));      // 3
    printf("Votos para Bob: %d\n", cantVotos(u, "Bob"));          // 2
    printf("Votos para Charlie: %d\n", cantVotos(u, "Charlie"));  // 1
    printf("Votos para Daniel: %d\n", cantVotos(u, "Daniel"));    // 0

    // Liberar memoria
    destruirUrna(u);

    return 0;
}