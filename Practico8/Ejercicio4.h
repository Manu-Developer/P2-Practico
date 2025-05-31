#ifndef EJ_4
#define EJ_4

struct nodo_pedido;
struct cabezalPedidos;
typedef struct nodo_pedido *cola_pedidos;
typedef struct cabezalPedidos *pedidos;

// Crea y devuelve una coleccion de pedidos vacia hasta k+1 pedidos.
pedidos crearPedidos(int k);

// Inserta el pedido con identificador i y descripcion d en la colleccion de pedidos p mientras no exista otro pedido con el mismo identificador i en p. En caso contrario la operacion no tiene efecto.
// Pre: i ∈ (0 ≤ i ≤ k)
void insertar(pedidos &p, int i, char *d);

// Elimina el pedido más antiguo (el primero ingresado) de una colección de pedidos no vacía y retorna la descripción.
// Pre: !esVacia(p)
char *eliminarAntiguo(pedidos &p);

// Devuelve true si p esta vacía y false en caso contrario
bool esVacia(pedidos &p);

// Retorna true si hay un pedido con identificador i en p, false en caso contrario.
bool existePedido(pedidos &p, int i);

#endif