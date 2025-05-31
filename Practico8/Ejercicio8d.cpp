#include "../Practico8/Ejercicio8d.h"

#include <stdio.h>

struct nodoUrna {
    int rango;
    int* arrayCandidatos;
};

urna urnaVaciaV2(int rango) {
    urna nuevaUrna = new nodoUrna;
    nuevaUrna->rango = rango;
    nuevaUrna->arrayCandidatos = new int[rango + 1];
    for (int i = 1; i <= rango; i++) {
        nuevaUrna->arrayCandidatos[i] = 0;
    }
    return nuevaUrna;
}

void insertarVoto(urna& u, int candidato) {
    if (candidato >= 1 && candidato <= u->rango) {
        u->arrayCandidatos[candidato]++;
    }
}

int cantVotos(urna u, int candidato) {
    if (candidato >= 1 && candidato <= u->rango) {
        return u->arrayCandidatos[candidato];
    } else {
        return -1;
    }
}

// Opcional: para evitar fugas de memoria
void destruirUrna(urna& u) {
    delete[] u->arrayCandidatos;
    delete u;
    u = NULL;
}

int main() {
    int n = 5;  // número de candidatos
    urna u = urnaVaciaV2(n);

    // Insertar votos
    insertarVoto(u, 1);
    insertarVoto(u, 3);
    insertarVoto(u, 3);
    insertarVoto(u, 5);
    insertarVoto(u, 5);
    insertarVoto(u, 5);

    // Mostrar resultados
    printf("Conteo de votos por candidato:\n");
    for (int i = 1; i <= n; i++) {
        printf("Candidato %d: %d votos\n", i, cantVotos(u, i));
    }

    // Liberar memoria
    destruirUrna(u);

    return 0;
}