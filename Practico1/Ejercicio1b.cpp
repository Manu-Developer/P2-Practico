#include <stdio.h>

// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int f;
};

void ordenarFechas(rep_fecha arregloFechas[], int largoArreglo) {
    for (int i = 0; i < largoArreglo; i++) {
        for (int j = 0; j < largoArreglo - i - 1; j++) {
            if (arregloFechas[j].f > arregloFechas[j + 1].f) {
                rep_fecha fechaAuxiliar = arregloFechas[j];
                arregloFechas[j] = arregloFechas[j + 1];
                arregloFechas[j + 1] = fechaAuxiliar;
            }
        }
    }
}

rep_fecha crearFecha(int f) {
    struct rep_fecha nuevaFecha;
    nuevaFecha.f = f;
    return nuevaFecha;
}

void imprimirFecha(rep_fecha fechaImprimir) {
    printf("%d\n", fechaImprimir.f);
}

int main(int argc, char const *argv[]) {
    rep_fecha fechaPrueba1 = crearFecha(20250101);
    rep_fecha fechaPrueba2 = crearFecha(19990515);
    rep_fecha fechaPrueba3 = crearFecha(20230710);
    rep_fecha fechaPrueba4 = crearFecha(20000411);

    rep_fecha arregloFechas[4] = {fechaPrueba1, fechaPrueba2, fechaPrueba3, fechaPrueba4};

    ordenarFechas(arregloFechas, 4);

    printf("Mostrando las fechas ordenadas: \n");
    for (int i = 0; i < 4; i++) {
        imprimirFecha(arregloFechas[i]);
    }

    return 0;
}
