#ifndef EJ_1
#define EJ_1

struct nodoHash;
struct multiFIFA;
typedef struct multiFIFA *FIFA;

// Crea y retorna una tabla de posiciones con una maxima cantidad de 'cotaPaises' elementos.
FIFA crearFIFA(int cotaPaises);

// Agrega el nombre del equipo pasado por parametro a la tabla como ultimos en la escala.
void agregar(const char *pais, FIFA &f);

// Devuelve el nombre del equipo del puesto i − 1 si el equipo pasado por parametro está en el puesto i.
// i debe ser mayor a 1.
const char *rivalDirecto(const char *pais, FIFA f);

// Intercambia los nombres de los equipos que estén en los puesto i e i − 1.
// i debe ser mayor a 1.
void intercambia(int i, FIFA &f);

#endif