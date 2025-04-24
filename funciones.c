#include <stdio.h>
#include <stdlib.h>
#include "juego.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}




// Función para imprimir el tablero. Aquí se dibujan las figuras (hexágono o rombo)
// y, en la línea central (tipoLinea == 1) se muestra la ficha si está presente.
int tablero(void) {
    // Encabezado de columnas (0 a COLUMNAS-1)
    printf("    ");
    for (int col = 0; col < COLUMNAS; col++) {
        printf("  %2d  ", col);
    }
    printf("\n");

    // Cada celda del tablero se dibuja usando 3 líneas.
    for (int fila = 0; fila < FILAS * 3; fila++) {
        int tipoLinea = fila % 3;      // 0: parte superior, 1: línea central, 2: inferior
        int filaTablero = fila / 3;      // índice lógico de fila en el tablero

        // Mostrar número de fila en la línea media.
        if (tipoLinea == 1) {
            printf(" %2d ", filaTablero);
        } else {
            printf("    ");
        }

        for (int col = 0; col < COLUMNAS; col++) {
            int imprimirFigura = 0;

            // Según las reglas de diseño:
            // Si la fila lógica es par se muestran figuras (hexágonos) en columnas pares.
            // Si la fila lógica es impar se muestran figuras (rombos) en columnas impares.
            if ((filaTablero % 2 == 0 && col % 2 == 0) ||
                (filaTablero % 2 == 1 && col % 2 == 1)) {
                imprimirFigura = 1;
            }

            if (imprimirFigura) {
                if (filaTablero % 2 == 0) {
                    // Filas pares: hexágonos
                    if (tipoLinea == 0) {
                        printf("  __  ");
                    } else if (tipoLinea == 1) {
                        // En la línea central, se muestra la ficha si existe.
                        if (piezas[filaTablero][col] != ' ') {
                            printf(" |%c| ", piezas[filaTablero][col]);
                        } else {
                            printf(" /  \\ ");
                        }
                    } else {
                        printf(" \\__/ ");
                    }
                } else {
                    // Filas impares: rombos
                    if (tipoLinea == 1) {
                        if (piezas[filaTablero][col] != ' ') {
                            printf(" |%c| ", piezas[filaTablero][col]);
                        } else {
                            printf(" /  \\ ");
                        }
                    } else if (tipoLinea == 2) {
                        printf(" \\  / ");
                    } else {
                        printf("      "); // Sin parte superior en rombo
                    }
                }
            } else {
                printf("      "); // Espacio en blanco en celdas sin figura
            }
        }
        printf("\n");
    }
    return 0;
}