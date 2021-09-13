/*
 ============================================================================
 Name        : TP1_MatiasArrua.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "matias.h"

int main(void) {
	setbuf(stdout, NULL);
	float num1;
	float num2;
	float x;
	float y;
	int opcion;
	int flagSeguir = 1;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	char continuar;
	float suma;
	float resta;
	float divicion;
	float multiplicacion;
	float factorizacion1;
	float factorizacion2;

	do {

		if (flag1 == 1 && flag2 == 1) {
					printf(	"-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n1- Ingresar 1er operando (A = %.2f)\n",x);
					printf("2- Ingresar 2do operando (B = %.2f)\n", y);
					printf("3- Calcular todas las operaciones\n");
					printf("4- Informar resultados (A-B)\n");
					printf("5- Salir\n-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n\n");

				}
		else if (flag1 == 1) {
			printf(	"-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n1- Ingresar 1er operando (A = %.2f)\n",	x);
			printf("2- Ingresar 2do operando (B = y)\n");
			printf("3- Calcular todas las operaciones\n");
			printf("4- Informar resultados (A-B)\n");
			printf("5- Salir\n-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n\n");
		}
		else if (flag2 == 1) {
					printf(	"-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n1- Ingresar 1er operando (A = x)\n");
					printf("2- Ingresar 2do operando (B = %.2f)\n", y);
					printf("3- Calcular todas las operaciones\n");
					printf("4- Informar resultados (A-B)\n");
					printf("5- Salir\n-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n\n");
				}
		  else {
			printf("-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n1- Ingresar 1er operando (A = x)\n");
			printf("2- Ingresar 2do operando (B = y)\n");
			printf("3- Calcular todas las operaciones\n");
			printf("4- Informar resultados (A-B)\n");
			printf("5- Salir\n-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n\n");
		}
		printf("Ingrese una opcion: ");

		scanf("%d", &opcion);
		switch (opcion) {
		case 1:
			system("cls");
			printf("\nPor favor ingrese el primer operando: ");
			scanf("%f", &num1);
			x = num1;
			flag1 = 1;
			break;

		case 2:
			system("cls");
			printf("\nPor favor ingrese el segundo operando: ");
			scanf("%f", &num2);
			y = num2;
			flag2 = 1;
			break;

		case 3:
			system("cls");
			if (flag1 == 1 && flag2 == 1) {
				suma = sumar(num1, num2);
				resta = restar(num1, num2);
				multiplicacion = multiplicar(num1, num2);

				if (num1 > 0) {
					factorizacion1 = factorial(num1);
				}

				if (num2 > 0) {
					factorizacion2 = factorial(num2);
				}

				if (num2 > 0) {
					divicion = dividir(num1, num2);
				}
				printf(
						"Ya se han calculado todos los resultados.\nPor favor elija la siguiente opcion\n\n");
				flag3 = 1;
			} else {
				if ((flag1 == 0 && flag2 == 1) || (flag1 == 0 && flag2 == 0)) {
					printf("Falta ingresar el primer operando\n");
				}

				if ((flag1 == 1 && flag2 == 0) || (flag1 == 0 && flag2 == 0)) {

					printf("Falta ingresar el segundo operando\n\n");

				}
			}

			break;
		case 4:
			system("cls");
			if (flag3 == 1) {
				printf("La suma de %.2f + %.2f es: %.2f\n", num1, num2, suma);
				printf("La resta de %.2f - %.2f es: %.2f\n", num1, num2, resta);
				printf("La multiplicacion de %.2f * %.2f es: %.2f\n", num1,
						num2, multiplicacion);

				if (num1 <= 0) {
					printf(
							" No se puede hacer el factorial de %.2f ya que es un numero negativo o cero \n",
							num1);
				} else {
					printf("El factorial de %.2f es: %.2f\n", num1,
							factorizacion1);
				}
				if (num2 <= 0) {
					printf(
							" No se puede hacer el factorial de %.2f ya que es un numero negativo o cero \n",
							num2);
				} else {
					printf("El factorial de %.2f es: %.2f\n", num2,
							factorizacion2);
				}

				if (num2 == 0) {
					printf("No se puede dividir por 0\n\n");
				} else {
					printf("La divicion de %.2f / %.2f es: %.2f\n\n", num1,
							num2, divicion);
				}
			} else {
				printf(
						"Debe realizar los calculos antes de ver los resultados\n\n");
			}
			break;

		case 5:
			printf("Confirma que quiere salir? (s/n):  ");
			fflush(stdin);
			scanf("%c", &continuar);
			if (continuar == 'n') {
				flagSeguir = 1;
			} else if (continuar == 's') {
				flagSeguir = 0;
			} else {
				printf("ingrese una opcion correcta");
			}
			system("cls");
			break;
		default:
			printf("Elija una opcion correcta del menu\n\n");
			break;
		}
	} while (flagSeguir == 1);

	return EXIT_SUCCESS;
}
