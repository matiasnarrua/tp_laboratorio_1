#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

Employee* employee_new() {
	Employee *newEmp = NULL;
	newEmp = (Employee*) malloc(sizeof(Employee));

	if (newEmp != NULL) {
		employee_setHorasTrabajadas(newEmp, 0);
		employee_setId(newEmp, 0);
		employee_setNombre(newEmp, " ");
		employee_setSueldo(newEmp, 0);
	}
	return newEmp;
}

Employee* employee_newParamStr(char *idStr, char *nombreStr,
		char *horasTrabajadasStr, char *sueldoStr) {
	Employee *newEmp = NULL;

	if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL
			&& sueldoStr != NULL) {
		newEmp = employee_new();
		if (newEmp != NULL) {
			if (employee_setHorasTrabajadas(newEmp, atoi(horasTrabajadasStr))
					== 1 || employee_setId(newEmp, atoi(idStr)) == 1
					|| employee_setNombre(newEmp, nombreStr) == 1
					|| employee_setSueldo(newEmp, atoi(sueldoStr)) == 1) {
				printf("Fallo algun setter\n");
				free(newEmp);
				newEmp = NULL;
			}
		}
	}
	return newEmp;
}

void employee_delete(Employee *employee) {
	free(employee);
	employee = NULL;
}

int employee_setId(Employee *this, int id) {
	int retorno = -1;

	if (this != NULL) {
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int employee_getId(Employee *this, int *id) {
	int retorno = -1;

	if (this != NULL && id != NULL) {
		*id = this->id;
		retorno = 0;
	}

	return retorno;
}

int employee_setNombre(Employee *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_getNombre(Employee *this, char *nombre) {
	int retorno = -1;

	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 0;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas) {
	int retorno = -1;

	if (this != NULL) {
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas) {
	int retorno = -1;

	if (this != NULL && horasTrabajadas != NULL) {
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}

	return retorno;
}

int employee_setSueldo(Employee *this, int sueldo) {
	int retorno = -1;

	if (this != NULL) {
		this->sueldo = sueldo;
		retorno = 0;
	}

	return retorno;
}

int employee_getSueldo(Employee *this, int *sueldo) {
	int retorno = -1;

	if (this != NULL && sueldo != NULL) {
		*sueldo = this->sueldo;
		retorno = 0;
	}

	return retorno;
}

int mayorId(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	if (pArrayListEmployee != NULL) {
		int len;
		int flag = 0;
		int i;
		Employee *auxEmployee;

		len = ll_len(pArrayListEmployee);

		for (i = 0; i < len; i++) {
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if (flag == 0 || retorno < auxEmployee->id) {
				retorno = auxEmployee->id;
				flag = -1;
			}
		}
	}
	return retorno;
}

int proximoId(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	if (pArrayListEmployee != NULL) {
		retorno = mayorId(pArrayListEmployee);
		retorno++;
	}
	return retorno;
}

int showOneEmployee(Employee *employee) {
	int retorno = -1;

	if (employee != NULL) {
		printf("%4d %18s %20d %20d\n", employee->id, employee->nombre,
				employee->horasTrabajadas, employee->sueldo);
		retorno = 0;
	}

	return retorno;
}

void pedirDatosEmp(char *nombre, char *horasTrabajadas, char *salario) {
	pedirCadena("Ingrese el nombre del empleado: ", nombre);
	pedirSoloNumeros("Ingrese las horas trabajadas del empleado: ",horasTrabajadas);
	pedirSoloNumeros("Ingrese el salario del empleado: ", salario);
}

void* getEmployeeById(LinkedList *pArrayListEmployee, int id) {
	int len;
	int i;
	Employee *auxEmployee = NULL;
	if (pArrayListEmployee != NULL) {
		len = ll_len(pArrayListEmployee);

		for (i = 0; i < len; i++) {
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if (id == auxEmployee->id) {
				return auxEmployee;
				break;
			}
		}
	}
	return auxEmployee;
}

int compareByHoursWorked(void *pElement1, void *pElement2) {
	int retorno = -1;
	int horasTrabajadas_Uno;
	int horasTrabajadas_Dos;

	Employee *empleado_Uno = (Employee*) pElement1;
	Employee *empleado_Dos = (Employee*) pElement2;

	employee_getHorasTrabajadas(empleado_Uno, &horasTrabajadas_Uno);
	employee_getHorasTrabajadas(empleado_Dos, &horasTrabajadas_Dos);

	if (horasTrabajadas_Uno > horasTrabajadas_Dos) {
		retorno = 1;
	} else {
		if (horasTrabajadas_Uno == horasTrabajadas_Dos) {
			retorno = 0;
		}
	}

	return retorno;
}
int compareByName(void *pElement1, void *pElement2) {
	int retorno;
	char nombre_Uno[50];
	char nombre_Dos[50];

	//Employee *empleado_Uno = (Employee*) pElement1;
	//Employee *empleado_Dos = (Employee*) pElement2;

	employee_getNombre((Employee*)pElement1, nombre_Uno);
	employee_getNombre((Employee*)pElement2, nombre_Dos);


	retorno = strcmp(nombre_Uno, nombre_Dos);

	return retorno;
}
int compareBySalary(void *pElement1, void *pElement2) {
	int retorno = -1;
	int sueldo_Uno;
	int sueldo_Dos;

	Employee *empleado_Uno = (Employee*) pElement1;
	Employee *empleado_Dos = (Employee*) pElement2;

	employee_getSueldo(empleado_Uno, &sueldo_Uno);
	employee_getSueldo(empleado_Dos, &sueldo_Dos);

	if (sueldo_Uno > sueldo_Dos) {
		retorno = 1;
	} else {
		if (sueldo_Uno == sueldo_Dos) {
			retorno = 0;
		}
	}

	return retorno;
}

int compareById(void *pElement1, void *pElement2) {
	int retorno = -1;
	int id_Uno;
	int id_Dos;

	Employee *empleado_Uno = (Employee*) pElement1;
	Employee *empleado_Dos = (Employee*) pElement2;

	employee_getId(empleado_Uno, &id_Uno);
	employee_getId(empleado_Dos, &id_Dos);

	if (id_Uno > id_Dos) {
		retorno = 1;
	} else {
		if (id_Uno == id_Dos) {
			retorno = 0;
		}
	}

	return retorno;
}


