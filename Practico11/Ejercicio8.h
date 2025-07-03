#ifndef EJ_8
#define EJ_8

struct rep_PAgrupacion;
struct rep_listaPuntos;
struct rep_conCarnaval;
typedef struct rep_PAgrupacion* PAgrupacion;
typedef struct rep_listaPuntos* listaPuntos;
typedef struct rep_conCarnaval* conCarnaval;

// PRE: -
// POST: Crea y retorna un conCarnaval vacio con puntajes en el rango [0,N]
conCarnaval crearConcCarnaval(int N);

// PRE: 0 <= puntaje <= N
// POST: Asocia a 'agrupacion' el valor 'puntaje' en 'c'. Si ya tenia un valor asociado lo redefine.
void asociarAsociacion(char* agrupacion, int puntaje, conCarnaval& c);

// PRE: -
// POST: Retorna 'true' si y solo si una 'agrupacion' tiene asociado un puntaje en 'c'.
bool existeAsociacion(char* agrupacion, conCarnaval c);

// PRE: existeAsociacion(agrupacion, c)
// POST: Retorna el puntaje asociado a 'agrupacion' en 'c'.
int puntajeAgrupacion(char* agrupacion, conCarnaval c);

// PRE: existeAsociacion(agrupacion, c)
// POST: Elimina la asociacion de 'agrupacion' en 'c'.
void eliminarAgrupacion(char* agrupacion, conCarnaval& c);

// POST: Imprime las agrupaciones en orden alfabetico con sus respectivos puntos.
void imprimirAgrupacion(conCarnaval c);

// PRE: 0 <= puntaje <= N
// POST: Retorna una lista con las agrupaciones que tienen 'puntaje' puntos en 'c'.
PAgrupacion listaPuntos(conCarnaval c, int puntaje);

#endif