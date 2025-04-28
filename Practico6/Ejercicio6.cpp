#include <stdio.h>

void hanoi(int n, char origen, char destino, char intermedio) {
    if (n > 0) {
        hanoi(n - 1, origen, intermedio, destino);
        printf(" Mueve %d de %c a %c\n", n, origen, destino);
        hanoi(n - 1, intermedio, destino, origen);
    }
}

// Paso 1: Definir la recurrencia

// Llamemos T(n) al tiempo de ejecucion para n discos.

// - Si n>0

// 1) Llama recursivamente a la funcion con n-1 discos.
// 2) Realiza una impresion
// 3) Llama nuevamente de manera recursiva a la funcion con n-1 discos.

// Entonces la recurrencia es: T(n)=2T(n-1)+c0 (Siendo c0 una constante)

// Paso 2: Expando la recurrencia

// 2T(n-1)+c0 = 2(2T(n-2)+c0)+c0 = 4T(n-2)+3c0
//= 2(4T(n-3)+3c0)+c0 = 8T(n-3)+7c0
//=...= 2^kT(n-k)+(2^k-1)c0

// Cuando k=n

// T(n) = 2^nT(0)+(2^n-1)c0 = 2^nd+(2^n-1)c0

// Luego T(n) es O(2^n)