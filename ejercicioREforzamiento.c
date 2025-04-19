#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de auto
struct autos {
    char *marca;
    char *codigoMotor;
};

// Nodo de autos (por si quieres una lista enlazada de autos, opcional)
struct nodoautos {
    struct autos *datos;
    struct nodoautos *sig;
};

// Estructura de pista
struct pista {
    char *nombrePista;
    char *pais;
    float longitud; // en km
};

// Estructura para tiempo de cada piloto en una pista
struct tiempoPista {
    struct pista *pista;  // Referencia a la pista
    int tiempo;           // Tiempo en segundos
    struct tiempoPista *sig;
};

// Estructura de piloto
struct piloto {
    char *nombre;
    struct autos *autoPiloto;
    struct tiempoPista *tiempos; // Lista de tiempos en distintas pistas
};

// Nodo de lista de pistas del campeonato
struct nodoPistas {
    struct pista *pista;
    struct nodoPistas *sig;
};

// Estructura principal del campeonato
struct campeonato {
    struct piloto **pilotos;      // Lista de pilotos
    int cantidadPilotos;
    struct nodoPistas *pistas;    // Lista enlazada de pistas
};


//crea una funcion para saber cual piloto gano en cada pista//

struct piloto *ganador(struct campeonato*campeonato, char *nombrePista);

//crea una funcion para detectar un auto con motor ilegal (se ingresara el codigo del motor ilegal)//

struct autos *Autoilegal(struct campeonato *campeonato, int codigoIlegal);
