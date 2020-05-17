/*
 * ArrayEmployees.c
 *
 *  Created on: May 16, 2020
 *      Author: samir
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "ArrayEmployees.h"

#define TRUE 0;



int initEmployees(Employee list[], int len) /*Dado que tanto la dirección del array como la cantidad de empleados son definidas en el código,
										   sin interaccion alguna con el user, la funcion siempre va a ser exitosa y no requiere validación*/
{
	int i;
	for(i=0; i<=len; i++)
	{
		list[i].isEmpty = TRUE;
	}
	return 0;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int i;
	int retorno = -1;
	for(i=0; i<=len; i++)
	{
		if (list[i].isEmpty == 0)
		{
			list[i].id = id;
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = 1;
			strcpy(list[i].name, name);
			strcpy(list[i].lastName, lastName);
			retorno = 0;
			break;
		}
	}
	return retorno;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int i;
	int retorno = -1;

	for(i=0; i<=len; i++)
	{
		if(list[i].id == id)
		{
			retorno = i;
			break;
		}
	}
	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int i;
	int retorno = -1;
	for(i=0; i<=len; i++)
	{
		if(list[i].id == id)
		{
			list[i].isEmpty = TRUE;
			return 0;
			break;
		}
	}
	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	Employee buffer;
	int retorno = -1;
	int i;
	int flagSwap;
	int contador = 0;
	int nuevoLimite;
	if (list != NULL && len > 0)
	{
		nuevoLimite = len -1;
		retorno= 0;
		if(order==1)
		{
			do
			{
				flagSwap=0;
				for(i=0;i<len;i++)
				{
					contador++;
					if(list[i].sector < list[i+1].sector)
					{
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
					else if(list[i].sector == list[i+1].sector && strcmp(list[i].lastName,list[i+1].lastName) < 0)
					{
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}
				nuevoLimite --;
			}while(flagSwap);
		}
		else if(order==0)
		{
			do
			{
				flagSwap=0;
				for(i=0;i<len;i++)
				{
					contador++;
					if(list[i].sector > list[i+1].sector)
					{
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
					else if(list[i].sector == list[i+1].sector && strcmp(list[i].lastName,list[i+1].lastName) > 0)
					{
						flagSwap=1;
						buffer = list[i];
						list[i] = list[i+1];
						list[i+1] = buffer;
					}
				}
				nuevoLimite --;
			}while(flagSwap);
		}
	}
	return retorno;
}

int printEmployees(Employee* list, int length)
{
	int i;
	for(i=0;i<=length; i++)
	{
		if( list[i].isEmpty != 0)
		{
			printf('Indice - Sector - Nombre Apellido - ID - Salario.\n');
			printf('%d-%d- %s %s -- %d - %f \n', &i, list[i].sector, list[i].name, list[i].lastName, list[i].id, list[i].salary);
		}
	}
	return 0;
}
