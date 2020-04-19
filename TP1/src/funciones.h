/*
 * funciones.h
 *
 *  Created on: Apr 14, 2020
 *      Author: samir
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

int utn_getNumero(int* pResultado, char* mensajeError, int minimo,int maximo,int reintentos);
/**\brief: pide y valida un numero con punto flotante.
 *
 *\param: int direccion de memoria en la cual se guardara el numero
 *\param: char mensaje de error
 *\param: int minimo dentro del rango valido
 *\param: int maximo dentro del rango valido
 *\param: int cantidad de reintentos que tiene el usuario (iteraciones)
 *\return: int que permite definir el exito de la función.
 */
float getFloat(char mensaje[]);
/**\brief: pide un numero con decimales
 * \param: char mensaje solicitando numero
 * \return: float numero obtenido
 */
float sumar(float* numero1, float* numero2);
/**\brief: suma dos numeros
 * \param: float numero a sumar
 * \param: float segundo numero a sumar
 * \return: float resultado de la suma
 */
float restar(float* numero1, float* numero2);
/**\brief: resta dos numeros
 * \param: float numero a restar
 * \param: float numero restado
 * \return: float resultado de la resta
 */
float multiplicar(float* numero1, float* numero2);
/**\brief: multiplica un numero
 * \param: float multiplicando
 * \param: float multiplicador
 * \return: float producto
 */
int dividir(float* numero1, float* numero2, float* cocien7e);
/**\brief: divide un numero y valida el segundo para que pueda darse correctamente la operación
 * \param: float dividendo
 * \param: float divisor
 * \param: float direccion de memoria donde se graba el numero
 * \return: cociente
 */
float factoriar(float* numero);
/**\brief: encuentra el factorial de un numero
 * \param: float cuyo factorial quiere obtenerse
 * \return: float factorial
 */

#endif /* FUNCIONES_H_ */
