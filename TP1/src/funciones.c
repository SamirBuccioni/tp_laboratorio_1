/*
 * funciones.c
 *
 *  Created on: Apr 14, 2020
 *      Author: samir
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


int utn_getNumero(int* pResultado, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = 1;
	int bufferInt;
	if(pResultado != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			__fpurge(stdin);
			scanf("%d",&bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				if(reintentos >0){
					printf("%s", mensajeError);
				}
				else if(reintentos == 0){
					printf("Ha agotado mi paciencia con el último error. Usted es tonto o se hace?\n\n");
				}
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

float getFloat(char mensaje[]){
	float auxiliar;
	printf("%s", mensaje);
	__fpurge(stdin);
	scanf("%f", &auxiliar);
	return auxiliar;
}

float sumar(float* numero1, float* numero2){
	float resultado;
	resultado = *numero1 + *numero2;
	return resultado;
}
float restar(float* numero1, float* numero2){
	float resultado;
	resultado = *numero1 - *numero2;
	return resultado;
}
float multiplicar(float* numero1, float* numero2){
	float resultado;
	resultado = *numero1 * *numero2;
	return resultado;
}
int dividir(float* numero1, float* numero2, float* cocien7e){

	if(*numero2 != 0){
	*cocien7e = *numero1 / *numero2;
	return 0;
	}
	else{
		return -1;
	}
}
float factoriar(float* numero){
	int i;
	float bufferInt = *numero;
	if (*numero < 0)
		for (i = -1; i > *numero; --i) {
			bufferInt = bufferInt *i;
		}
	    else {
	        for (i = 1; i < *numero; ++i) {
	        	bufferInt =bufferInt * i;
	        }
	    }
	return bufferInt;
}
