#ifndef JUEGO_H
#define JUEGO_H

#define FILAS 11
#define COLUMNAS 11
#define LONGITUD_NOMBRE 50

typedef char Ficha;
// Matriz global que almacena las fichas en cada celda del tablero.
extern Ficha piezas[FILAS][COLUMNAS];

extern struct Jugador J1;
extern struct Jugador J2;

struct Jugador { //Se define la estructura de Jugador, que tendrá el número, el color y el nombre
    char color;
    char nombre[LONGITUD_NOMBRE];
};





#endif // JUEGO_H