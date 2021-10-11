/*
 * ArrayEmployees.h
 *
 *  Created on: 11 oct. 2021
 *      Author: Mati
 */

#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED


typedef struct
{
    int id;
    char name [51];
    char lastName [51];
    float salary;
    int sector;
    int isEmpty;

} Employee;

#endif // ARRAYEMPLOYEES_H_INCLUDED


void initEmployees(Employee vec[], int len );
int addEmployees (int idx,Employee vec[], int len);
int findEmployeesById (int id,Employee vec[],int len );
void removeEmployee (Employee vec[], int len );

void sortEmployees(Employee vec[], int len , int order);

void printEmployees(Employee vec[], int len);
void printEmployee(Employee emp);

int buscarLibres (Employee vec[],int tam );


void modificarEmpleado(Employee vec[], int tam );

int menu();


void hardcodearEmpleados(Employee vec[],int cant);



