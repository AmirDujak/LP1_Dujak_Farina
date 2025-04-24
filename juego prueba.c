#include <stdio.h>

#define FILAS 11
#define COLUMNAS 11

typedef char Ficha;

// Matriz global que almacena las fichas en cada celda del tablero.
Ficha piezas[FILAS][COLUMNAS];

// Función para inicializar el arreglo de fichas: todas las celdas se inician en ' ' (vacío).
void inicializarPiezas() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            piezas[i][j] = ' ';
        }
    }
}

// Función para imprimir el tablero.
int tablero(void) {
    // Encabezado de columnas (0 a COLUMNAS-1)
    printf("    ");
    for (int col = 0; col < COLUMNAS; col++) {
        printf("  %2d  ", col);
    }
    printf("\n");

    // Cada celda del tablero se dibuja usando 3 líneas.
    for (int fila = 0; fila < FILAS * 3; fila++) {
        int tipoLinea = fila % 3;
        int filaTablero = fila / 3;

        if (tipoLinea == 1) {
            printf(" %2d ", filaTablero);
        } else {
            printf("    ");
        }

        for (int col = 0; col < COLUMNAS; col++) {
            int imprimirFigura = 0;

            if ((filaTablero % 2 == 0 && col % 2 == 0) ||
                (filaTablero % 2 == 1 && col % 2 == 1)) {
                imprimirFigura = 1;
            }

            if (imprimirFigura) {
                if (filaTablero % 2 == 0) {
                    if (tipoLinea == 0) {
                        printf("  __  ");
                    } else if (tipoLinea == 1) {
                        if (piezas[filaTablero][col] != ' ') {
                            printf(" /%c \\ ", piezas[filaTablero][col]);
                        } else {
                            printf(" /  \\ ");
                        }
                    } else {
                        printf(" \\__/ ");
                    }
                } else {
                    if (tipoLinea == 1) {
                        if (piezas[filaTablero][col] != ' ') {
                            printf(" /%c \\ ", piezas[filaTablero][col]);
                        } else {
                            printf(" /  \\ ");
                        }
                    } else if (tipoLinea == 2) {
                        printf(" \\  / ");
                    } else {
                        printf("      ");
                    }
                }
            } else {
                printf("      ");
            }
        }
        printf("\n");
    }
    return 0;
}

// Función corregida para mover una ficha
void moverFicha(int origenFila, int origenCol, int destinoFila, int destinoCol) {
    if (origenFila < 0 || origenFila >= FILAS || origenCol < 0 || origenCol >= COLUMNAS ||
        destinoFila < 0 || destinoFila >= FILAS || destinoCol < 0 || destinoCol >= COLUMNAS) {
        printf("Coordenadas fuera de rango.\n");
        return;
    }

    if (piezas[origenFila][origenCol] == ' ') {
        printf("No hay ficha en la posición de origen.\n");
        return;
    }

    if (origenFila == destinoFila) {
        printf("Movimiento inválido: misma fila.\n");
        return;
    }

    if ((destinoFila %2==1 && destinoCol %2==1)) {
        printf("Movimiento inválido: casilla destino no válida.\n");
        return;
    }
    if (destinoFila > origenFila + 2){
    	printf("Movimiento invalido, no puedes saltar casillas. \n");
    	return;
    }

    if (piezas[destinoFila][destinoCol] != ' ') {
        printf("Se captura la ficha '%c' en la posición (%d, %d).\n",
               piezas[destinoFila][destinoCol], destinoFila, destinoCol);
    }

    piezas[destinoFila][destinoCol] = piezas[origenFila][origenCol];
    piezas[origenFila][origenCol] = ' ';
}

int main() {
    inicializarPiezas();

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

    piezas[10][0] = 'R';
    piezas[10][2] = 'R';
    piezas[10][4] = 'R';
    piezas[10][6] = 'R';
    piezas[10][8] = 'R';
    piezas[10][10] = 'R';
    piezas[9][1] = 'r';
    piezas[9][3] = 'r';
    piezas[9][5] = 'r';
    piezas[9][7] = 'r';
    piezas[9][9] = 'r';

    int origenFila, origenCol;
    int destinoFila, destinoCol;
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        printf("\nTablero actual:\n");
        tablero();

        printf("\nIngrese las coordenadas de la ficha a mover (origen: fila columna): ");
        if (scanf("%d %d", &origenFila, &origenCol) != 2) {
            printf("Error en la entrada. Terminando el programa.\n");
            break;
        }

        printf("Ingrese las coordenadas destino (fila columna): ");
        if (scanf("%d %d", &destinoFila, &destinoCol) != 2) {
            printf("Error en la entrada. Terminando el programa.\n");
            break;
        }

        moverFicha(origenFila, origenCol, destinoFila, destinoCol);

        printf("\n¿Desea mover otra ficha? (s/n): ");
        scanf(" %c", &continuar);
    }

    printf("\nFin del programa.\n");
    return 0;
}
