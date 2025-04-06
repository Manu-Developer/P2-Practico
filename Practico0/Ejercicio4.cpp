#include <stdio.h>
#include <string.h>
#define MAX_CHARACTERS 100

bool esPalindrome(char *frase, int largoFrase) {
    int inicio = 0;
    int final = largoFrase - 1;

    while (final > inicio) {
        if (frase[inicio] != frase[final]) {
            return false;
        }
        inicio++;
        final--;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    char *frase;
    char cadena[MAX_CHARACTERS];
    frase = cadena;

    printf("Ingrese la palabra que desee, finaliza con .: ");
    char letra;
    scanf("%c", &letra);

    int i = 0;
    while (letra != '.') {
        cadena[i] = letra;
        scanf("%c", &letra);
        i++;
    }

    int largoFrase = strlen(frase);

    printf("%d", esPalindrome(frase, largoFrase));
    return 0;
}
