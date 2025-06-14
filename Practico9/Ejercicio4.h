#ifndef EJ_4
#define EJ_4

struct rep_grafica;
struct nodoHash;
typedef struct rep_grafica* grafica;
typedef struct nodoHash* Lista;

// Devuelve una gráfica vacia que puede mantener hasta 'N' asociaciones.
// Precondición: N > 0.
grafica CrearGrafica(int N);

// Si en 'g' hay menos de 'N' asociaciones, asigna 'y' como valor asociado a 'x', en caso contrario la operación no tiene efecto.
// Precondición: x > 0 , y > 0 , Valor (x, g) == -1.
void Asociar(int x, int y, grafica& g);

// Si en 'g' existe asociación para 'x', devuelve el valor asociado a 'x', en otro caso devuelve -1.
// Precondición: x > 0.
int Valor(int x, grafica g);

// Elimina de 'g' la asociación para 'x' si existe tal asociacion, en caso contrario la operación no tiene efecto.
// Precondición: x > 0.
void Desasociar(int x, grafica& g);

//-----------------------------------------------------------------------------------//

// NO COMPRENDO PORQUE NOS DAN FUNCIONES ASOCIADAS A UN TADLISTA, PUES NUNCA SON USADAS.

struct Punto {
    int x, y;
};

// Devuelve una lista vacia.
Lista CrearLista();

// Agrega 'pt ' al inicio de 'l'.
void Insertar(Punto pt, Lista& l);

// Devuelve el primer elemento de 'l'.
// Precondición: ! EsVaciaLista (l).
Punto Primero(Lista l);

// Devuelve 'l' sin el primer elemento.
// Precondición: !EsVaciaLista (l).
void Resto(Lista& l);

// Devuelve true si y solo si 'l' es vacia .
bool EsVaciaLista(Lista l);

// Devuelve true si y solo si en 'l' hay un punto cuya primera coordenada es 'x'.
bool ExisteX(int x, Lista l);

// Remueve el primer elementode 'l' cuya primera coordenada es 'x'.
// Precondición: ExisteX (x,l).
void RemoverX(int x, Lista& l);

#endif