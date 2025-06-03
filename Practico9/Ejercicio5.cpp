#include <stdio.h>
#include <string.h>

struct nodoHash {
    char *usuario;
    char *contrasena;
    nodoHash *sig;
};

struct rep_tabla {
    int tamTabla;
    int cantidad;
    nodoHash **tabla;
};

typedef struct rep_tabla *tabla;

int funcionHash(char *usuario, int largoTabla) {
    int sumaASCII = 0;
    int largoUsuario = strlen(usuario);

    for (int i = 0; i < largoUsuario; i++) {
        sumaASCII = sumaASCII + int(usuario[i]);
    }

    return sumaASCII % largoTabla;
}

tabla crearTabla(int tamTabla) {
    tabla nuevaTabla = new rep_tabla;
    nuevaTabla->cantidad = 0;
    nuevaTabla->tamTabla = tamTabla;
    nuevaTabla->tabla = new nodoHash *[tamTabla];
    for (int i = 0; i < tamTabla; i++) {
        nuevaTabla->tabla[i] = NULL;
    }
    return nuevaTabla;
}

bool esVaciaTabla(tabla t) {
    return t->cantidad == 0;
}

bool esLlenaTabla(tabla t) {
    return t->cantidad == t->tamTabla;
}

bool estaDefinida(tabla t, char *usuario) {
    int indiceHash = funcionHash(usuario, t->tamTabla);
    nodoHash *aux = t->tabla[indiceHash];

    while (aux != NULL && strcmp(aux->usuario, usuario) != 0) {
        aux = aux->sig;
    }

    return aux != NULL;
}

void insertarTabla(tabla &t, char *usuario, char *contrasena) {
    if (!estaDefinida(t, usuario)) {
        int indiceHash = funcionHash(usuario, t->tamTabla);
        nodoHash *nuevoNodo = new nodoHash;
        nuevoNodo->usuario = strdup(usuario);
        nuevoNodo->contrasena = strdup(contrasena);
        nuevoNodo->sig = t->tabla[indiceHash];
        t->tabla[indiceHash] = nuevoNodo;
        t->cantidad++;
    }
}

char *recuperarClave(tabla t, char *usuario) {
    int indiceHash = funcionHash(usuario, t->tamTabla);
    nodoHash *aux = t->tabla[indiceHash];

    while (aux != NULL && strcmp(aux->usuario, usuario) != 0) {
        aux = aux->sig;
    }

    return aux->contrasena;
}

void imprimirTabla(tabla t) {
    for (int i = 0; i < t->tamTabla; i++) {
        if (t->tabla[i] != NULL) {
            nodoHash *aux = t->tabla[i];
            while (aux != NULL) {
                printf("id=%d, user=%s, pass=%s\n", i, aux->usuario, aux->contrasena);
                aux = aux->sig;
            }
        }
    }
}

void borrar(char *usuario, tabla &t) {
    int indiceHash = funcionHash(usuario, t->tamTabla);
    nodoHash *aux = t->tabla[indiceHash];

    if (strcpy(t->tabla[indiceHash]->usuario, usuario) == 0) {
        nodoHash *primerNodo = t->tabla[indiceHash];
        t->tabla[indiceHash] = t->tabla[indiceHash]->sig;
        delete primerNodo;
        primerNodo = NULL;
        t->cantidad--;
    }

    while (aux->sig != NULL) {
        if (strcpy(aux->sig->usuario, usuario) == 0) {
            nodoHash *aBorrar = aux->sig;
            aux->sig = aux->sig->sig;
            delete aBorrar;
            aBorrar = NULL;
            t->cantidad--;
        } else {
            aux = aux->sig;
        }
    }
}

int main() {
    tabla logIN_tabla = crearTabla(13);
    char usuario[30];
    char contrasena[30];
    char cmd = 'a';

    printf("Bienvenido al sistema de usuarios ### LogIn ###\n");

    while (cmd != 's') {
        printf("Ingrese el comando deseado (r)egistrar, (i)mprimir, (l)ogear, (s)alir: ");
        scanf("%c", &cmd);

        if (cmd == 'r') {
            printf("--- :: Registrar usuario :: ---\n");
            printf("Ingrese el nombre de usuario: ");
            scanf("%s", &usuario);
            printf("Ingrese su contrasena: ");
            scanf("%s", &contrasena);
            insertarTabla(logIN_tabla, usuario, contrasena);
        } else if (cmd == 'i') {
            printf("--- :: Imprimir Tabla :: ---\n");
            imprimirTabla(logIN_tabla);
        } else if (cmd == 'l') {
            printf("--- :: Logear usuario :: ---\n");
            printf("Ingrese el nombre de usuario: ");
            scanf("%s", &usuario);
            printf("Ingrese su contrasena: ");
            scanf("%s", &contrasena);

            if (estaDefinida(logIN_tabla, usuario)) {
                char *passAlmacenada = recuperarClave(logIN_tabla, usuario);

                if (strcmp(passAlmacenada, contrasena) == 0) {
                    printf("Usuario reconocido exitosamente.\n");
                } else {
                    printf("Usuario NO reconocido.\n");
                }
            } else {
                printf("Nombre de usuario no registrado.\n");
            }
        }
    }

    return 0;
}