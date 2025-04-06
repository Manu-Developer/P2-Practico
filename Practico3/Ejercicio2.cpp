#include <stdio.h>
#include <string.h>

bool esPalindrome(char string[], int inicio, int fin) {
    if (inicio >= fin) return true;

    return (string[inicio] == string[fin]) && (esPalindrome(string, inicio + 1, fin - 1));
}

int main() {
    char string[] = "hola";
    int largoFrase = strlen(string);

    if (esPalindrome(string, 0, largoFrase - 1)) {
        printf("Es palindrome");
    } else {
        printf("No es palindrome");
    }

    return 0;
}