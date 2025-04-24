#include <stdio.h>
#include <stdlib.h>
#include "juego.h"

/* void inicializarPiezas() { //? Crea la matriz y deja los espacios en blancos que luego son reemplazados por los valores principales
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            piezas[i][j] = ' ';
        }
    }
} */






int main(void) {
/*     // Inicializar la matriz de fichas.
    inicializarPiezas(); */ //!VERIFICAR SI ES NECESARIO

    // Colocar algunas fichas en el tablero para el ejemplo.
    // Supongamos que las fichas de un equipo son 'V' y 'v' y de otro 'R' y 'r'.
    // Colocamos piezas en los bordes superior e inferior.
    piezas[0][0] = 'V';
    piezas[0][2] = 'V';
    piezas[0][4] = 'V';
    piezas[0][6] = 'V';
    piezas[0][8] = 'V';
    piezas[0][10] = 'V';
    piezas[1][1] = 'v';
    piezas[1][3] = 'v';
    piezas[1][5] = 'v';
    piezas[1][7] = 'v';
    piezas[1][9] = 'v';

    piezas[9][1] = 'r';
    piezas[9][3] = 'r';
    piezas[9][5] = 'r';
    piezas[9][7] = 'r';
    piezas[9][9] = 'r';
    piezas[10][0] = 'R';
    piezas[10][2] = 'R';
    piezas[10][4] = 'R';
    piezas[10][6] = 'R';
    piezas[10][8] = 'R';
    piezas[10][10] = 'R';

    int ganador = 0;

    



    return 0;
}