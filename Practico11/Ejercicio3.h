#ifndef EJ_3
#define EJ_3

struct nodoEmpleado;
struct rep_estructura;
typedef struct rep_estructura *estructura;

// Crea y retorna una estructura vacia que podra contener la informacion de hasta k empleados.
estructura crearEstructura(int k);

// Retorna true si la estructura e esta llena, false en caso contrario.
bool estaLLenaEstructura(estructura e);

// Ingresa a la estructura el empleado con su correspondiente nombre, numero de seguridad social y numero de empleado.
// Pre: !estaLLenaEstructura(e)
void ingresarEmpleado(estructura &e, const char *nombre, int nroSegSocial, int nroEmpleado);

// Retorna e imprime el numero de seguridad social a partir del nombre de un empleado si es que existe.
// ¿En caso de no existir el empleado la funcion retorna -1?
int obtenerNroSegSocial(estructura e, const char *nombre);

// Retorna e imprime el numero de empleado social a partir del nombre de un empleado si es que existe.
// ¿En caso de no existir el empleado la funcion retorna -1?
int obtenerNroEmpleado(estructura e, const char *nombre);

// Imprime todos los empleados de la compania que se encuentran en la estructura de forma ordenada segun su nombre.
void imprimirEmpleados(estructura e);

#endif