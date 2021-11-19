#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = 1;
	char buffer[4][20];
	int cant;

	Employee *nEmp;

	if (pFile != NULL && pArrayListEmployee != NULL) {
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1],buffer[2], buffer[3]);

		while (!feof(pFile)) {
			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1], buffer[2], buffer[3]);
			if (cant < 4) {
				break;
			}
			nEmp = employee_newParamStr(buffer[0], buffer[1], buffer[2],buffer[3]);
			ll_add(pArrayListEmployee, nEmp);
			retorno = 0;
		}

	} else {
		printf("Error al abrir el archivo");
		system("pause");
	}

	return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee) {
	int retorno = -1;
	Employee *this = NULL;
	int contador =0;

	if (pArrayListEmployee != NULL && pFile != NULL) {
		while (!feof(pFile)) {
			this =employee_new();
			if (this != NULL) {
				fread(this, sizeof(Employee), 1, pFile);
				if (feof(pFile)) {
					retorno = -1;
					break;
				}
				ll_add(pArrayListEmployee, this);
				contador++;
			}
		}
		fclose(pFile);
		printf("se cargaron : %d\n", contador);
		pFile = NULL;
		retorno = 0;
	}
	return retorno;
}
