#include <stdio.h>
#include <string.h>

int ocurrencias(char frase[100], int largoFrase, int letraBuscar) {
    int letraOcurrencias = 0;

    for (int i = 0; i < largoFrase; i++) {
        if (letraBuscar == frase[i]) {
            letraOcurrencias++;
        }
    }

    return letraOcurrencias;
}

int main() {
    char frase[100];
    char letraBuscar;
    int largoFrase;

    printf("Ingrese la frase: ");
    scanf("%[^\n]s", frase);

    largoFrase = strlen(frase);

    printf("Ingrese la letra a buscar: ");
    scanf(" %c", &letraBuscar);

    printf("La cantidad de veces que aparece la letra '%c' en la frase es: %d veces", letraBuscar, ocurrencias(frase, largoFrase, letraBuscar));

    return 0;
}