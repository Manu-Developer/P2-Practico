struct repTabla;
typedef repTabla* Tabla;

// PRE: cota > 0. POS: Devuelve la Tabla vacía, para la cual se estiman cota correspondencias.
Tabla crear(int cota);

// POS: Agrega la correspondencia (d,i) en t, si d no tenía imagen en t; en caso contrario, no se modifica t.
void insertar(int d, float i, Tabla& t);

// POS: Devuelve true si y sólo si d tiene imagen en t.
bool pertenece(int d, Tabla t);

// POS: Devuelve la cantidad de correspondencias en t (0 si t está vacía).
int cantidad(Tabla t);

// PRE: pertenece (d,t). POS: Retorna la imagen de d en t.
float recuperar(int d, Tabla t);

// POS: Elimina de t la correspondencia que involucra a d, si d está definida en t. En otro caso la operación no tiene efecto.
void eliminar(int d, Tabla& t);

// PRE: cantindad(t) > 0. POS: Retorna el mínimo valor del dominio presente en una correspondencia de t.
int minimo(Tabla t);

// POS: Retorna una copia de la tabla t, sin compartir memoria, para la cual se estiman cota correspondencias.
Tabla copia(Tabla t, int cota);

// POS: Libera toda la memoria ocupada por t.
void destruir(Tabla& t);
