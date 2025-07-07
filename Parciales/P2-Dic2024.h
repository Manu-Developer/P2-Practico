struct RepVotacion;
typedef RepVotacion* Votacion;

// PRE: ‘cant’>0. POS: Devuelve el TAD Votacion vacío, para el cual se estiman ‘cant’ listas electorales diferentes.
Votacion crearVotacion(int cant);

// POS: Registra un voto a la lista electoral ‘le’ en ‘v’.
void insertarVoto(Votacion& v, char* le);

// POS: Devuelve la cantidad total de votos registrados en ‘v’.
int cantidad(Votacion v);

// POS: Devuelve la cantidad de votos que tiene la lista electoral ‘le’ en ‘v’.
int cantVotos(Votacion v, char* le);

/* PRE: cantidad(v) > 0. POS: Devuelve el nombre de la lista más votada en ‘v’. Si hay empate entre dos o más listas
electorales (más votadas), devuelve*/
char* masVotada(Votacion v);

typedef int T;
typedef struct repCp* CP;
// POS: Devuelve la cola de prioridad vacía
CP crear();

/* POS: Agrega ‘x’ con prioridad ‘p’ a ‘cp’, si ‘p’
no es una prioridad usada ya en ‘cp’. En caso contrario, no tiene efecto */
void agregar(T x, unsigned int p, CP& cp);

// POS: Retorna true si y solo si ‘cp’ es vacía
bool esVacia(CP cp);

/* PRE: !esVacia(cp). POS: Remueve y retorna el elemento
con mayor prioridad (valor más grade) ingresado en ‘cp’. */
T prioritario(CP& cp);

// Retorna una copia de ‘cp’, sin compartir memoria
CP copia(CP cp);

// Destruye la cola de prioridad ‘cp’, liberando su memoria
void destruir(CP& cp);