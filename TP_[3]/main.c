#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "matias.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    setbuf (stdout, NULL);
    int option ;
    int id= 0;
    char check = 'n';
    int validacion;
    int flag =0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	option=menu();
        switch(option)
        {
            case 1:
              validacion =  controller_loadFromText("data.csv",listaEmpleados);
              switch(validacion)
              {
              case -1:
                  printf("El archivo no se pudo abrir.\n");
                  break;
              case 0:
                  printf("se abrio exitosamente el archivo\n");
                  flag=1;
                  break;
              case 1:
                  printf("No pudo acceder a la opcion de carga desde archivo ");
                  break;
              case 2:
                  printf("La lista ya esta cargada\n");
                  break;
              }
                break;
         case 2:
        	 validacion = controller_loadFromBinary("data.bin", listaEmpleados);
            id = proximoId(listaEmpleados);

            switch(validacion)
                         {
                         case -1:
                             printf("El archivo no se pudo abrir\n");
                             break;
                         case 0:
                             printf("se abrio exitosamente el archivo\n");
                             flag=1;
                             break;
                         case 1:
                             printf("No pudo acceder a la opcion de carga desde archivo\n");
                             break;
                         case 2:
                             printf("La lista ya esta cargada\n");
                             break;
                         }

            break;
        case 3:
        	if (flag == 1){
            id = proximoId(listaEmpleados);
            validacion = controller_addEmployee(listaEmpleados, &id);
            switch(validacion)
                        {
                        case -1:
                            printf("No se pudo agregar al empleado en la lista.\n");
                            break;
                        case 0:
                            printf("Se agrego al empleado en la lista exitosamente\n");
                            break;
                        case 1:
                            printf("No pudo acceder al alta de empleados\n");
                            break;
                        case 2:
                            printf("Ha cancelado la operacion\n");
                            break;
                        }}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}
            break;
        case 4:
        	if (flag == 1){
        	validacion =  controller_editEmployee(listaEmpleados);
             switch(validacion)
                         {
                         case -1:
                             printf("\nNo se pudo acceder al menu de modificaciones\n");
                             break;
                         case 0:
                             printf("Se guardaron las modificaciones exitosamente\n");
                             break;
                         case 1:
                        	 printf("El empleado no existe\n");
                        	 break;
                         case 3:
                             printf("Ha cancelado la operacion\n");
                             break;
                         }}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}
            break;
        case 5:
        	if (flag == 1){
        	validacion =  controller_removeEmployee(listaEmpleados);
        	switch(validacion)
        	            {
        	            case -1:
        	                printf("No se pudo eliminar al empleado de la lista\n");
        	                break;
        	            case 0:
        	                printf("Se elimino al empleado exitosamente\n");
        	                break;
        	            case 1:
        	                printf("No pudo acceder a la baja de empleados\n");
        	                break;
        	            case 2:
        	                printf("Ha cancelado la operacion\n");
        	                break;
        	            case 3:
        	                printf("El empleado no existe\n");
        	                break;
        	            }}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}
            break;
        case 6:
        	if (flag == 1){
        	validacion =    controller_ListEmployee(listaEmpleados);
            switch(validacion)
            {
            case -1:
                printf("No pudo acceder al listado de empleados\n");
                break;
            case 1:
                printf("La lista esta vacia\n");
                break;
            }}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}
            break;
        case 7:
        	if (flag == 1){
        	validacion =   controller_sortEmployee(listaEmpleados);
        	switch(validacion)
        	            {
        	            case -1:
        	                printf("No pudo realizar el ordenamiento\n");
        	                break;
        	            case 0:
        	                printf("Se ha ordenado a los empleados existosamente\n");
        	                break;
        	            case 1:
        	                printf("No pudo acceder al ordenamiento de empleados\n");
        	                break;
        	            case 2:
        	                printf("La lista esta vacia\n");
        	                break;
        	            case 3:
        	                printf("Ha salido del submenu de ordenamiento\n");
        	                break;
        	            }
        	}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}


            break;
        case 8:
        	if (flag == 1){
        	validacion =   controller_saveAsText("data.csv", listaEmpleados);
        	switch(validacion)
        	            {
        	            case -1:
        	                printf("No se pudo acceder al guardado en TEXTO\n");
        	                break;
        	            case 0:
        	                printf("El archivo en modo TEXTO se guardo exitosamente\n");
        	                break;
        	            }
        	}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}



            break;
        case 9:
        	if (flag == 1){
        	validacion =   controller_saveAsBinary("data.bin", listaEmpleados);
        	 switch(validacion)
        	            {
        	            case -1:
        	                printf("No se pudo acceder al guardado en BINARIO\n");
        	                break;
        	            case 0:
        	                printf("El archivo en modo BINARIO se guardo exitosamente \n");
        	                break;
        	            }
        	}
        	else{
        		printf("Debe cargar el archivo primero\n");
        	}

            break;
        case 10:
        	check = getConfirmacion("\nEsta seguro que desea salir? s/n:  ");


                    break;
        default:
                    printf("Ingrese una opcion correcta.\n");
                    system("pause");
                    break;

        }
    }while(check == 'n');

    printf("Programa finalizado");
    return 0;
}

