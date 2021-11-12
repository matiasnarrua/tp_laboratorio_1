#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "matias.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct {
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
} Employee;

Employee* employee_new();
Employee* employee_newParamStr(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr);
//Employee* employee_newParam(int* id,char* nombre,int* horasTrabajadas,float* sueldo);
void employee_delete();

int employee_setId(Employee *this, int id);
int employee_getId(Employee *this, int *id);

int employee_setNombre(Employee *this, char *nombre);
int employee_getNombre(Employee *this, char *nombre);

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

int employee_setSueldo(Employee *this, int sueldo);
int employee_getSueldo(Employee *this, int *sueldo);

int mayorId(LinkedList *pArrayListEmployee);
int proximoId(LinkedList *pArrayListEmployee);
int showOneEmployee(Employee *employee);
void pedirDatosEmp(char *nombre, char *horasTrabajadas, char *salario);
void* getEmployeeById(LinkedList *pArrayListEmployee, int id);

int compareByHoursWorked(void *pElement1, void *pElement2);
int compareByName(void *pElement1, void *pElement2);
int compareBySalary(void *pElement1, void *pElement2);
int compareById(void *pElement1, void *pElement2);

#endif // employee_H_INCLUDED

