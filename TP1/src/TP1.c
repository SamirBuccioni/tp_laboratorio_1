/*
 1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
2 Cómo realizar y entregar el trabajo práctico
El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP1 de la
materia.
El mismo consistirá en el proyecto de CodeBlocks con el programa funcionando y comentado,
respetando las reglas de estilo de la cátedra. La compilación no deberá arrojar mensajes de
error ni de warnings.
El proyecto deberá contar con la biblioteca descripta en la sección número dos, y se deberá
hacer uso de dichas funciones para resolver la lógica del programa.
 */

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main(void) {
	int opcion;
	int respuesta;
	float num1=0,num2 =0;
	float suma, resta, producto, cociente, factorial1, factorial2;
	int i=0, j=0;
	do{
		printf("1. Ingresar 1er operando A= %.2f \n2. Ingresar 2do operando B= %.2f \n3. Calcular todas las operaciones \n4. Informar resultados \n5. Salir \n", num1, num2);
		respuesta = utn_getNumero(&opcion, "Error. Ingrese una opción válida (1,2,3,4 ó 5)\n", 1, 5, 2);
		if(respuesta == 0){
			switch(opcion){
			case 1:
				num1 = getFloat("Ingrese el primer operando: ");
				break;
			case 2:
				num2 = getFloat("Ingrese el segundo operando: ");
				break;
			case 3:
				i=1;
				suma = sumar(&num1, &num2);
				resta = restar(&num1, &num2);
				producto= multiplicar(&num1, &num2);
				dividir(&num1, &num2, &cociente);
				factorial1 = factoriar(&num1);
				factorial2 = factoriar(&num2);
				break;
			case 4:
				if(i==1){
				printf("\nEl resultado de A+B es: %.2f \nEl resultado de A-B es: %.2f\nEl resultado de A*B es: %.2f\nEl factorial "
						"de A es: %.2f y El factorial de B es: %.2f\n", suma, resta, producto, factorial1, factorial2);
				if(num2 !=0){
					printf("El resultado de A/B es: %.2f\n\n", cociente);
				}
					else{
						printf("A/B no existe! No es posible dividir por cero\n\n");
					}
				}
				else{
					printf("\nAun no ha realizado ninguna operación.\n");
				}
				break;
			case 5:
				j=1;
				break;
			}
		}
	}while(j==0);
	printf("Gracias por usar la Calculadora Virtual. Hasta luego!");
	return EXIT_SUCCESS;
}


