#include <stdio.h>
#include <stdlib.h>

struct SistemaEventos{
    struct ListaArtistas *artistas; 
    struct NodoPais *paises;
};
struct ListaArtistas{
    int cantArtistas;
    struct NodoArtista *abbArtistas;
};
struct NodoArtista{
    struct Artista *datosArtista;
    struct NodoArtista *izq, *der;
};
struct NodoPais{
    struct Pais *pais;
    struct NodoPais *sig;
};
struct Pais{
    char *nombre;
    struct NodoRecinto *recintos;
};
struct NodoRecinto{
    struct Recinto *datosRecinto;
    struct NodoRecinto *ant, *sig;
};
struct Recinto{
    int id;
    char *nombre;
    int capacidad;
    struct Evento **eventos; 
    int pLibreEventos;
};

struct Evento{
    int id;
    char *fecha;
    struct Artista *artista; 
};
struct Artista{
    int id;
    char *nombre;
    char *genero;
    char *selloDiscografico;
};
#define tamArreglos 5000

int agregarArtista(struct SistemaEventos *SE, struct Artista nuevoArtista) {
    struct NodoArtista *nuevo, *aux;
    nuevo = (struct NodoArtista *) malloc(sizeof(struct NodoArtista));
    if (nuevo == NULL) {
        return 0; // Error al asignar memoria
    }

    nuevo->datosArtista = (struct Artista *) malloc(sizeof(struct Artista));
    if (nuevo->datosArtista == NULL) {
        free(nuevo);
        return 0; // Error al asignar memoria
    }

    *(nuevo->datosArtista) = nuevoArtista; // Copiar los datos del artista

    // Buscar la posición correcta para insertar el nuevo nodo
    aux = SE->artistas->abbArtistas;
    struct NodoArtista *padre = NULL;
    while (aux != NULL) {
        padre = aux;
        if (nuevoArtista.id < aux->datosArtista->id) {
            aux = aux->izq;
        } else if (nuevoArtista.id > aux->datosArtista->id) {
            aux = aux->der;
        } else {
            // El artista ya existe, liberar la memoria asignada y retornar 0
            free(nuevo->datosArtista);
            free(nuevo);
            return 0;
        }
    }

    // Insertar el nuevo nodo en el ABB
    if (padre == NULL) {
        SE->artistas->abbArtistas = nuevo;
    } else if (nuevoArtista.id < padre->datosArtista->id) {
        padre->izq = nuevo;
    } else {
        padre->der = nuevo;
    }

    SE->artistas->cantArtistas++; // Incrementar el contador de artistas
    return 1; // Artista agregado exitosamente
}