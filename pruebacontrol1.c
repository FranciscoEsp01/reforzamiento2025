#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct persona{
    char *rut;
    int id;
    char *nombre;
    int edad;
};

struct nodoPersona{
    struct persona *datos;
    struct nodoPersona *sig;
};

struct persona *crearPersona(char *rut, int id, char *nombre, int edad){
    struct persona *nuevaPersona = (struct persona*)malloc(sizeof(struct persona));
    nuevaPersona->rut = (char*)malloc(strlen(rut)*sizeof(struct persona));
    strcpy(nuevaPersona->rut, rut);
    nuevaPersona-> id = id;
    nuevaPersona->nombre = (char*)malloc(strlen(nombre)*sizeof(struct persona));
    strcpy(nuevaPersona->nombre, nombre);
    nuevaPersona-> edad = edad;
    return nuevaPersona;
}

struct nodoPersona* crearNodoPersona(struct nodoPersona **personas, struct persona *nuevo){
    struct nodoPersona *nodoNuevo, *rec;
    if(*personas == NULL){
        struct nodoPersona *nuevaPersona = (struct nodoPersona*)malloc(sizeof(struct nodoPersona));
        nodoNuevo->datos = nuevo;
        return nodoNuevo;
    }
    return NULL;
}

struct persona *buscarPersona(struct nodoPersona *lista, char *rut){
    struct nodoPersona *rec;
    rec = lista;
    while(rec !=NULL){
        if(strcmp(rec-> datos ->rut, rut) == 0){
            return rec->datos;
        }
        rec = rec->sig;
    }
    return NULL;
}

struct nodoPersona *quitarPersona(struct nodoPersona **lista, char *rut){
    struct nodoPersona *rec;
    struct persona *aux;
    if(strcmp((*lista)->datos->rut, rut)== 0){
        aux =(*lista)-> datos;
        (*lista) = (*lista)-> sig;
        return aux;
    }
    rec = (*lista);
    while(rec-> sig != NULL){
        if(strcmp((*lista)->datos->rut, rut)== 0){
            aux = rec-> sig-> datos;
            rec-> sig = rec-> sig-> sig;
            return aux;
        }
        rec = rec->sig;
    }
    return NULL;
}

void ordenarPersonasAsc(struct nodoPersona *personas){
    struct nodoPersona *rec;
    struct persona *temp;
    int flag;
    rec = personas;
    while(rec-> sig != NULL){
        if(rec->datos->id > rec->sig->datos->id){
            temp = rec->datos;
            rec->datos = rec->sig->datos;
            rec->sig->datos = temp;
            flag = 1;
        }
        flag = 0;
        rec = rec->sig;

    }
}