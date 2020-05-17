/*
 * functions.h
 *
 *  Created on: May 16, 2020
 *      Author: samir
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/** \brief muestra las opciones del menu y permite al usuario elegir una.
 *
 * \param explicita las opciones al usuario
 * \param pone un tope de opciones para validar.
 * \return int devuelve la opcion elegida
 */
int printMenu(char opcionesMenu[], int cantidadOpciones);

int getInt (char mensaje[]);

#endif /* FUNCTIONS_H_ */
