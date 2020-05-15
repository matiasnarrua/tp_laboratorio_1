#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


#define TAM 11
#define TAMSECTOR 5

#define CANTHARCORDE 10




int main()
{
    char seguir = 's';
    char confirma;
    int proximoId = 1000;
    Employee lista[TAM];
    //  eSector sectores[TAMSECTOR] = { { 1, "Sistemas" },{ 2, "RRHH" },{ 3, "Compras" },{ 4, "Ventas" },{ 5, "Contable" } };

    initEmployees(lista, TAM);

    hardcodearEmpleados(lista, CANTHARCORDE);
    proximoId += CANTHARCORDE;

    do
    {
        switch(menu())
        {

        case 1:
            if ( addEmployees(proximoId, lista, TAM ) == 1)
            {
                proximoId ++ ;
            }
            break;

        case 2:
            modificarEmpleado(lista, TAM);
            break;

        case 3:
            removeEmployee(lista, TAM);
            break;

        case 4:
            sortEmployees(lista, TAM, 1);

            printEmployees(lista, TAM);
            break;

        case 5:
            printf("Confirma salir ?");
            fflush(stdin);
            scanf("%c", &confirma);
            if (confirma == 's')
            {
                seguir = 'n';
            }
            break;
        }
        system ("pause");
    }
    while(seguir == 's');




    return 0;
}


