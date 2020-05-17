/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "ArrayEmployees.h"

#define MAXEMPLEADOS 1000
int main(void)
{
    int opcionMenu;
    int validarMenu = -1;
    Employee listEmployees[MAXEMPLEADOS];
    int sector;
    int id;
    float salario;
    char nombre[51];
    char apellido[51];
    int retorno;
    int indice;
    int orden;

    initEmployees(listEmployees, MAXEMPLEADOS);

    do
    {
          opcionMenu = printMenu("1.ALTAS: Ingreso de nuevo cliente.\n2.MODIFICAR: busqueda de cliente por id y alteracion de sus datos.\n3.BAJA: eliminacion de empleado por Id.\n4.INFORMACION DE EMPLEADOS. \n5.SALIR.", 5);
          if(opcionMenu == 1)
          {
        	 validarMenu=0;
        	 //no me gusta hacerlo asi pero por la estructura de la funcion addEmployee no vi muchas otras opciones..
        	 printf("Ingrese sector: ");
        	 __fpurge(stdin);
        	 scanf("%d", &sector);
        	 printf("Ingrese apellido: ");
        	 __fpurge(stdin);
        	 fgets(nombre,51,stdin);
        	 printf("Ingrese nombre: ");
        	 __fpurge(stdin);
        	 fgets(apellido,51,stdin);
        	 printf("Ingrese id: ");
        	 __fpurge(stdin);
        	 scanf("%d", &id);
        	 printf("Ingrese salario: ");
        	 __fpurge(stdin);
        	 scanf("%f", &salario);
        	 retorno = addEmployee(listEmployees, MAXEMPLEADOS, id, nombre,apellido, salario, sector);
        	 switch(retorno)
        	 {
        	 	 case (0):
                		 printf("Se ha cargado correctamente el cliente\n");
        	 	 break;
        	 	 case -1:
        	 		 	 printf("No hay espacio para cargar al cliente\n");
        	     break;
        	 }
          }
          else if(opcionMenu == 2 || opcionMenu == 3 || opcionMenu == 4)
          {
        	  if(validarMenu!=0)
        	  {
        		  printf("Error. Primero debe ingresar un empleado\n");
        	  }
        	  else
        	  {
        		  switch(opcionMenu)
        		  {
        		  	  case(2):
        		  			id = getInt("Ingrese el id del empleado: ");
							indice = findEmployeeById(listEmployees, MAXEMPLEADOS, id);
							opcionMenu = printMenu("Ingrese el campo a modificar: \n1.Nombre.\n2.Apellido\n3.Salario\n4.Sector.",4);
							switch(opcionMenu)
							{
								case(1):
										printf("Nombre previo: %s\nIngrese nuevo:", listEmployees[indice].name);
										fgets(listEmployees[indice].name, 51, stdin);
										break;
								case(2):
										printf("Apellido previo: %s\nIngrese nuevo:", listEmployees[indice].lastName);
										fgets(listEmployees[indice].lastName, 51, stdin);
										break;
								case(3):
										printf("Salario previo: %f\nIngrese nuevo:", listEmployees[indice].salary);
										__fpurge(stdin);
										scanf("%f", &listEmployees[indice].salary);
										break;
								case(4):
										printf("Sector previo: %d\nIngrese nuevo:", listEmployees[indice].sector);
										__fpurge(stdin);
										scanf("%d", &listEmployees[indice].sector);
										break;
							}
					break;
					case(3):
							id = getInt("Ingrese el id del empleado");
							removeEmployee(listEmployees, MAXEMPLEADOS, id);
							printf("El empleado no existe mas en el sistema");
					break;
					case(4):
							do{
								orden = getInt("Ingrese 1 para ordenar de mayor a menor, o 2 para ordenar de menor a mayor.");
							}while(orden != 1 && orden != 0);
							sortEmployees(listEmployees, MAXEMPLEADOS, orden);
							printEmployees(listEmployees, MAXEMPLEADOS);
					break;
        		  }
        	  }
          }



    }while(opcionMenu != 5);
}
