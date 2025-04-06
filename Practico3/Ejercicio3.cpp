#include <stdio.h>

int rayuela(int adoquinN) {
    if (adoquinN == 0 || adoquinN == 1) {
        return 1;
    }

    // Para llegar al adoquinN, puedo llegar desde (adoquinN - 1) o (adoquinN - 2)
    return rayuela(adoquinN - 1) + rayuela(adoquinN - 2);
}

int main() {
    printf("%d", rayuela(4));
    return 0;
}