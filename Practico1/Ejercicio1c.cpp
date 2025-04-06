#include <stdio.h>

struct rep_fecha {
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

// TFecha es un puntero a la estructura rep_fecha.
// Es una flecha que apunta a un espacio en memoria dentro de la estructura.

typedef struct rep_fecha *TFecha;

/* Devuelve un 'TFecha' con dia d, mes m y año a */
TFecha crear_fecha(unsigned int d, unsigned int m, unsigned int a) {
    TFecha fecha = new rep_fecha;
    // Manera poco legible:
    //  (*fecha).d = d;
    //  (*fecha).m = m;
    //  (*fecha).a = a;

    // Manera mas legible:
    fecha->d = d;
    fecha->m = m;
    fecha->a = a;

    return fecha;
}

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool comparar_fechas(TFecha f1, TFecha f2) {
    return ((f2->a > f1->a) || ((f2->a == f1->a) && (f2->m > f1->m)) || ((f2->a == f1->a) && (f2->m == f1->m) && (f2->d > f1->d)));
}

/* Devuelve el día correspondiente a fecha */
unsigned int dia(TFecha fecha) {
    return fecha->d;
}

/* Devuelve el mes correspondiente a fecha */
unsigned int mes(TFecha fecha) {
    return fecha->m;
}

/* Devuelve el año correspondiente a fecha */
unsigned int anio(TFecha fecha) {
    return fecha->a;
}

int main(int argc, char const *argv[]) {
    TFecha f1 = crear_fecha(2, 3, 2022);
    TFecha f2 = crear_fecha(1, 3, 2022);

    printf("%d/%d/%d %d", dia(f1), mes(f1), anio(f1), comparar_fechas(f2, f1));
    return 0;
}
