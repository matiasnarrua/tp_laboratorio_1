/*
 * ArrayEmployees.c
 *
 *  Created on: 11 oct. 2021
 *      Author: Mati
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"

#include "hardcodear.h"

void initEmployees(Employee vec[], int len )
{
    for(int i=0; i<len; i++)
    {
        vec[i].isEmpty = 1;

    }
}

int addEmployees (int idx,Employee vec[], int len)
{
    int todoOk = 0;
    int indice = buscarLibres(vec, len);
    Employee auxEmpleado;

    system("cls");
    printf("***** Alta Empleado *****\n\n");
    if (  indice == -1 )
    {

        printf("Sistema Completo\n\n");
    }
    else
    {
        auxEmpleado.id = idx;
        printf("ingrese Nombre: ");
        fflush(stdin);
        fgets(auxEmpleado.name, 20, stdin);
       	strtok(auxEmpleado.name, "\n");
       	strlwr(auxEmpleado.name);
       	auxEmpleado.name[0]= toupper(auxEmpleado.name[0]);


        printf("ingrese Apellido: ");
        fflush(stdin);
        fgets(auxEmpleado.lastName, 20, stdin);
      	strtok(auxEmpleado.lastName, "\n");
      	strlwr(auxEmpleado.lastName);
      	       	auxEmpleado.lastName[0]= toupper(auxEmpleado.lastName[0]);

        printf("ingrese sueldo: ");
        scanf("%f",&auxEmpleado.salary);
        while(auxEmpleado.salary<1 ){
                                                	 printf("El sueldo no puede ser menor a 0, Ingrese de nuevo: ");
                                                	                    scanf("%f", &auxEmpleado.salary);
                                                }

        printf("Ingrese Sector: ");
        scanf("%d",&auxEmpleado.sector);

        auxEmpleado.isEmpty = 0;

        vec[indice] = auxEmpleado;
        todoOk = 1;
    }
    return todoOk;
}
int findEmployeesById (int id,Employee vec[],int len )
{
    int indice = -1;
    for(int i=0; i<len; i++)
    {
        if(vec[i].id == id && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void removeEmployee (Employee vec[], int len )
{
    int id ;
    int indice;
    char confirma;
    system("cls");
    printf("*****Baja Empleado *****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);
    indice = findEmployeesById(id, vec, len);

    if(indice == -1)
    {

        printf("No hay registro del empleado con el Id: %d\n",id);
    }
    else
    {
        printEmployee(vec[indice]);
        printf("Confirma baja[S/N] ?");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma == 's')
        {
            vec[indice].isEmpty = 1;
            printf("Se ha realizado la baja con exito \n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}

void sortEmployees(Employee vec[], int len, int order)
{
    Employee auxEmpleado;
    for(int i=0; i<len-1; i++)
    {
        for(int j= i+1; j<len; j++)
        {
           if (order ==0){
             if( strcmp(vec[i].lastName, vec[j].lastName)>0 )
            {

                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j] = auxEmpleado;
            }
            else if (strcmp(vec[i].lastName, vec[j].lastName)==0 && vec[i].sector < vec[j].sector)
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j] = auxEmpleado;
            }
           }
           if (order ==1){
               if( strcmp(vec[i].lastName, vec[j].lastName)>0 )
            {

                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j] = auxEmpleado;
            }
            else if (strcmp(vec[i].lastName, vec[j].lastName)==0 && vec[i].sector < vec[j].sector)
            {
                auxEmpleado=vec[i];
                vec[i]=vec[j];
                vec[j] = auxEmpleado;
            }
           }
        }
    }
}
void printEmployees(Employee vec[], int len)
{
    int flag = 0;
    printf("*****Listado Empleados*****\n\n");
    printf("  Id          Apellido             Nombre       Sueldo       Sector\n");

    for(int i=0; i<len; i++)
    {
        if(vec[i].isEmpty == 0)
        {
            printEmployee(vec [i]);
            flag = 1;
        }
    }
    if(flag ==0)
    {
        printf("****No hay empleados que mostrar****\n\n");
    }
}
void printEmployee(Employee emp)
{
     printf("%5d   %15s     %15s      %.2f     %d\n", emp.id, emp.lastName , emp.name, emp.salary,emp.sector);

}
int buscarLibres (Employee vec[],int tam )
{
    int indice = -1;
    for(int i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


void modificarEmpleado(Employee vec[], int tam )
    {
        int id ;
        int indice;
        char confirma;
        int opcion;
        float nuevoSueldo;
        char nuevoNombre [20];
        char nuevoApellido[20];
        int nuevoSector;

        system("cls");
        printf("***** Modificar Empleado *****\n\n");
        printf("Ingrese id: ");
        scanf("%d", &id);
        indice = findEmployeesById(id, vec, tam);

        if(indice == -1)
        {
            printf("No hay registro del empleado con el Id: %d\n",id);
        }
        else
        {
            printEmployee(vec[indice]);

            printf("Modificar este empleado[S/N] ?");
            fflush(stdin);
            scanf("%c", &confirma);

            if(confirma == 's')
            {
                printf("Modificar:\n1_Nombre\n2_Apellido\n3_Salario\n4_Sector\n5_Salir\n\nSeleccione una opcion: ");
                scanf("%d", &opcion);
                switch(opcion)
                {

                case 1:
                    printf("ingrese nuevo Nombre: ");
                    fflush(stdin);
                    			fgets(nuevoNombre, 20, stdin);
                    			strtok(nuevoNombre, "\n");
                    			strlwr(nuevoNombre);
                    			nuevoNombre[0]= toupper(nuevoNombre[0]);
                  strcpy( vec[indice].name,nuevoNombre);
                    printf("Se ha actualizado con exito \n\n");

                    break;

                case 2:
                    printf("ingrese nuevo Apellido: ");
                    fflush(stdin);
                                  fgets(nuevoApellido, 20, stdin);
                              	strtok(nuevoApellido, "\n");
                              	strlwr(nuevoApellido);
                              	nuevoApellido[0]= toupper(nuevoApellido[0]);
                   strcpy(vec[indice].lastName, nuevoApellido);
                    printf("Se ha actualizado con exito \n\n");

                    break;

                case 3:

                    printf("ingrese nuevo sueldo: ");
                    scanf("%f", &nuevoSueldo);
                    while(nuevoSueldo<1 ){
                                        	 printf("El sueldo no puede ser menor a 0, Ingrese de nuevo: ");
                                        	                    scanf("%f", &nuevoSueldo);
                                        }
                    vec[indice].salary = nuevoSueldo;
                    printf("Se ha actualizado con exito \n\n");
                    break;

                case 4:
                    printf("ingrese nuevo sector: ");
                    scanf("%d", &nuevoSector);
                    while(nuevoSector<1 || nuevoSector>5){
                    	 printf("ingrese nuevo sector Valido (1-5): ");
                    	                    scanf("%d", &nuevoSector);
                    }
                    vec[indice].sector = nuevoSector;
                    printf("Se ha actualizado con exito \n\n");
                    break;

                case 5:
                    printf("Confirma salir ?");
                    fflush(stdin);
                    scanf("%c", &confirma);
                    if (confirma == 's')
                    {
                        break;
                    }

                }

            }else
                {
                    printf("Se ha cancelado la operacion\n\n");
                }
        }}


int menu()
{
    int opcion;

    system("cls");
    printf("***** Gestion de Empleados *****\n\n");
    printf("1. Alta Empleado\n2. Modificar Empleado\n3. Baja Empleado\n4. Informar Empleados\n5. Salir\n\n");
    fflush(stdin);
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}


        void hardcodearEmpleados(Employee vec[],int cant)
{
    for(int i =0; i< cant; i++)
    {

        vec[i].id =ids[i];
        strcpy( vec[i].name, nombres [i]);
        strcpy( vec[i].lastName, apellidos[i]);
        vec[i].salary = sueldos[i];
        vec[i].sector = idsSector[i];
        vec[i].isEmpty = 0;
    }
}
