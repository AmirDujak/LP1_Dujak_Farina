#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juego.h"

void reglas() {
    printf("Las reglas del juego son las siguientes: \n");
    printf("Cada jugador tiene 11 fichas. 6 fichas grandes y 5 fichas chicas. \n");
    printf("El objetivo del juego es llevar una ficha de un color al lado contrario o capturar todas las fichas del rival. Realizar cualquiera de los dos objetivos es suficiente para ganar el juego. \n");
    printf("El tablero consiste en 11x6 celdas. 6 hexágonos por fila y 5 rombos por fila. \n");
    printf("\n");
    printf("--- MOVIMIENTOS VÁLIDOS --- \n");
    printf("Las fichas se mueven únicamente vertical o diagonalmente. Las fichas pueden avanzar únicamente una casilla por turno y solamente se puede mover una ficha por turno. \n");
    printf("Las fichas grandes solo pueden capturar en los hexágonos a cualquiera de las dos fichas (grandes o pequeñas), mientras que las fichas pequeñas solo capturan en rombos (a grandes o pequeñas), siempre que las fichas estén en una celda adyacente válida. \n");
    printf("--- MÉTODOS DE CAPTURA --- \n");
    printf("Para capturar una ficha, la ficha atacante ocupa la posición de la ficha a ser capturada (una ficha pequeña que se encuentra en un hexágono captura una ficha grande que se encuentra en un rombo y se queda en en la posición de la ficha capturada, en este caso, el rombo). \n");
    printf("--- IMPORTANTE --- \n");
    printf("Las fichas no pueden retroceder, solamente pueden irse hacia delante. \n");
}

int primerTurno(void){ //Esta función sirve para elegir cuál jugador jugará primero
    int X;
    printf("Ingrese el número del jugador que jugará primero (1 o 2): ");
    scanf("%d", &X);
    while (X != 1 && X != 2){
        printf("El número introducido no es valido.\n Por favor ingrese 1 o 2: \n");
    }
    return X;
} //Luego se trabajará con el valor de la variable X para determinar cuál jugador jugará primero

void ingresarNombre (char *nombre, int num){
    printf("Introduzca el nombre del jugador %d: ", num);
    int i, c;
    for (i = 0; i < LONGITUD_NOMBRE; i++, *nombre++) {
        c = getchar();
        if (c == '\n'){
            break;
        }
        *nombre = c;
    }
    *nombre = '\0';
}

char leerColor(void) {
    char c;
    do {
        printf("Jugador 1 introduzca su color: ");
        c = getchar();
        limpiarBuffer();
        c = toupper(c); //?Función que convierte minúsculas a mayúsculas de la librería de ctype.h
        if (c != 'R' && c != 'V') {
            printf("El color introducido no es válido.\n Por favor introduzca R o V: \n");
        }
    } while (c != 'R' && c != 'G');
    return c; //?Se tiene en cuenta que el color no asignado será asignado al otro jugador
}

void preJuego(void) {
    reglas(); //?Muestra las reglas del juego
    printf("\n");
    char nombre[LONGITUD_NOMBRE];
    printf("Primero se tomarán los datos del jugador 1: \n");
    ingresarNombre(nombre, 1);
    strcpy(J1.nombre, nombre);
    J1.color =leerColor();
    printf("Ahora se tomarán los datos del jugador 2: \n");
    ingresarNombre(nombre, 2);
    strcpy(J2.nombre, nombre);
    if (J1.color == 'R') {
        J2.color = 'V';
    } else {
        J2.color = 'R';
    }
}