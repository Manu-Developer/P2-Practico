#include <stdio.h>

struct nodo {
    char caracter;
    nodo* sig;
};

struct rep_pila {
    int cantidad;
    nodo* pila;
};

typedef struct rep_pila* Pila;

Pila crearPila() {
    Pila p = new rep_pila;
    p->cantidad = 0;
    p->pila = NULL;
    return p;
}

void apilar(Pila& p, char caracter) {
    nodo* nuevoNodo = new nodo;
    nuevoNodo->caracter = caracter;
    nuevoNodo->sig = p->pila;
    p->pila = nuevoNodo;
    p->cantidad++;
}

bool esVaciaPila(Pila p) {
    return p->cantidad == 0;
}

void desapilar(Pila& p) {
    nodo* aBorrar = p->pila;
    p->pila = p->pila->sig;
    delete aBorrar;
    p->cantidad--;
}

void destructorPila(Pila& p) {
    while (!esVaciaPila(p)) {
        desapilar(p);
    }
    delete p;
}

char tope(Pila p) {
    return p->pila->caracter;
}

bool esPalindromeConSeparador(Pila& p) {
    Pila pilaAux = crearPila();
    bool esPalindromo = true;

    // Primera pasada: guardar antes del separador
    while (!esVaciaPila(p) && tope(p) != '-') {
        apilar(pilaAux, tope(p));
        desapilar(p);
    }

    // Si no se encontró separador o estaba al principio/final
    if (esVaciaPila(p)) {
        destructorPila(pilaAux);
        destructorPila(p);
        return false;
    }

    // Desapilar el separador
    desapilar(p);

    // Comparar con reverso
    while (!esVaciaPila(pilaAux) && !esVaciaPila(p)) {
        if (tope(pilaAux) != tope(p)) {
            esPalindromo = false;
            break;
        }
        desapilar(pilaAux);
        desapilar(p);
    }

    // Si una de las pilas quedó con elementos => no son palíndromos
    if (!esVaciaPila(pilaAux) || !esVaciaPila(p)) {
        esPalindromo = false;
    }

    // Vaciar ambas pilas
    destructorPila(pilaAux);
    destructorPila(p);

    return esPalindromo;
}

int main() {
    // Crear pila vacía
    Pila p = crearPila();

    // Apilar caracteres de "abac-caba"
    const char* texto = "abac-caaa";
    for (int i = 8; i >= 0; i--) {
        apilar(p, texto[i]);
    }

    bool resultado = esPalindromeConSeparador(p);

    printf("Cadena: \"%s\" -> Resultado: %s\n", texto, resultado ? "true" : "false");

    return 0;
}