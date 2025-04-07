// Francisco Espinoza //
// Joaquin Muñoz //

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct banco{
    char *nombre;
    char *direccion;
    int saldo;
};

struct nodoBanco{
    struct banco *datos;
    struct nodoBanco *sig, *ant;
};

struct robo{
    char *fecha;
    int monto;
    struct banco *bancoRobado;
};

struct ladron{
    char *apodo;
    char *rut;
    int MAXrobos;
    struct robo *robos;
    int PlibreLadron;
};

struct nodoLadron{
    struct ladron *datosLadron;
    struct nodoLadron *sig;
};

struct bandaCriminal{
    char *nombre;
    struct nodoLadron *headLadrones;
    struct nodoBanco *headBancos;
};
struct nodoBanco *agregarBanco(struct nodoBanco *head, struct banco *banco) {
    struct nodoBanco *nuevoNodo = (struct nodoBanco *)malloc(sizeof(struct nodoBanco));
    nuevoNodo->datos = banco;
    nuevoNodo->sig = NULL;
    nuevoNodo->ant = NULL;

    if (head == NULL) {
        nuevoNodo->sig = nuevoNodo;
        nuevoNodo->ant = nuevoNodo;
        return nuevoNodo;
    } else {
        struct nodoBanco *temp = head;
        while (temp->sig != head) {
            temp = temp->sig;
        }
        temp->sig = nuevoNodo;
        nuevoNodo->ant = temp;
    }
    return head;
}

int contarRobos(struct bandaCriminal *banda, struct banco *banco) {
    struct nodoLadron *rec = banda->headLadrones;
    int i, contador = 0;

    while(rec != NULL){
        struct ladron *ladron = rec->datosLadron;
        for (int i = 0; i < ladron->PlibreLadron; i++) {
            if (ladron->robos[i].bancoRobado == banco) {
                contador++;
            }
        }
        rec = rec->sig;
    }
    return contador;
}

struct nodoBanco *getBancosMasRobados(struct bandaCriminal *banda) {
    if (banda == NULL || banda->headBancos == NULL) return NULL;
    struct nodoBanco *rec = banda->headBancos;
    int maxRobos = 0;
    while (rec != NULL) {
        int robosBanco = contarRobos(banda, rec->datos);
        if (robosBanco > maxRobos) {
            maxRobos = robosBanco;
        }
        rec = rec->sig;
    }

    if (maxRobos == 0) return NULL;

    struct nodoBanco *resultado = NULL;
    rec = banda->headBancos;

    while (rec != NULL) {
        int robosBanco = contarRobos(banda, rec->datos);
        if (robosBanco == maxRobos) {
            resultado = agregarBanco(resultado, rec->datos);
            if (!resultado) return NULL;
        }
        rec = rec->sig;
    }

    return resultado;
}