#include <stdio.h>

struct nodoABB {
    int codigo;     // código del empleado
    float salario;  // salario del empleado
    nodoABB *izq, *der;
};

typedef nodoABB* ABB;

// El peor caso de licenciar se da cuando todos los códigos son menores que c. En dicho caso debe recorrerse todo el árbol.
void licenciar(ABB& arbol, int codigo) {
    if (arbol != NULL) {
        if (arbol->codigo < codigo) {
            arbol->salario = 0;
            licenciar(arbol->der, codigo);
        }
        licenciar(arbol->izq, codigo);
    }
}

// El caso promedio de conAumento es igual al peor caso, ya que recorre siempre todo el árbol.
ABB conAumento(ABB arbol, float piso, float aumento) {
    if (arbol == NULL) {
        return NULL;
    } else {
        ABB resultado = new nodoABB;
        resultado->codigo = arbol->codigo;

        if (arbol->salario > piso)
            resultado->salario = arbol->salario;
        else
            resultado->salario = arbol->salario + aumento;

        resultado->der = conAumento(arbol->der, piso, aumento);
        resultado->izq = conAumento(arbol->izq, piso, aumento);

        return resultado;
    }
}