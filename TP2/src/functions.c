/*
 * functions.c
 *
 *  Created on: May 16, 2020
 *      Author: samir
 */
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int getInt (char mensaje[])
{
    int returnValue;

    printf("%s", mensaje);
    __fpurge(stdin);
    scanf("%d", &returnValue);

    return returnValue;
}

int printMenu(char opcionesMenu[], int cantidadOpciones)
{
    int opcionElegida;

    printf("%s\n", opcionesMenu);
    printf("Ingrese la opcion que desea: ");
    __fpurge(stdin);
    scanf("%d", &opcionElegida);

    while (opcionElegida > cantidadOpciones || opcionElegida < 1)
    {
        printf("Error, opcion invalida. Por favor, reingrese la opcion que desea: ");
        __fpurge(stdin);
        scanf("%d", &opcionElegida);
    }

    return opcionElegida;
}
