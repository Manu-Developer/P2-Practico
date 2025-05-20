#ifndef EJ_4
#define EJ_4

struct nodo_pedido;
typedef struct nodo_pedido *colaP;

struct cabezalPedidos;
typedef struct cabezalPedidos *pedido;

// Crea y devuelve una collecion de pedidos vacia con una cota k.
pedido crearPedidos(int k);

// Inserta el pedido con identificador i y descripcion d en la colleccion de pedidos p mientras no exista otro pedido con el mismo identificador i en p. En caso contrario la operacion no tiene efecto.
// Pre: i ∈ (0 ≤ i ≤ k)
void insertar(pedido &p, int i, string d);

// Elimina el pedido más antiguo (el primero ingresado) de una colección de pedidos no vacía y retorna la descripción.
// Pre: !esVacia(p)
string eliminarAntiguo(pedido &p);

// Devuelve true si p esta vacía y false en caso contrario
bool esVacia(pedido &p);

// Retorna true si hay un pedido con identificador i en p, false en caso contrario.
bool existePedido(pedido &p, int i);

#endif