#include <stdio.h>

struct lista {
    int elemento;
    lista *sig;
};

typedef lista *L;

void imprimirReversa(L lista) {
    if (lista != NULL) {
        imprimirReversa(lista->sig);
        printf("%d", lista->elemento);
    }
}

// T(0) <= c1 (Si L==NULL, c1 es constante)
// T(n) <= T(n-1)+c0 (Si L!=NULL, c0 es constante)

// Expandiendo por recurrencia:

// T(n) <= T(n-1)+c0 <= T(n-2)+2c0 <= T(n-3)+3c0 <=...<= T(n-i)+ic0

// Caso Base (i=n):

// T(n) <= T(0)+nc0 <= c1+nc0

// Entonces T(n) es O(n)