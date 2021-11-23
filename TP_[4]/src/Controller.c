#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "matias.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee) {
	FILE *auxF;
	int retorno = 1;
	auxF = fopen(path, "r");
	if (auxF == NULL) {
		printf("Error al abrir el archivo");

	} else {
		parser_EmployeeFromText(auxF, pArrayListEmployee);
		retorno = 0;
	}
	fclose(auxF);
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee) {
	int retorno = 1;

	FILE *pFile = NULL;

	pFile = fopen(path, "rb");

	if (pFile != NULL && pArrayListEmployee != NULL) {
		retorno = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
	} else {
		retorno = 2;
	}

	fclose(pFile);
	return retorno;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee, int *id) {
	int retorno = 1;
	char nombre[60];
	char sueldo[60];
	char horasTrabajadas[60];
	char idEmp[60];
	int poxId;
	char check;
	char continuar;

	if (pArrayListEmployee != NULL) {
		do {
			Employee *newEmp;

			sprintf(idEmp, "%d", *id);
			pedirDatosEmp(nombre, horasTrabajadas, sueldo);
			newEmp = employee_newParamStr(idEmp, nombre, horasTrabajadas,
					sueldo);

			printf("Los datos ingresados son:\n");
			printf("%5s %15s %22s %22s\n", "ID:", "Nombre:",
					"Horas trabajadas:", "Sueldo:");
			showOneEmployee(newEmp);

			check = getConfirmacion("\nDesea cargar al empleado? S/N: ");
			if (check == 's') {
				retorno = ll_add(pArrayListEmployee, newEmp);
			} else if (check == 'n') {
				retorno = 2;
			}

			poxId = *id;
			poxId++;
			*id = poxId;

			continuar = getConfirmacion(
					"\nDesea ingresar otro empleado? S/N: ");

		} while (continuar == 's');
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \return int Devuelve -1 si la lista es nula, 0 si se cargo al empleado modificado ,1 si el id del empleado no existe, 2 si el usuario cancelo la operacion
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;

	Employee *empAux;
	Employee *empAMod;
	char confirmacion1 = 's';
	char confirmacion2 = 'n';
	int id;

	if (pArrayListEmployee != NULL) {
		printf("Lista de empleados\n");
		controller_ListEmployee(pArrayListEmployee);
		id = getInt("Ingrese el id del empleado que quiera modificar: \n");

		empAMod = getEmployeeById(pArrayListEmployee, id);

		empAux = empAMod;
		if (empAux != NULL) {
			printf("\nEste es el empleado a modificar: \n");
			printf("%4s %18s %20s %20s\n", "ID:", "Nombre:",
					"Horas trabajadas:", "Salario:");
			showOneEmployee(empAux);
			system("pause");
			do {

				switch (menuMod()) {
				case 1:
					pedirCadena("Ingrese un nuevo nombre: ", empAux->nombre);
					confirmacion1 =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
					system("pause");
					break;
				case 2:
					empAux->horasTrabajadas = getInt(
							"Ingrese una nueva cantidad de horas trabajadas: ");
					confirmacion1 =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
					system("pause");
					break;
				case 3:
					empAux->sueldo = getInt("Ingrese el nuevo salario: ");
					confirmacion1 =
							getConfirmacion(
									"\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
					system("pause");
					break;
				case 4:
					confirmacion1 = 'n';

					system("pause");
					break;
				default:
					printf("Ingreso una opcion incorrecta.\n");

					system("pause");
					break;
				}
			} while (confirmacion1 == 's');
		} else {
			retorno = 1;
		}

		printf("\nEste es el empleado con los cambios realizados:\n");
		printf("\n%4s %18s %20s %20s\n", "ID:", "Nombre:", "Horas trabajadas:",
				"Salario:");
		showOneEmployee(empAux);
		confirmacion2 = getConfirmacion(
				"\nDesea cargar los datos? Ingrese s para SI o n para NO:");
		if (confirmacion2 == 's') {
			empAMod = empAux;
			retorno = 0;
		} else {
			retorno = 2;
		}
	}

	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList *pArrayListEmployee) {
	int retorno = 1;
	int id;
	Employee *auxEmp;
	int indice;
	char check;

	if (pArrayListEmployee != NULL) {
		printf("Estos son los empleados:\n");
		controller_ListEmployee(pArrayListEmployee);
		id = getInt("\nIngrese el id del empleado que desea dar de baja: ");
		printf("\n");

		auxEmp = getEmployeeById(pArrayListEmployee, id);

		if (auxEmp != NULL) {
			printf("%4s %18s %20s %20s\n", "ID:", "Nombre:",
					"Horas trabajadas:", "Salario:");
			showOneEmployee(auxEmp);
			check =
					getConfirmacion(
							"\nEsta seguro que quiere eliminar al empleado? Ingrese s para SI o n para NO:");
			if (check == 's') {
				indice = ll_indexOf(pArrayListEmployee, auxEmp);
				retorno = ll_remove(pArrayListEmployee, indice);
			} else if (check == 'n') {
				retorno = 2;
			}
		} else {
			retorno = 3;
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee) {
	int retorno = -1;
	int i;
	int len;

	if (pArrayListEmployee != NULL) {
		retorno = 0;

		len = ll_len(pArrayListEmployee);
		Employee *auxEmp;
		printf("%4s%22s%32s%32s\n", "Id", "Nombre", "Horas Trabajadas",
				"Sueldo");
		for (i = 0; i < len; i++) {
			auxEmp = (Employee*) ll_get(pArrayListEmployee, i);
			showOneEmployee(auxEmp);
			if (i != 0 && i % 200 == 0) {
				system("pause");
			}
		}
	} else {
		retorno = 1;
	}

	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
	{
		int retorno = 1;

		char option_continue = 'n';
		int orden;
		int isEmpty = 0;

		if (pArrayListEmployee != NULL) {
			isEmpty = ll_isEmpty(pArrayListEmployee);
			retorno = 2;
			if (isEmpty != 1) {
				do {
					system("cls");

					switch (menuOrden()) {
					case 1:
						orden =
								getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ",	1, 0);
						retorno = ll_sort(pArrayListEmployee, compareById,orden);
						option_continue = 's';
						printf("\n");
						system("pause");
						break;
					case 2:
						orden =	getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ",1, 0);
						retorno = ll_sort(pArrayListEmployee, compareByName,
								orden);
						option_continue = 's';
						printf("\n");
						system("pause");
						break;
					case 3:
						orden =
								getDosEstados(
										"Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ",
										1, 0);
						retorno = ll_sort(pArrayListEmployee,
								compareByHoursWorked, orden);
						option_continue = 's';
						printf("\n");
						system("pause");
						break;
					case 4:
						orden =
								getDosEstados(
										"Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ",
										1, 0);
						retorno = ll_sort(pArrayListEmployee, compareBySalary,orden);
						option_continue = 's';
						printf("\n");
						system("pause");
						break;
					case 5:
						option_continue =
								getConfirmacion(
										"Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
						retorno = 3;
						break;
					default:
						printf("Ha ingresado una opcion incorrecta.\n");
						printf("\n");
						system("pause");
						break;
					}
				} while (option_continue == 'n');
			}
		}
		return retorno;
	}

	/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
	 *
	 * \param path char*
	 * \param pArrayListEmployee LinkedList*
	 * \return int
	 *
	 */
	int controller_saveAsText(char *path, LinkedList *pArrayListEmployee) {
		int retorno = -1;
		   int len;
		 FILE* pFile;
		    Employee* auxEmployee = NULL;

		    int idStr;
		    char nombreStr[51];
		    int horasTrabajadasStr;
		    int sueldoStr;

		    if(pArrayListEmployee != NULL && path != NULL)
		    {
		        pFile = fopen(path, "w");
		        len = ll_len(pArrayListEmployee);

		        if(pFile != NULL)
		        {
		            fprintf(pFile, "Id,Nombre,Horas trabajadas,Salario\n");
		            for(int i=0; i<len; i++)
		            {
		                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		                employee_getId(auxEmployee, &idStr);
		                employee_getNombre(auxEmployee, nombreStr);
		                employee_getHorasTrabajadas(auxEmployee, &horasTrabajadasStr);
		                employee_getSueldo(auxEmployee, &sueldoStr);

		                fprintf(pFile, "%d,%s,%d,%d\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
		            }
		        }
		        fclose(pFile);
		        retorno = 0;
		    }
		    return retorno;
	}

	/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
	 *
	 * \param path char*
	 * \param pArrayListEmployee LinkedList*
	 * \return int
	 *
	 */
	int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee) {
		int retorno = -1;
		    int len;
		    int i;
		    FILE* pFile;
		    Employee* auxEmployee = NULL;

		    if(pArrayListEmployee != NULL && path != NULL)
		    {
		        pFile = fopen(path, "wb");
		        len = ll_len(pArrayListEmployee);

		        if(pFile != NULL)
		        {
		            for(i=0; i<len; i++)
		            {
		                auxEmployee = (Employee*) ll_get(pArrayListEmployee, i);
		                fwrite(auxEmployee, sizeof(Employee), 1, pFile);
		            }
		        }
		        fclose(pFile);
		        retorno = 0;
		    }

		    return retorno;
	}

