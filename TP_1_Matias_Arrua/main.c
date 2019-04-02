#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1,num2;

    while(seguir=='s')
    {
        printf("-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!) y (B!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n-*-*-*-*-*-*-.......-*-*-*-*-*-*-\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            printf("\nIntroduce primer operando: ");
            scanf("%f", &num1);
                break;
        case 2:
            printf("\nIntroduce segundo operando: ");
            scanf("%f", &num2);
                break;
        case 3:
            printf("La suma de %.2f y %.2f es: %.2f\n\n",num1,num2, suma(num1,num2));
                break;
        case 4:
            printf("La resta de %.2f y %.2f es: %.2f\n\n",num1,num2, resta(num1,num2));
                break;
        case 5:
                if(num2==0){
                    printf("Error. No se puede dividir por cero\n\n");
                }
                else{
                    printf("La division entre %.2f y %.2f es: %.2f\n\n",num1,num2, dividir(num1,num2));
                }
                break;
        case 6:
            printf("La multiplicacion de %.2f y %.2f es: %.2f\n\n",num1,num2, multiplicar(num1,num2));
                break;
        case 7:
                if(num1<=0||num2<=0)
                {
                    printf("Error. No se puede sacar el factorial de un numero negativo o cero\n");
                }
                else{
                    printf("El factorial de %.2f es: %.2f\n\n", num1, factorial(num1));
                    printf("El factorial de %.2f es: %.2f\n\n", num2, factorial(num2));
                    }

                break;
        case 8:
            printf("La suma de %.2f y %.2f es: %.2f\n\n", num1,num2, suma(num1,num2));
            printf("La resta de %.2f y %.2f es: %.2f\n\n", num1,num2, resta(num1,num2));
            printf("La multiplicacion de %.2f y %.2f es: %.2f\n\n",num1,num2, multiplicar(num1,num2));

            if(num2==0){
                    printf("Error. No se puede dividir por cero\n\n");
                }
                else{
                    printf("La division entre %.2f y %.2f es: %.2f\n\n",num1,num2, dividir(num1,num2));
                }

            if(num1<=0){
                    printf("Error. No se puede sacar el factorial de un numero negativo o cero\n\n");
                }
                else{
                    printf("El factorial de %.2f es: %.2f\n\n", num1, factorial(num1));
                    printf("El factorial de %.2f es: %.2f\n\n", num2, factorial(num2));
                }
                break;
        case 9:
                seguir = 'n';
                break;
        }
    }
}
