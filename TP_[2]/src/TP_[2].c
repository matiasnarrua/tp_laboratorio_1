/*
 ============================================================================
 Name        : TP_[2].c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


#define TAM 1000
#define TAMSECTOR 5

#define CANTHARCORDE 10




int main()
{
	setbuf(stdout, NULL);

    char confirma;
    int flagSeguir = 1;
    int proximoId = 1000;
    Employee lista[TAM];
    int flag =0;

    initEmployees(lista, TAM);

//------------------- COMENTAR ESTAS 3 LINEAS SIGUENTES PARA QUITAR HARDCODE----------------------------//
    hardcodearEmpleados(lista, CANTHARCORDE);
    proximoId += CANTHARCORDE;
    flag=1;
//------------------------------------------//

    do
    {
        switch(menu())
        {

        case 1:
            if ( addEmployees(proximoId, lista, TAM ) == 1)
            {   flag=1;
                proximoId ++ ;
            }
            break;

        case 2:
        	if(flag == 1){

            modificarEmpleado(lista, TAM);
        	}
        	else
            {
                printf("Error.... Primero debe realizar el alta de un Empleado");
            }
            break;

        case 3:
        	if(flag == 1){

            removeEmployee(lista, TAM);
        	        	}
        	        	else
        	            {
        	                printf("Error.... Primero debe realizar el alta de un Empleado");
        	            }
            break;

        case 4:
        	if(flag == 1){

            sortEmployees(lista, TAM, 1);

            printEmployees(lista, TAM);
        	        	}
        	        	else
        	            {
        	                printf("Error.... Primero debe realizar el alta de un Empleado");
        	            }
            break;

        case 5:

            printf("Confirma que quiere salir? (s/n):  ");
            				fflush(stdin);
            				scanf("%c", &confirma);
            				if (confirma == 'n') {
            					flagSeguir = 1;
            				} else if (confirma == 's') {
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

    }
    while(flagSeguir == 1);




    return 0;
}

