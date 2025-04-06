#include <stdio.h>

// Registro con dia d, mes m y año a
struct rep_fecha {
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

rep_fecha crearFecha(int d, int m, int a) {
    struct rep_fecha nuevaFecha;
    nuevaFecha.d = d;
    nuevaFecha.m = m;
    nuevaFecha.a = a;
    return nuevaFecha;
}

void imprimirFecha(rep_fecha fechaImprimir) {
    printf("%d/%d/%d\n", fechaImprimir.d, fechaImprimir.m, fechaImprimir.a);
}

void ordenarFechas(rep_fecha arregloFechas[], int largoArreglo) {
    for (int i = 0; i < largoArreglo; i++) {
        for (int j = 0; j < largoArreglo - i - 1; j++) {
            if ((arregloFechas[j].a > arregloFechas[j + 1].a) || ((arregloFechas[j].a == arregloFechas[j + 1].a) && (arregloFechas[j].m > arregloFechas[j + 1].m)) || ((arregloFechas[j].a == arregloFechas[j + 1].a) && (arregloFechas[j].m == arregloFechas[j + 1].m) && arregloFechas[j].d > arregloFechas[j + 1].d)) {
                rep_fecha fechaAuxiliar = arregloFechas[j];
                arregloFechas[j] = arregloFechas[j + 1];
                arregloFechas[j + 1] = fechaAuxiliar;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    rep_fecha fechaPrueba1 = crearFecha(1, 1, 2025);
    rep_fecha fechaPrueba2 = crearFecha(8, 3, 2023);
    rep_fecha fechaPrueba3 = crearFecha(15, 6, 1999);
    rep_fecha fechaPrueba4 = crearFecha(1, 1, 2022);

    rep_fecha arregloFechas[4] = {fechaPrueba1, fechaPrueba2, fechaPrueba3, fechaPrueba4};

    ordenarFechas(arregloFechas, 4);

    printf("Mostrando las fechas ordenadas: \n");
    for (int i = 0; i < 4; i++) {
        imprimirFecha(arregloFechas[i]);
    }

    return 0;
}
